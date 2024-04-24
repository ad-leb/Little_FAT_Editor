/*	config spase	*/
void configure ();
int	conf_get_image ();
int conf_get_file_count ();
int conf_get_next_file ();

/*	image space		*/
void image_prepare (int);
void image_write (int);



int main (int argc, char* argv[])
{
	configure();

	image___prepare(conf_get_image());

	for (int i = 1; i <= conf_get_file_count(); i++) {
		write_file(conf_get_next_file);
	}

	return 0;
}
