#include "../includes/utility_functions.h"

int	word_len(char *word){
	if (!word)
		return -1;
	int count;
	for(count = 0; word[count] != '\n' && word[count] != '\0'; count++){}
	return count;
}

boolean	ft_isprintable(char c){
	if (c <= 32 || c == 127)
		return TRUE;
	return FALSE;
}

char	*ft_formatstr(char *str){
	if (str == NULL)
		return (NULL);
	int j = 0;
	for(int i = 0; str[i] != '\0'; i++){
		if (str[i] >= 'A' && str[i] <= 'Z'){
			str[j] = str[i] + 32;
			j++;
		}
		else if(ft_isprintable(str[i]) == FALSE){
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
	return (&str[0]);
}

void	ft_strncpy(char *src, char *dest, unsigned int n){
	for(unsigned int i = 0; src[i] != '\0' && i < n; i++)
		dest[i] = src[i];
}

void	swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}