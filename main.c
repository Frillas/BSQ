#include "bsq.h"

static int	check_args(int argc)
{
	if (argc < 2)
		return (1);

	return (0);
}

static int	open_file(char *argv[], FILE **file)
{
	*file = fopen(argv[1], "r");
	if (*file == NULL)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	FILE *file = NULL;

	if (check_args(argc))
		return (1);

	open_file(argv, &file);
	if (file == NULL)
		return (1);

	if (handler(file))
	{
		fclose(file);
		return (1);
	}

	fclose(file);
	return (0);
}
