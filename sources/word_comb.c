#include "../includes/word_comb.h"

int comb_size = 0;
char *current_comb[10000];
int printed = 0;

struct list	*init_list(struct list **list){
	(*list) = (struct list *)xmalloc(sizeof(struct list));
	(*list)->next = NULL;
	(*list)->str = NULL;
	(*list)->prev =NULL;
	return *list;
}

struct list	*add_element(struct list **list, char *str){
	struct list *new_ele = xmalloc(sizeof(struct list));
	new_ele->str = xmalloc(strlen(str) + 1);
	strcpy(new_ele->str, str);
	new_ele->next = NULL;
	if (*list)
		new_ele->prev = (*list);
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
		if(temp->str)
			free(temp->str);
		free(temp);
	}
	*head = NULL;
}

boolean	is_solution(int char_set[]){
	for(int i = 0; i < 256; i++)
		if(char_set[i] != 0)
			return FALSE;
	return TRUE;
}

void	print_solution(){
	for(int i = 0; i < comb_size; i++)
		printf("%s ", current_comb[i]);
	printf("\n");
}

void	backtrack(struct list *current, int char_set[]){
	if(is_solution(char_set))
	{
		printed++;
		return print_solution();
	}

	if(!current)
		return;

	struct list *temp = current;
	while(temp && temp->str)
	{
		boolean can_use = TRUE;
		for(int i = 0; temp->str[i] != '\0'; i++) {
			if(char_set[(unsigned char)temp->str[i]] <= 0) {
				can_use = FALSE;
				break;
			}
		}

		if(can_use == TRUE)
		{
			current_comb[comb_size] = temp->str;
			comb_size++;

			for(int i = 0; temp->str[i] != '\0'; i++)
				char_set[(unsigned char)temp->str[i]]--;
			
			backtrack(temp->next, char_set);

			for(int i = 0; temp->str[i] != '\0'; i++)
				char_set[(unsigned char)temp->str[i]]++;
			comb_size--;

		}
		temp = temp->next;
	}
}

int	find_comb(struct list *elements, char *ref){
	int char_set[256] = {0};

	for(int i = 0; ref[i] != '\0'; i++)
			char_set[(unsigned char)ref[i]]++;
	
	backtrack(elements, char_set);
	return printed;
}