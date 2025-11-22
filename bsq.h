#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	int		nb_lines;
	char	space;
	char	obstacle;
	char	square;
	size_t	line_len;
	int		max;
	int		x;
	int		y;
}			t_data;

char	**read_map(FILE *file, t_data *data);
char	*read_first_line(FILE *file);
int		handler (FILE *file);
void	free_map(char **map, int nb_lines);
int		isalnum_bsq(char c);
char	*strcpy_bsq(char *str);
size_t	strlen_bsq(char *str);
char	*getline_bsq(FILE *file);
int		find_square(char **map, t_data *data);
int		**create_int_map(t_data *data);
void	free_int_map(int **int_map, int nb_lines);
void	print_map(char **map, t_data *data);

#endif
