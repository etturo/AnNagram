#include "../includes/error_handling.h"
#include "../includes/utility_functions.h"

int	main(int argc, char **argv){
	if(argc!=2 || !argv || !*argv)
		return puterrmsg(INVALID_ARGUMENTS);

	printf("%s\n", ft_formatstr(argv[1]));
}
