#include "bsq.h"

static int	alloc_map(char ***map, int nb_lines)
{
	*map = (char**)malloc((nb_lines + 1) * sizeof(char *));
	if (*map == NULL)
		return (1);
	return (0);
}

static int check_nb_lines(char **map, t_data *data, char *line, int *index)
{
	int i = *index;

	if (i >= data->nb_lines)
	{
		free(line);
		free_map(map, i);
		return (1);
	}
	return (0);
}

static int is_valid_line(char **map, t_data *data, char *line, int *index)
{
	size_t size;
	int i = *index, j = 0;

	if (i == 0)
		data->line_len = strlen_bsq(line);
	size = strlen_bsq(line);
	if (size != data->line_len || line[size - 1] != '\n')
	{
		free(line);
		free_map(map, i);
		return (1);
	}
	while (line[j] != '\n')
	{
		if (line[j] != data->space && line[j] != data->obstacle)
		{
			free(line);
			free_map(map, i);
			return (1);
		}
		j++;
	}
	return (0);
}

static int store_line(char **map, char *line, int *index)
{
	int i = *index;

	map[i] = strcpy_bsq(line);
	if (map[i] == NULL)
	{
		free(line);
		free_map(map, i);
		return (1);
	}
	return (0);
}

static int read_all_lines(FILE *file, char **map, t_data *data)
{
	char *line = NULL;
	int i = 0;

	while (1)
	{
		line = getline_bsq(file);
		if (line == NULL)
			break;
		if (check_nb_lines(map, data, line, &i))
			return (1);
		if (is_valid_line(map, data, line, &i))
			return (1);
		if (store_line(map, line, &i))
			return (1);
		free(line);
		i++;
	}
	if (i < data->nb_lines)
	{
		free_map(map, i);
		return (1);
	}
	return (0);
}

char	**read_map(FILE *file, t_data *data)
{
	char **map;

	if (alloc_map(&map, data->nb_lines))
		return (NULL);

	if (read_all_lines(file, map, data))
		return (NULL);

	map[data->nb_lines] = NULL;

	return (map);
}

char *read_first_line(FILE *file)
{
	char *line;

	line = getline_bsq(file);
	if (line == NULL)
		return (NULL);

	return (line);
}
