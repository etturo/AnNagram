#include "../includes/checker.h"

boolean check(int n, char *reference, char *buffer){
	int	valid_letter = 0;
	int k = 0;

	while(buffer && valid_letter < n)
	{
		if (word_len(&buffer[k]) != n)
			return FALSE;
		for(int j = 0; j < word_len(&buffer[k]); j++)
		{
			for(int i = 0; i < word_len(reference); i++)
			{
				if(reference[i] == buffer[k+j])
					valid_letter++;
			}
		}
		k += word_len(&buffer);
	}
	if(valid_letter == n)
		return TRUE;
	return FALSE;
}