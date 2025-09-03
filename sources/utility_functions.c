#include "../includes/utility_functions.h"

int word_len(char *word){
	int count;
	for(count = 0; word[count] != '\n' && word[count] != '\0'; count++){}
	return count;
}