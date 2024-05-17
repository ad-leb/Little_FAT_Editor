# Little FAT12 editor


Editor for file image of FAT12. I hope, it will grow to be able to work with other FAT systems and more.

I made it as an alternative to mount-way image editing: I needed to load and replace files to image lot of times an hour, and using 'mount' command, 'cp', 'ls' and 'unmount' every time feels realy undue. As the same time, because my work was closely related with filesystems, I wanted to make an almost fully editor for image file based on simple file read-write interface, without mountings. 

## Portings

I start to make this program for myself, so I had a lot to practise with assembly language here.. So, a lot of code is accessable only by -x86\_64-linux-gnu. So, yeah -- now it's only for AMD64 GNU-Linux. And this non porting asseblying code in a heart of *FAT12* module (almost all) and in a *helpr* module, that needed everywhere in other modules (it's not only). Also, C code in most cases refer to UNIX (Linux) API (*sbrk*, *write*, *read* and etc.).

## General interface

The calling of program have a hard structure:
```
lfe  <procedure>  <image-file>  <parameter>  <target / file>  ...
```
There is can be only one image-file to edit, only one target (if it used), but unlimited number of parameters and files. 
> [!IMPORTANT]
> There is no good error handling yet, and in case of error there is will be code of error returned. If you use a bash, you can get this code by command *echo $?*, and check it in file in *defs.h* file, that should locate in a *\_body/\_head* directory.

Supporting procedures:
- born;
- push;
- pull;
- list;




## **list** procedure
```
lfe list <image-file> <parameter> <target>
```
Now it can work with 2 targets:
- title
- content

```
lfe list floppy.img title
```
Target **title** will print for you information about image, which it takes from a *boot sector* of file. All number values will has a *heximal* format. To convert them to *decimal* format, use **-d** parameter:
```
lfe list floppy.img -d title
```
To see numeric content of FAT's Root, use target **content**:
```
lfe list floppy.img content
```
The printed files will has a names, that they will got after **pull** procedure in your mounted filesystem. 



## **push** procedure
> [!WARNING]
> This program don't check for size of writing files or possible to write data yet. (little lazy, yeah). Don't use it for big data, that can be bigger, that image can take!
```
lfe push <image-file> <parameter> <file>
```
**push** procedure is for writing a file from a mounted filesystem to image (for example, named "floppy.img"). Becouse FAT12 internal name is limited by 11 characters, editor trying to rebuild name of choosen file to FAT acceptable by taking first 5 bytes of *real* file name and last 3 bytes of *real* file name if it have to be longer then 8 bytes + 3 bytes of file extension. 
> [!WARNING]
> Be realy accurate with naming a files to puting in image: if files has the same internal FAT names, program will consider them as one file, so files will rewrite each other.

If parameter **-c** will be detected, **push** procedure will clear FAT and Root tables before writing new files:
```
lfe push floppy.img -c hello.txt world.doc
```
Also it can erase an image without any writings:
```
lfe push floppy.img -c 
```
By the way, **push** work with directories. For example, this command:
```
lfe push floppy.img obj/
```
..will say to lfe **recursively** move files into image. Because FAT12 not support directories, lfe only use them for found file in there, but not write. *(You will found a bug here).*



## **pull** procedure
```
lfe pull <image-file> <parameter> <file>
```
Reverse to **push**: it clone a choosen from image content file in mounted filesystem. There's can use an index from a list files (received from **list** procedure):
```
lfe pull floppy.img 12
```
Or you can just ask to pull all files from image:
```
lfe pull floppy.img all
```
All choosen files restore to new dir, named as "from\_*name-of-imagefile*".



## **born** procedure
```
lfe born <image-file> <parameter> <fields>
```
This procedure create an image with choosen parameter, as count of sectors (size of file), filesystem, etc.

There is can be changing *any* field of BIOS Parameter Block, so image will be created as you set it. By default there is creating 2880 sectors (512 bytes) of FAT12 for floppy disk (field 'media' -- *md*; it has no use today, of course), where cluster equal of sector.

Little example:
```
lfe born my_lovely.img oem=MADE\ IN spc=8
```
this command will create a default image with using 4KiB-cluster (*scp=8*) FAT12-filesystem on it and misterious mark for alians, who still use FAT12 today. You can check it by **list** procedure.

Here a list of field-parameters for configuration:
- **sectors=**    *integer* | count of sectors
- **oem=**        *string*  | OEM Label
- **bps=**        *integer* | Bytes Per Sector
- **spc=**        *integer* | Sectors Per Cluster
- **rs=**         *integer* | Reserved Sectors
- **nf=**         *integer* | Number of FATs
- **ts=**         *integer* | Total Sector (count)
- **md=**         *integer* | Media
- **spt=**        *integer* | Sectors Per Track
- **hpc=**        *integer* | Heads Per Cylinder
- **hs=**         *integer* | Hidden Sectors
- **tsb=**        *integer* | Total Sector (count) Big
- **dn=**         *integer* | Drive Number
- **uu=**         *integer* | Unused (if needed, why not)
- **ebs=**        *integer* | Extension Boot Signature
- **sn=**         *integer* | Serial Number
- **vl=**         *string*  | Volume label
- **oem=**        *string*  | Filesystem label





# How to **make**
Make file is really big for this little project, so I put here some instructions for comfort using:



## Just make
To get a finished program, open directory of this file in your command shell and print commnad 'make':
```
make
```
After build, finished program will locate in *bin* directory. For install it to *$(PREFIX)/bin* dir (by default it's a */usr/local/bin*), use this:
```
make install
```




## Stucture
Makefile operates with **raw files** (the object files of each text file from *SRCDIR*) and **modules** (the collection of raw files, based on their functions and using data). Directory ierarchy is no matter for 'make', and can be using only for human readability: Makefile has been wrotten to erase it, so for 'make' all text files locate in one directory. 

There are few modules:
- **\_boot** | assebly code, that build a file list, check for pararmeters, choose procedure, load tables, save names of image and program and provide primal error check;
- **\_body** | base of program;
- **inter** | base interface of program functionality, but honnestly -- just big text code, makin A LOT and important;
- **image** | provide base operations on image at all, like load tables, writing data and etc.;
- **fat12** | provide base operations on FA12 table;
- **rootf** | provide base operations on Root table;
- **helpr** | *helper* is just a barn of helpful procedures, like a string or memory allocations procedures.

Needed (relating) **raw files** found by their names: first part of them is signify their module (except **\_body**). This marks are really handy when looking for symbols, that you forgot. 

All sourc files locate in **src**, and for all object file and binary files Make will create a **obj** and **bin** directories -- all other file structure is just for help to guys. 



## PHONYs

I found this *make* target usefull:
- **clean**     -- little bash script for cleaning base dir;
- **down**      -- remove all objects and bin files;
- **zen**       -- **clean** + **down**;
- **t___**      -- fast test procedure;
- **d___**      -- fast debug procedure;


#### test 
```
make tpush
    /*    ./bin/debug push floppy.img -c obj/  */
    /* You will found by this test, that lfe is little buggy for naming files                           */
    /* It either 'coz FAT's internal name limit in 12 bytes. This bug can be cool toy for some hours :) */
make tpull
    /*    ./bin/debug pull floppy.img all  */
make tborn
    /*    ./bin/debug born keks -d  */
    /* keks -- dump word                                                                                */
    /* '-d' is just for count of args -- I miscalculate with it..                                       */
make tlist
    /*    ./bin/debug list floppy.img content  */
make tlistt
    /*    ./bin/debug list floppy.img title  */
```
#### gdb
```
make dpush
    /*    gdb --args ./bin/debug push floppy.img -c obj/ */
make dpull
    /*    gdb --args ./bin/debug pull floppy.img all */
make dborn
    /*    gdb --args ./bin/debug born keks -d */
make dlist
    /*    gdb --args ./bin/debug list floppy.img content */
make dlistt
    /*    gdb --args ./bin/debug list floppy.img title */
```





### I think, it's all

