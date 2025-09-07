#include "../includes/checker.h"

boolean	check(char *reference, char *file_word){
	int len1 = word_len(reference);
	int len2 = word_len(file_word);
	if (len2 > len1)
		return FALSE;
	char ascii_count[256];
	for(int i = 0; i < 256; i++)
		ascii_count[i] = 0;
	for(int i = 0; i < len1; i++)
		ascii_count[(int)reference[i]]++;
	for(int i = 0; i < len2; i++)
		ascii_count[(int)file_word[i]]--;
	for(int i = 0; i < 256; i++)
		if(ascii_count[i] < 0)
			return FALSE;
	return TRUE;
}