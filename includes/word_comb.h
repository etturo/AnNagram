#ifndef WORD_COMB_H
# define WORD_COMB_H

# include "utility_functions.h"
# include "error_handling.h"
# include <unistd.h>
# include <stdlib.h>

struct list {
	char *str;
	struct list *next;
};

struct list	*init_list(struct list **list);
struct list	*add_element(struct list **list, char *str);
void		print_list(struct list **list);
void		free_list(struct list **head);



#endif