#include "../includes/error_handling.h"
#include "../includes/database.h"


int	main(int argc, char **argv){
	if(argc!=2 || !argv || !*argv)
		return puterrmsg(INVALID_ARGUMENTS);

	dict *head = fill_dictionary(argv[1]);
	dict *current = head;

	for(int i = 0; i < 10; i++){
		printf("%s\n", current->word);
		current = current->next;
	}
	while(head){
		dict *temp = head;
		head = head->next;
		free(temp);
	}
}
