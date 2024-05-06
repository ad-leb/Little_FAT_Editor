#include "header.h"


void helpr___memreset (unsigned char*, int);
void helpr___itod (unsigned char*, int);
void helpr___itoh (unsigned char*, int);
int helpr___strcat (unsigned char*, unsigned char*, int);

int write (int, unsigned char*, int);


void print___image_info ()
{
	unsigned char				line[1024];
	unsigned char				num_buffer[32];
	int							len;


	helpr___memreset(line, 1024);
	len = helpr___strcat(line, str_oem, 0);
	len = helpr___strcat(line, separator, 0);
	len = helpr___strcat(line, data___image_info.oem, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_bps, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bpb.bps);
	else			 				helpr___itoh(num_buffer, data___bpb.bps);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_spc, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bpb.spc);
	else			 				helpr___itoh(num_buffer, data___bpb.spc);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_rs, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bpb.rs);
	else			 				helpr___itoh(num_buffer, data___bpb.rs);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_nf, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bpb.nf);
	else			 				helpr___itoh(num_buffer, data___bpb.nf);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_re, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bpb.re);
	else			 				helpr___itoh(num_buffer, data___bpb.re);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_ts, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bpb.ts);
	else			 				helpr___itoh(num_buffer, data___bpb.ts);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_md, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bpb.md);
	else			 				helpr___itoh(num_buffer, data___bpb.md);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_spf, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bpb.spf);
	else			 				helpr___itoh(num_buffer, data___bpb.spf);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_spt, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bpb.spt);
	else			 				helpr___itoh(num_buffer, data___bpb.spt);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_hpc, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bpb.hpc);
	else			 				helpr___itoh(num_buffer, data___bpb.hpc);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_hs, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bpb.hs);
	else			 				helpr___itoh(num_buffer, data___bpb.hs);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_tsb, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bpb.tsb);
	else			 				helpr___itoh(num_buffer, data___bpb.tsb);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_dn, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bs.dn);
	else			 				helpr___itoh(num_buffer, data___bs.dn);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_uu, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bs.uu);
	else			 				helpr___itoh(num_buffer, data___bs.uu);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_ebs, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bs.ebs);
	else			 				helpr___itoh(num_buffer, data___bs.ebs);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_sn, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP ) 				helpr___itod(num_buffer, data___bs.sn);
	else			 				helpr___itoh(num_buffer, data___bs.sn);
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	len = helpr___strcat(line, str_vl, 0);
	len = helpr___strcat(line, separator, 0);
	len = helpr___strcat(line, data___image_info.bs.vl, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	len = helpr___strcat(line, str_fs, 0);
	len = helpr___strcat(line, separator, 0);
	len = helpr___strcat(line, data___image_info.bs.fs, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);
}
