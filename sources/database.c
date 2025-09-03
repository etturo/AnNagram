#include "../includes/database.h"

dict	*new_word(char *word, dict *dictionary){
	dict *new_element = (dict *)malloc(sizeof(dict));

	dictionary->next = new_element;
	int count = word_len(word);
	if(count > 0)
		new_element->word = (char *)malloc(sizeof(char)*count);
	else
		return NULL;
	strcpy(new_element->word, word);
	new_element->next = NULL;
	new_element->prev = dictionary;
	dictionary = new_element;
	return dictionary;
}

dict	*dict_init(void){
	dict *head = (dict *)malloc(sizeof(dict));
	head->word = NULL;
	head->prev = NULL;
	head->next = NULL;
	return head;
}

dict	*fill_dictionary(char *filename){
	int fd;
	char *buffer = (char *)malloc(sizeof(char)*MAX_BUF);
	fd = open(filename, O_RDONLY);
	if(fd < 0){
		puterrmsg(FILE_NOT_READABLE_MSG);
		return NULL;
	}
	read(fd, buffer, MAX_BUF);
	dict *dictionary = dict_init();
	dict *dict_head = dictionary;
	unsigned long int index = 0;
	char word[20];
	while(buffer[index])
	{
		int j = 0;
		while(buffer[index] != '\n'){
			word[j] = buffer[index];
			index++;
			j++;
		}
		for(int k = 0; k < 20; k++)
			word[k] = 0;
		dictionary = new_word(word, dictionary);
		if(!dictionary)
			return NULL;
		index++;
	}
	close(fd);
	return dict_head;
}
