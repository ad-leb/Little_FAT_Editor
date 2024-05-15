#include <type.c>
#include <defs.h>


extern struct image_info		data___image_info;


int helpr___atoi (void*);
int helpr___strcmp (unsigned char*, unsigned char*, int);
void helpr___strncpy (unsigned char*, unsigned char*, int);
void helpr___memreset (void*, int);

void image___write (void*, int, int);



int born (unsigned char* params[])
{
	unsigned char*				pattern_oem = "oem=";
	unsigned char*				pattern_vl = "vl=";
	unsigned char*				pattern_fs = "fs=";

	unsigned char*				pattern_sectors = "sectors=";

	unsigned char*				pattern_bps = "bps=";
	unsigned char*				pattern_spc = "spc=";
	unsigned char*				pattern_rs = "rs=";
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

	unsigned char*				pattern_ = "=";



	/* setting first needed default params */
	data___image_info.bpb.bps 	= 0x0200;
	data___image_info.bpb.spc 	= 0x01;
	data___image_info.bpb.rs	= 0x0001;
	data___image_info.bpb.ts	= 0x0b40;
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

		if ( helpr___strcmp(params[i], pattern_oem, 4) == 0 )		  { helpr___strncpy(data___image_info.oem, params[i] + 4, 8); 			continue; }
		if ( helpr___strcmp(params[i], pattern_vl, 3) == 0 )		  { helpr___strncpy(data___image_info.bs.vl, params[i] + 3, 11);		continue; }
		if ( helpr___strcmp(params[i], pattern_fs, 3) == 0 )		  { helpr___strncpy(data___image_info.bs.fs, params[i] + 3, 8);			continue; }

		if ( helpr___strcmp(params[i], pattern_bps, 4) == 0 )		  { data___image_info.bpb.bps = (word) helpr___atoi(params[i] + 4);		continue; }
		if ( helpr___strcmp(params[i], pattern_spc, 4) == 0 )		  { data___image_info.bpb.spc = (byte) helpr___atoi(params[i] + 4);		continue; }
		if ( helpr___strcmp(params[i], pattern_rs, 3) == 0 )		  { data___image_info.bpb.rs = (word) helpr___atoi(params[i] + 3);		continue; }
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

	}


	image___write(&data___image_info, 0, 512);



	return 1;
}
