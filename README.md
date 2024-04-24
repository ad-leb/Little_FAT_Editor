# Lil FAT12 writer for disk image

The prog from this repo gonna be able to write, delete and add a files in image with FAT12 filesystem on it. It perspective, it has been able to work with other FAT systems.


Project consist of modules named "image", "rootf", "fat12", "confg", "store" and additional functions, including main interface.

Every module is wrote in Makefile. Files to compile and linking has to be founding with "find" command. It's more easily in real, because every compiling file has a prefix in it's name, which determine it's kind. So programmer don't need to rewrite a Makefile a lot, however, he don't afraid of garbaging a working space. By the way, a directories' structure in SRCDIR is alse help a programmer, not a make-program (which using a "find" and "sed" to determine module's files). 

All intermediate object files (blocks of modules) are store in a RAWDIR. 

Make phony:
    () clear -- little bash script for cleaning root directory of project. I found it a usefull.
    () down  -- removing all objects files.
    () zen   -- 'clean' + 'down' + 'rm -r obj bin' and so. Just return project to his Git appearance. 
