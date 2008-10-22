#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <mysql.h>

#define HELLO_WORLD "Hello World"

/*
gcc -Wall -bundle -o hello.so `/usr/local/mysql/bin/mysql_config --cflags` hello.c

gcc -Wall -bundle -o hello.so -I/usr/local/mysql/include -Os -arch i386 -fno-common hello.c
*/

char *hello_world (UDF_INIT *initid, UDF_ARGS *args,
	char *result, unsigned long *length,
	char *is_null, char *error)
{
	strcpy(result, HELLO_WORLD);
	*length=strlen(HELLO_WORLD);

	return result;
}

my_bool hello_world_init (UDF_INIT *initid, UDF_ARGS *args, char *message)
{
	initid->max_length=255;
	initid->const_item=1;
	
	return 0; /* success */
}

void hello_world_deinit (UDF_INIT *initid)
{
	return;
}

