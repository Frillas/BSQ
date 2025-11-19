#include "bsq.h"

size_t	strlen_bsq(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*strjoin_bsq(char *str1, char *str2)
{
	int len1 = 0, len2 = 0, i = 0;
	char *new_str;
	
	if (str1 != NULL)
		len1 = strlen_bsq(str1);
	if (str2 != NULL)
		len2 = strlen_bsq(str2);

	new_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (new_str == NULL)
		return (NULL);

	while (i < len1)
	{
		new_str[i] = str1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		new_str[i] = str2[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char *getline_bsq(FILE *file, char *line)
{
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
