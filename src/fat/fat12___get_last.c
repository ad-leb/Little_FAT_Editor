
int fat12___get_next (int);


int fat12___get_last (int cluster)
{
	int							tmp_cluster;


	while ( 1 ) {
		tmp_cluster = fat12___get_next(cluster);
		if ( tmp_cluster < 0xff8 )		cluster = tmp_cluster;
		else							break;
	}


	return cluster;
}
