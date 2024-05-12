
unsigned char helpr___get_allowed_char (unsigned char);


void helpr___get_fat_name (unsigned char* to, unsigned char* from)
{
	int							to_pos;
	int							from_pos;
	int							name_len = -1;
	unsigned char				ch;



	/* get filename without path */
	for (from_pos = 0; *(from + from_pos) != 0; from_pos++) 
		if ( *(from + from_pos) == '/' && *(from + from_pos + 1) != 0 )		  { from += from_pos + 1;
																	from_pos = 0;			}



	/* fill all name by space characters */
	for (from_pos = 0; from_pos < 11; from_pos++)
		*(to + from_pos) = ' ';


	/* get extension of file */
	for (from_pos = 0, to_pos = 8; *(from + from_pos ) != 0; from_pos++)
		if ( *(from + from_pos) == '.' ) 								  { name_len = from_pos++;
																	break;			}
	for (int count = 0; *(from + from_pos) != 0 && count < 3; from_pos++) {
		ch = helpr___get_allowed_char(*(from + from_pos));
		if ( ch ) 		*(to + to_pos + count++) = ch;
	}
	if ( name_len == -1 )											name_len = from_pos;



	/* get first 5 characters of name */
	for (from_pos = 0, to_pos = 0; to_pos < 5 && from_pos < name_len; from_pos++) {
		ch = helpr___get_allowed_char(*(from + from_pos));
		if ( ch )		*(to + to_pos++) = ch;
	}
	/* get last 3 characters of name */
	if ( from_pos > name_len )												from_pos = name_len;
	for (to_pos = 5; to_pos < 8 && from_pos < name_len; from_pos++) {
		ch = helpr___get_allowed_char(*(from + from_pos));
		if ( ch )		*(to + to_pos++) = ch;
	}
}




unsigned char helpr___get_allowed_char (unsigned char ch)
{
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
		case '~' :																return ch;
		default	 :	if ( ch >= '0' && ch <= '9' )								return ch;
					ch &= 0x5f;
					if ( ch >= 'A' && ch <= 'Z' )								return ch;
					else														return 0;
	}
}
