# Little FAT12 editor


Editor for file image of FAT12. I hope, it will grow to be able to work with other FAT systems and more.

I made it as an alternative to mount-way image editing: I needed to load and replace files to image by lot of times an hours, and using 'mount' command, 'cp', 'ls' and 'unmount' every time feels realy undue. As the same time, becouse my work was closely related with filesystems, I wanted to make an almost fully editor for image file based on simple file read-write interface, without mountings. 

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
