#include "bsq.h"

int	isalnum_bsq(char c)
{
	if (c >= 32 && <= 126)
		return (1);
	return (0);
}

size_t	strlen_bsq(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*strcpy_bsq(char *str)
{
	int len = 0, i = 0;
	char *new_str;

	if (str == NULL)
		return (NULL);

	len = strlen_bsq(str);
	if ((new_str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);

	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char *getline_bsq(FILE *file)
{
	char *line = NULL;
	size_t	n = 0; 
	ssize_t nb_bytes = 0;

	nb_bytes = getline(&line, &n, file);
	if (nb_bytes < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
