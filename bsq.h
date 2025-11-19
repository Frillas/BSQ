#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>

char	**read_all_lines(FILE *file, int nb_lines);
char	*read_first_line(FILE *file);
int		handler (FILE *file);
void	free_map(char **map, int nb_lines);
char	*strjoin_bsq(char *str1, char *str2);
size_t	strlen_bsq(char *str);
char	*getline_bsq(FILE *file, char *line);

#endif
