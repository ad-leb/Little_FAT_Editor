/* lol allocate */

void* sbrk (int);


void* helpr___lalloc (int size)
{
	return sbrk(size);
}
