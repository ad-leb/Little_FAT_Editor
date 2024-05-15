#include <type.c>
#include <defs.h>
#include "string/title.c"


extern struct image_info		data___image_info;
extern int						data___params;


void helpr___memreset (unsigned char*, int);
void helpr___itod (unsigned char*, int);
void helpr___itoh (unsigned char*, int);
void helpr___error (int);
int helpr___strcat (unsigned char*, unsigned char*, int);

int write (int, unsigned char*, int);



void inter___print_title ()
{
	unsigned char				line[1024];
	unsigned char				num_buffer[32];
	int							len;


	helpr___memreset(line, 1024);
	len = helpr___strcat(line, str_oem, 0);
	len = helpr___strcat(line, separator, 0);
	len = helpr___strcat(line, data___image_info.oem, 8);
	len = helpr___strcat(line, terminator, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_bps, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bpb.bps);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bpb.bps);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_spc, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bpb.spc);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bpb.spc);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_rs, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bpb.rs);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bpb.rs);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_nf, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bpb.nf);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bpb.nf);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_re, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bpb.re);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bpb.re);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_ts, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bpb.ts);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bpb.ts);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_md, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bpb.md);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bpb.md);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_spf, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bpb.spf);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bpb.spf);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_spt, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bpb.spt);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bpb.spt);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_hpc, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bpb.hpc);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bpb.hpc);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_hs, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bpb.hs);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bpb.hs);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_tsb, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bpb.tsb);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bpb.tsb);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);


	if ( write(1, "\n", 1) != 1 )												helpr___error(ERR_WRTE);
	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_dn, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bs.dn);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bs.dn);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_uu, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bs.uu);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bs.uu);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_ebs, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bs.ebs);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bs.ebs);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	helpr___memreset(num_buffer, 32);
	len = helpr___strcat(line, str_sn, 0);
	len = helpr___strcat(line, separator, 0);
	if ( PARAM_DECOP > 0 ) 			helpr___itod(num_buffer, data___image_info.bs.sn);
	else			 			  { helpr___itoh(num_buffer, data___image_info.bs.sn);
									len = helpr___strcat(line, "0x", 2);			}
	len = helpr___strcat(line, num_buffer, 0);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	len = helpr___strcat(line, str_vl, 0);
	len = helpr___strcat(line, separator, 0);
	len = helpr___strcat(line, data___image_info.bs.vl, 11);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);

	helpr___memreset(line, 1024);
	len = helpr___strcat(line, str_fs, 0);
	len = helpr___strcat(line, separator, 0);
	len = helpr___strcat(line, data___image_info.bs.fs, 8);
	len = helpr___strcat(line, terminator, 0);
	if ( write(1, line, len) != len ) 											helpr___error(ERR_WRTE);
}
