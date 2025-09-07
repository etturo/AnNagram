#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# define TRUE 1
# define FALSE 0

# define FILE_NOT_READABLE_MSG "File is not readable or empty."
# define ERROR_MSG "Error!"
# define INVALID_ARGUMENTS "Invalid Arguments!"

# include <stdio.h>
# include <unistd.h>

typedef unsigned short int boolean;

int	puterrmsg(char *msg);

#endif