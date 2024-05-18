#include <type.c>
#include <defs.h>


extern struct image_info		data___image_info;
extern unsigned char			data___dump_jmp;
extern unsigned char			data___dump_msg;


int helpr___atoi (void*);
int helpr___strcmp (unsigned char*, unsigned char*, int);
void helpr___strncpy (unsigned char*, unsigned char*, int);
void helpr___memreset (void*, int);
void helpr___error (int);
void* helpr___lalloc (int);
void helpr___write_dump_bootsector ();

void image___write (void*, int, int);
void image___prepare_fat ();


int born (unsigned char* params[])
{
	unsigned char*				default_oem = "LFE  IMG";
	unsigned char*				default_vl = "NEW VOLUME";
	unsigned char*				default_fs = "FAT12   ";


	unsigned char*				pattern_oem = "oem=";
	unsigned char*				pattern_vl = "vl=";
	unsigned char*				pattern_fs = "fs=";

	unsigned char*				pattern_sectors = "sectors=";

	unsigned char*				pattern_bps = "bps=";
	unsigned char*				pattern_spc = "spc=";
	unsigned char*				pattern_rs = "rs=";
	unsigned char*				pattern_nf = "nf=";
	unsigned char*				pattern_re = "re=";
	unsigned char*				pattern_ts = "ts=";
	unsigned char*				pattern_md = "md=";
	unsigned char*				pattern_spt = "spt=";
	unsigned char*				pattern_hpc = "hpc=";
	unsigned char*				pattern_hs = "hs=";
	unsigned char*				pattern_tsb= "tsb=";
	unsigned char*				pattern_dn = "dn=";
	unsigned char*				pattern_uu = "uu=";
	unsigned char*				pattern_ebs = "ebs=";
	unsigned char*				pattern_sn = "sn=";


	int							sectors = 0x0b40;
	unsigned char*				dump;
	int							mark = 0xAA55; 					/* I hope, I remove it somewhen */




	/* setting default fields */
	data___image_info.bpb.bps 	= 0x0200;
	data___image_info.bpb.spc 	= 0x01;
	data___image_info.bpb.rs	= 0x0001;
	data___image_info.bpb.nf	= 0x02;
	data___image_info.bpb.re	= 0xe0;
	data___image_info.bpb.ts	= sectors;
	data___image_info.bpb.md 	= 0xf8;
	data___image_info.bpb.spt	= 0x0012;
	data___image_info.bpb.hpc	= 0x0002;
	data___image_info.bpb.hs	= 0x00000000;
	data___image_info.bpb.tsb	= 0x00000000;
	data___image_info.bs.dn 	= 0x00;
	data___image_info.bs.uu		= 0x00;
	data___image_info.bs.ebs 	= 0x29;
	data___image_info.bs.sn 	= 0x0000017e;


	/* read user params */
	for (int i = 0; params[i] != NULL; i++) {
		if ( helpr___strcmp(params[i], pattern_sectors, 8) == 0 )	  { data___image_info.bpb.ts = 0;
																		sectors = helpr___atoi(params[i] + 8);
																		if ( sectors > 65535 ) 	data___image_info.bpb.tsb = (dword) sectors;
																		else					data___image_info.bpb.ts = (word) sectors;	continue; }


		if ( helpr___strcmp(params[i], pattern_oem, 4) == 0 )		  { helpr___strncpy(data___image_info.oem, params[i] + 4, 8); 			continue; }
		if ( helpr___strcmp(params[i], pattern_vl, 3) == 0 )		  { helpr___strncpy(data___image_info.bs.vl, params[i] + 3, 11);		continue; }
		if ( helpr___strcmp(params[i], pattern_fs, 3) == 0 )		  { helpr___strncpy(data___image_info.bs.fs, params[i] + 3, 8);			continue; }


		if ( helpr___strcmp(params[i], pattern_bps, 4) == 0 )		  { data___image_info.bpb.bps = (word) helpr___atoi(params[i] + 4);		continue; }
		if ( helpr___strcmp(params[i], pattern_spc, 4) == 0 )		  { data___image_info.bpb.spc = (byte) helpr___atoi(params[i] + 4);		continue; }
		if ( helpr___strcmp(params[i], pattern_rs, 3) == 0 )		  { data___image_info.bpb.rs = (word) helpr___atoi(params[i] + 3);		continue; }
		if ( helpr___strcmp(params[i], pattern_nf, 3) == 0 )		  { data___image_info.bpb.nf = (word) helpr___atoi(params[i] + 3);		continue; }
		if ( helpr___strcmp(params[i], pattern_re, 3) == 0 )		  { data___image_info.bpb.re = (word) helpr___atoi(params[i] + 3);		continue; }
		if ( helpr___strcmp(params[i], pattern_ts, 3) == 0 )		  { data___image_info.bpb.ts = (word) helpr___atoi(params[i] + 3);		continue; }
		if ( helpr___strcmp(params[i], pattern_md, 3) == 0 )		  { data___image_info.bpb.md = (byte) helpr___atoi(params[i] + 3);		continue; }
		if ( helpr___strcmp(params[i], pattern_spt, 4) == 0 )		  { data___image_info.bpb.spt = (word) helpr___atoi(params[i] + 4);		continue; }
		if ( helpr___strcmp(params[i], pattern_hpc, 4) == 0 )		  { data___image_info.bpb.hpc = (word) helpr___atoi(params[i] + 4);		continue; }
		if ( helpr___strcmp(params[i], pattern_hs, 3) == 0 )		  { data___image_info.bpb.hs = (dword) helpr___atoi(params[i] + 3);		continue; }
		if ( helpr___strcmp(params[i], pattern_tsb, 4) == 0 )		  { data___image_info.bpb.tsb = (dword) helpr___atoi(params[i] + 4);	continue; }

		if ( helpr___strcmp(params[i], pattern_uu, 3) == 0 )		  { data___image_info.bs.uu = (byte) helpr___atoi(params[i] + 3);		continue; }
		if ( helpr___strcmp(params[i], pattern_dn, 3) == 0 )		  { data___image_info.bs.dn = (byte) helpr___atoi(params[i] + 3);		continue; }
		if ( helpr___strcmp(params[i], pattern_ebs, 4) == 0 )		  { data___image_info.bs.ebs = (byte) helpr___atoi(params[i] + 4);		continue; }
		if ( helpr___strcmp(pattern_sn, params[i], 3) == 0 )		  { data___image_info.bs.sn = (dword) helpr___atoi(params[i] + 3);		continue; }

		else														  { helpr___error(ERR_UNKN);													  }
	}


	/* setting an empty string fields */
	if ( data___image_info.oem[0] == 0 )		helpr___strncpy(data___image_info.oem, default_oem, 8);
	if ( data___image_info.bs.vl[0] == 0 )		helpr___strncpy(data___image_info.bs.vl, default_vl, 11);
	if ( data___image_info.bs.fs[0] == 0 )		helpr___strncpy(data___image_info.bs.fs, default_fs, 8);


	/* setting 'SectorsPerFAT' */
	data___image_info.bpb.spf = (word) ( (data___image_info.bpb.ts * (1.5)) / (data___image_info.bpb.spc * data___image_info.bpb.bps) + 1 );


	/* inflate file in size */
	dump = helpr___lalloc(data___image_info.bpb.bps);
		if ( dump == NULL )														helpr___error(ERR_LALL);
	helpr___memreset(dump, data___image_info.bpb.bps);
	for (int i = 0; i < sectors; i++)
		image___write(dump, i * data___image_info.bpb.bps, data___image_info.bpb.bps);
	


	/* format boot sector */
	image___write(&data___image_info, 0, sizeof(data___image_info));
	image___write(&data___dump_jmp, 0, 3);
	image___write(&data___dump_msg, 0x3e, 0x1d3);


	/* tell image module to prepare fat table -- it just adding 3 bytes in begin of tables */
	image___prepare_fat();



	return 1;
}
