#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <mysql.h>

#define HELLO_WORLD "Hello World"

/*
gcc -Wall -bundle -o hello.so `/usr/local/mysql/bin/mysql_config --cflags` hello.c

gcc -Wall -bundle -o hello.so -I/usr/local/mysql/include -Os -arch i386 -fno-common hello.c
*/


/* illustrate simple argument handling */
char *hello(UDF_INIT *initid, UDF_ARGS *args,
	char *result, unsigned long *length,
	char *is_null, char *error)
{
	
	strcpy(result, "Hello");
	strcat(result, " ");
	strcat(result, args->args[0]);
	*length=strlen(result);

	return result;
}

my_bool hello_init (UDF_INIT *initid, UDF_ARGS *args, char *message)
{
	if(args->arg_count != 1)
	{
		strcpy(message, "hello requires exactly one string argument");
		return 1;
	}
	if(args->arg_type[0] != STRING_RESULT)
	{
		strcpy(message, "hello requires exactly one string argument");
		return 1;
	}

	initid->max_length=args->lengths[0]+strlen("hello ");
	return 0; /* true */
}

void hello_deinit (UDF_INIT *initid)
{
	return;
}
