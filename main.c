#include "bsq.h"

static int	open_file(char *argv[], FILE **file, int i)
{
	*file = fopen(argv[i], "r");
	if (*file == NULL)
	{
		fprintf(stderr, "map error\n");
		return (1);
	}
	return (0);
}

static int	check_args(int argc)
{
	if (argc < 2)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	FILE	*file = NULL;
	int		i;

	if (check_args(argc))
	{
		handler(stdin);
		return (0);
	}

	for(i = 1; i < argc; i++)
	{
		if (i > 1)
			fprintf(stdout, "\n");

		open_file(argv, &file, i);
		if (file == NULL)
			continue;

		if (handler(file))
			fprintf(stderr, "map error\n");
		
		fclose(file);
		file = NULL;
	}

	return (0);
}
