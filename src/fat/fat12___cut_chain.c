int fat12___get_next (int);
void fat12___reset (int);


void fat12___cut_chain (int pos)
{
	if ( pos <= 0xff0 )	
		fat12___cut_chain(fat12___get_next(pos));
	fat12___reset(pos);
}
