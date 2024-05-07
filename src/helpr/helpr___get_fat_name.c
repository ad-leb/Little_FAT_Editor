
/* Convert a real long name of file to internal 11-bytes FAT name */


void helpr___get_fat_name (unsigned char* to, unsigned char* from)
{
	unsigned char				ch = 1;
	int							pos;
	int							i;
	int							last = 0;




	for (int i = 0; *(from + i) != 0; i++) {
		if ( (*(from + i) == '/') && (*(from + i + 1) != 0) ) {
			from += i + 1;
			i = 0;
		}
	}



    /* 3 characters of file extension */
    for (i = 0; ch != 0; i++) {
    	ch = *(from + i);
    	if ( ch == '.') {
			if ( i < 8 ) 	last = 5;
			else			last = i - 3;		/* Last part of name -- will be used in name building */
    		i++;
    		for (pos = 8; pos < 11; i++) {
    			ch = *(from + i);
    			if ( ch == 0 ) 						break;
    			ch &= 0x5f;
    			if ( ch >= 'A' && ch <= 'Z' ) 	*(to + pos++) = ch;
    		}
    		break;
    	}
    }
	if ( last == 0 ) 							last = i - 1 - 3;
    while ( pos < 11 )							*(to + pos++) = ' ';



	/* First 5 characters of file name */
	ch = *(from);
	for (pos = 0; pos < 5 && ch != 0; pos++) {
		if ( ch == '.' )							break;

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
		if ( ch >= '0' && ch <= '9' )			*(to + pos) = ch;
		ch &= 0x5f;
		if ( ch >= 'A' && ch <= 'Z' )			*(to + pos) = ch;

		ch = *(from + pos + 1);
	}

	if ( ch == '.' ) {
		while ( pos < 8 ) 						*(to + pos++) = ' ';
	} else {
	/* Last 3 characters of file name */
		ch = *(from + last++);
		for (pos = 5; pos < 8 && ch != 0; pos++) {
			if ( ch == '.' )							break;
		
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
			if ( ch >= '0' && ch <= '9' )			*(to + pos) = ch;
			ch &= 0x5f;
			if ( ch >= 'A' && ch <= 'Z' )			*(to + pos) = ch;
		
			ch = *(from + last++);
		}
	}
	while ( pos < 8 ) 						*(to + pos++) = ' ';
}
