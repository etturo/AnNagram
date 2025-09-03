#ifndef DATABASE_H
# define DATABASE_H

#define TRUE 1
#define FALSE 0

# define MAX_BUF 2000000000

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "error_handling.h"
# include "utility_functions.h"

typedef unsigned short int boolean;

typedef struct list{
	char *word;
	struct list *next;
	struct list *prev;
} dict;

dict	*fill_dictionary(char *filename);
dict	*new_word(char *word, dict *dictionary);


#endif