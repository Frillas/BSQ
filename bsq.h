/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:05:46 by aroullea          #+#    #+#             */
/*   Updated: 2025/11/22 18:55:40 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>

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
	int		i;
	size_t	j;
}			t_data;

// handler
int		handler(FILE *file);

// handler utils
int		get_data(char *line, t_data *data);

// read
int		read_map(FILE *file, t_data *data);

// read_utils
int		check_line_size(char *line, t_data *data);
int		read_all_lines(FILE *file, int *current, int *prev, t_data *data);

// square
int		detect_square(char *line, int *current, int *prev, t_data *data);
int		handle_first_line(char *map, int *current, t_data *data);

// print
int		print_map(FILE *file, t_data *data);

// free
// void	free_int_map(int **int_map, int nb_lines);
// void	free_map(char **map, int nb_lines);
// void	free_mem(char *line, char **map, int nb_lines);

// utils
int		isalnum_bsq(char c);
size_t	strlen_bsq(char *str);
char	*getline_bsq(FILE *file);

#endif
