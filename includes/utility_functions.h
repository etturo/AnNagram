#ifndef UTILITY_FUNCTIONS_H
# define UTILITY_FUNCTIONS_H

typedef unsigned short int boolean;
# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <unistd.h>

int 	word_len(char *word);
char	*ft_formatstr(char *str);
boolean	ft_isprintable(char c);
void	ft_strncpy(char *src, char *dest, unsigned int n);
void	swap(char *a, char *b);

#endif