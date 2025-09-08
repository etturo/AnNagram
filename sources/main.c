#include "../includes/error_handling.h"
#include "../includes/utility_functions.h"
#include "../includes/checker.h"
#include "../includes/word_comb.h"
#include <fcntl.h>

#define O_RDONLY 0x0000
#define FILENAME "data/words.txt"

int	main(int argc, char **argv){
	if(argc<2 || !argv || !*argv)
		return puterrmsg(INVALID_ARGUMENTS);

	char *str = ft_formatstr(argv[1]);
	int fd = open(FILENAME, O_RDONLY);

	if (fd < 0)
		return puterrmsg(FILE_NOT_READABLE_MSG);

	char	buffer[1024];
	char	word[256];
	char	normalized_word[256];
	int		bytes_read;
	int		word_index = 0;
	struct list *list = init_list(&list);
	struct list *head = list;
	while((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		for(int i = 0; i < bytes_read; i++)
		{
			if(buffer[i] == '\n')
			{
				if(word_index > 0)
				{
					word[word_index] = '\0';
					ft_strncpy(word, normalized_word, sizeof(word));
					ft_formatstr(normalized_word);
					if(check(str, normalized_word) == TRUE)
						list = add_element(&list, word);
				}
				word_index = 0;
			}
			else
			{
				if (word_index < (int)sizeof(word))
				{
					word[word_index] = buffer[i];
					word_index++;
				}
			}
		}
	}
	find_comb(head->next, str);
	free_list(&head);
	close(fd);
	return 0;
}