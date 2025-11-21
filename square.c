#include "bsq.h"

static void handle_first_line(char *map, int *num, t_data *data)
{
	size_t i;

	for (i = 0; i < (data->line_len - 1); i++)
	{
		if (map[i] == data->space)
			num[i] = 1;
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

static void  add_square(int x, int y, int max, char **map, t_data *data)
{
	int i, j;

	for (j = y; j >= (y - (max - 1)); j--)
	{
		for (i = x; i >= (x - (max - 1)); i--)
		{
			map[j][i] = data->square; 
		}
	}
}

static void detect_square(char **map, int **num, t_data *data)
{
	int		i, *pnum, *prev, max, x, y;
	size_t	j; 
	char	*pmap;
	
	max = 0;
	for (i = 1; i < data->nb_lines; i++)
	{
		for (j = 0; j < (data->line_len - 1); j++)
		{
			pmap = map[i];
			pnum = num[i];
			prev = num[i - 1];

			if (pmap[j] == data->obstacle)
				pnum[j] = 0;
			else if (j == 0) 
				pnum[j] = prev[j];
			else 
			{
				pnum[j] = check_min(prev[j], prev[j - 1], pnum[j - 1]) + 1;
				if (max < pnum[j])
				{
					max = pnum[j];
					x = j;
					y = i;
				}
			}
		}
	}
	add_square(x, y, max, map, data);
}

int find_square(char **map, t_data *data)
{
	int **num;

	num = create_int_map(data);
	if (num == NULL)
		return (1);

	handle_first_line(map[0], num[0], data);

	detect_square(map, num, data);
	free_int_map(num, data->nb_lines);

	return (0);
}
