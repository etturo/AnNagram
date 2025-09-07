#include "../includes/error_handling.h"
#include "../includes/utility_functions.h"
#include "../includes/checker.h"
#include <fcntl.h>\

#define BUFFER_SIZE 1250400

char	*filename = "../data/words.txt";

int	main(int argc, char **argv){
	if(argc!=2 || !argv || !*argv)
		return puterrmsg(INVALID_ARGUMENTS);
	char *str = ft_formatstr(argv[1]);
	int fd = open(filename, O_RDONLY);
	if (fd == 0)
		return puterrmsg(FILE_NOT_READABLE_MSG);
	char *buffer = (char*)malloc(BUFFER_SIZE*sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	int		len_count;
	char	*file_word = NULL;
	for(unsigned int i = 0; i < 1250378; i++)
	{
		len_count = word_len(buffer);
		ft_strncpy(&buffer[i], file_word,len_count);
		if(check(str, file_word) == TRUE)
			printf("%s\n", file_word);
		i += len_count;
	}
	free (buffer);
	close(fd);
	return 0;
}