/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:06:56 by hsaadaou          #+#    #+#             */
/*   Updated: 2020/12/10 16:05:44 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		check_errors(int fd, char **line)
{
	if (fd == -1 || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	return (1);
}

char	*find_newline(char *remaining, char **line, char *buff)
{
	char	*temp_line;
	char	*to_parse;
	char	*newline_pos;
	size_t	i;

	i = 0;
	to_parse = ft_strlen(remaining) ? ft_strdup(remaining) : ft_strdup(buff);
	while (i < ft_strlen(to_parse))
	{
		if (to_parse[i] == '\n')
		{
			to_parse[i] = '\0';
			if (!(temp_line = malloc(sizeof(char) * i + 2)))
				return (NULL);
			ft_strlcpy(temp_line, to_parse, i + 2);
			*line = ft_strjoin(*line, temp_line);
			newline_pos = ft_strdup(to_parse + i + 1);
			free(temp_line);
			return (newline_pos);
		}
		i++;
	}
	if (ft_strlen(to_parse))
		*line = ft_strjoin(*line, to_parse);
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	static char	*rem[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char		buff[BUFFER_SIZE + 1];
	int			bytes_read;

	if (!rem[fd])
		rem[fd] = 0;
	if (check_errors(fd, line) == -1)
		return (-1);
	*line = ft_strdup("");
	ft_bzero(buff, BUFFER_SIZE + 1);
	while (!(rem[fd] = find_newline(rem[fd], line, buff)))
	{
		if ((bytes_read = read(fd, buff, BUFFER_SIZE)) == -1 || bytes_read == 0)
			return (bytes_read);
		buff[bytes_read] = '\0';
	}
	return (1);
}
