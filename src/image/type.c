#include "../type.c"

/********************************************************************/
/*		Boot sector's data:									  		*/
/*			- Original Equipment Manufacturer 	[oem_t]	;	  		*/
/*			- Bios Parameter block 				[bpb]	;	  		*/
/*			- Volumes' info 					[bs]	;	  		*/
/********************************************************************/
typedef unsigned char			oem_t[8];
struct bpb {
	word						bps;		/* Bytes Per Sector 	*/
	byte						spc;		/* Sectors Per Cluster 	*/
	word						rs;			/* Reserved Sectors 	*/
	byte						nf;			/* Number Of FATs 		*/
	word						re;			/* Root Entries 		*/
	word						ts;			/* Total Sectors		*/
	byte						md;			/* Media				*/
	word						spf;		/* Sectors Per FAT		*/
	word						spt;		/* Sectors Per Track	*/
	word						hpc;		/* Head Per Cylinder	*/
	dword						hs;			/* Hidden Sectors		*/
	dword						tsb;		/* Total Sectors bigger	*/
};
struct bs {
	byte						dn;			/* Drive Number			*/
	byte						uu;			/* unused				*/
	byte						ebs;		/* Boot Signature		*/
	dword						sn;			/* Serial Number		*/
	byte						vl[11];		/* Volume Label			*/
	byte						fs[8];		/* FileSystem			*/
};

/********************************************************************/
/*		Image info:											  		*/
/*			- all Boot sector's data in one struct.			  		*/
/********************************************************************/
struct image_info {
	byte						empty[3]; 	/* jump instruction 	*/

	oem_t						oem;
	struct bpb					bpb;
	struct bs					bs;
};
