#include "../includes/database.h"

boolean	fill_dictionary(char *filename){
	int fd;
	char *buffer = (char *)malloc(sizeof(char)*MAX_BUF);
	fd = open(filename, O_RDONLY);
	if(fd < 0){
		puterrmsg(FILE_NOT_READABLE_MSG);
		return NULL;
	}
	read(fd, buffer, MAX_BUF);
	
	close(fd);
	return TRUE;
}
