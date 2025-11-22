#include "bsq.h"

static void handle_one_line(char *map, t_data *data)
{
	size_t i;

	for (i = 0; i < (data->line_len - 1); i++)
	{
		if (map[i] == data->space)
		{
			map[i] = data->square;
			break;
		}
	}
}

static void handle_first_line(char *map, int *num, t_data *data)
{
	size_t i;

	for (i = 0; i < (data->line_len - 1); i++)
	{
		if (map[i] == data->space)
		{
			num[i] = 1;
			if (data->max < num[i])
			{
				data->max = num[i];
				data->x = i;
			}
		}
		else
			num[i] = 0;
	}
}

int	check_min(int up, int diag, int left)
{
	if (up <= diag && up <= left)
		return (up);
	else if (diag <= up && diag <= left)
		return (diag);
	else
		return(left);
}

static void  add_square(char **map, t_data *data)
{
	int i, j;

	for (j = data->y; j >= (data->y - (data->max - 1)); j--)
	{
		for (i = data->x; i >= (data->x - (data->max - 1)); i--)
		{
			map[j][i] = data->square; 
		}
	}
}

static void detect_square(char **map, int **num, t_data *data)
{
	int		i, *pnum, *prev;
	size_t	j; 
	char	*pmap;
	
	for (i = 1; i < data->nb_lines; i++)
	{
		for (j = 0; j < (data->line_len - 1); j++)
		{
			pmap = map[i];
			pnum = num[i];
			prev = num[i - 1];

			if (pmap[j] == data->obstacle)
				pnum[j] = 0;
			else 
			{
				if (j == 0) 
					pnum[j] = check_min(prev[j], 0, 0) + 1;
				else
					pnum[j] = check_min(prev[j], prev[j - 1], pnum[j - 1]) + 1;
				if (data->max < pnum[j])
				{
					data->max = pnum[j];
					data->x = j;
					data->y = i;
				}
			}
		}
	}
	add_square(map, data);
}

int find_square(char **map, t_data *data)
{
	int **num;

	if (data->nb_lines == 1)
	{
		handle_one_line(map[0], data);
		return (0);
	}

	num = create_int_map(data);
	if (num == NULL)
		return (1);

	handle_first_line(map[0], num[0], data);

	detect_square(map, num, data);
	free_int_map(num, data->nb_lines);

	return (0);
}
