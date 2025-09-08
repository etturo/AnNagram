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
		char c = str[i];
		if (c >= 'A' && c <= 'Z'){
			c = c + 32;
		}
		c = normalize_char(c);
		if (ft_isprintable(c) == FALSE){
			str[j] = c;
			j++;
		}
	}
	str[j] = '\0';
	return str;
}

void	ft_strncpy(char *src, char *dest, unsigned int n){
	unsigned int	i;
	for(i = 0; src[i] != '\0' && i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}

void	swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

char normalize_char(char c) {
	// Converte caratteri accentati nei loro equivalenti non accentati
	unsigned char uc = (unsigned char)c;

	switch(uc) {
		// à, á, â, ã, ä, å
		case 0xE0: case 0xE1: case 0xE2: case 0xE3: case 0xE4: case 0xE5:
			return 'a';
		// è, é, ê, ë
		case 0xE8: case 0xE9: case 0xEA: case 0xEB:
			return 'e';
		// ì, í, î, ï
		case 0xEC: case 0xED: case 0xEE: case 0xEF:
			return 'i';
		// ò, ó, ô, õ, ö
		case 0xF2: case 0xF3: case 0xF4: case 0xF5: case 0xF6:
			return 'o';
		// ù, ú, û, ü
		case 0xF9: case 0xFA: case 0xFB: case 0xFC:
			return 'u';
		// ç
		case 0xE7:
			return 'c';
		// ñ
		case 0xF1:
			return 'n';
		default:
			return c;
	}
}