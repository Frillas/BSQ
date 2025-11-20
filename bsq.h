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
}			t_data;

char	**read_map(FILE *file, t_data *data);
char	*read_first_line(FILE *file);
int		handler (FILE *file);
void	free_map(char **map, int nb_lines);
char	*strcpy_bsq(char *str);
size_t	strlen_bsq(char *str);
char	*getline_bsq(FILE *file);

#endif
