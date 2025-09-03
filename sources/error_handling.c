#include "../includes/error_handling.h"

int	puterrmsg(char *msg){
	for(int i = 0; msg[i]!=0; i++)
		write(2, &msg[i], 1);
	write(2, "\n", 1);
	return (-1);
}
