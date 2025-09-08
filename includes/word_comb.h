#ifndef WORD_COMB_H
# define WORD_COMB_H

# include "utility_functions.h"
# include "error_handling.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

struct list {
	char *str;
	struct list *next;
	struct list *prev;
};

struct list	*init_list(struct list **list);
struct list	*add_element(struct list **list, char *str);
void		print_list(struct list **list);
void		free_list(struct list **head);
void		find_comb(struct list *elements, char *ref);
void		backtrack(struct list *current, int char_set[]);
void		print_solution();
boolean		is_solution(int char_set[]);

#endif