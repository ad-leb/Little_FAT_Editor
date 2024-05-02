

void helpr___get_fat_name (unsigned char* to, unsigned char* from)
{
	unsigned char				ch = 1;
	int							pos;





    /* 3 symbols of file extension */
    for (int i = 0; ch != 0; i++) {
    	ch = *(from + i);
    	if ( ch == '.') {
    		i++;
    		for (pos = 8; pos < 11; i++) {
    			ch = *(from + i);
    			if ( ch == 0 ) 					break;
    			ch &= 0x5f;
    			if ( ch >= 'A' && ch <= 'Z' ) 	*(to + pos++) = ch;
    		}
    		break;
    	}
    }
    while ( pos < 11 )							*(to + pos++) = ' ';



	/* 8 symbols of file name */
	ch = *(from);
	for (pos = 0; pos < 8 && ch != 0; pos++) {
		if ( ch == '.' )						break;


		switch ( ch ) {
			case ' ' :
			case '!' :
			case '$' :
			case '%' :
			case '&' :
			case '(' :
			case ')' :
			case '-' :
			case '_' :
			case '@' :
			case '`' :
			case '\'':
			case '^' :
			case '{' :
			case '}' :
			case '~' :		*(to + pos) = ch;		break;
			default	 :								break;
		}
		ch &= 0x5f;
		if ( ch >= 'A' && ch <= 'Z' )			*(to + pos) = ch;


		ch = *(from + pos + 1);
	}
	while ( pos < 8 ) 							*(to + pos++) = ' ';
}
