#include "../includes/word_comb.h"

struct list	*init_list(struct list **list){
	(*list) = (struct list *)malloc(sizeof(struct list));
	(*list)->next = NULL;
	(*list)->str = NULL;
	return *list;
}

struct list	*add_element(struct list **list, char *str){
	struct list *new_ele = (struct list *)malloc(sizeof(new_ele));
	new_ele->str = malloc(sizeof(str));
	ft_strncpy(str, new_ele->str, sizeof(str));
	new_ele->next = NULL;
	(*list)->next = new_ele;
	return new_ele;
}

void	print_list(struct list **list){
	while(*list)
	{
		printf("%s\n", (*list)->str);
		*list = (*list)->next;
	}
}

void	free_list(struct list **head){
	struct list *current = *head;
	struct list *temp;

	while(current)
	{
		temp = current;
		current = temp->next;
		free(temp);
	}
	*head = NULL;
}

void	find_and_print_comb(struct list **head){
	struct list *current = (*head);

	
}