#include "bsq.h"

char	**read_all_lines(FILE *file, int nb_lines)
{
	int i = 0;
	char **map, *line = NULL;

	map = (char**)malloc(nb_lines * sizeof(char **));
	if (map == NULL)
		return (NULL);

	while (i < nb_lines)
	{
		line = getline_bsq(file, line);
		if (line == NULL)
		{
			free_map(map, i);
			return (NULL);
		}

		map[i] = strjoin_bsq(NULL, line);
		if (map[i] == NULL)
		{
			free(line);
			free_map(map, i);
			return (NULL);
		}
		
		free(line);
		printf("%s", map[i]);
		i++;
	}
	return (map);
}

char *read_first_line(FILE *file)
{
	char *line = NULL;

	line = getline_bsq(file, line);
	if (line == NULL)
		return (NULL);
	
	printf("%s", line);
	return (line);
}
