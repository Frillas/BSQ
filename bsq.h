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
	size_t	j;
}			t_data;

char	**read_map(FILE *file, t_data *data);
char	*read_first_line(FILE *file);
int		handler(FILE *file);
void	free_map(char **map, int nb_lines);
void	free_mem(char *line, char **map, int nb_lines);
int		isalnum_bsq(char c);
char	*strcpy_bsq(char *str);
size_t	strlen_bsq(char *str);
char	*getline_bsq(FILE *file);
int		find_square(char **map, t_data *data);
int		**create_int_map(t_data *data);
void	free_int_map(int **int_map, int nb_lines);
void	print_map(char **map, t_data *data);
int		check_nb_lines(char **map, t_data *data, char *line, int *index);
int		is_valid_line(char **map, t_data *data, char *line, int *index);
int		store_line(char **map, char *line, int *index);
int		read_all_lines(FILE *file, char **map, t_data *data);
void	handle_first_line(char *map, int *num, t_data *data);
int		check_min(int up, int diag, int left);
void	add_square(char **map, t_data *data);
void	process_cell(char **map, int **num, t_data *data, int i);
void	detect_square(char **map, int **num, t_data *data);
int		get_nb_lines(char *line, t_data *data, int *index);
int		get_map_data(char *line, t_data *data, int *index);
int		check_data(t_data *data);
int		get_data(char *line, t_data *data);

#endif
