/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:59:36 by hsaadaou          #+#    #+#             */
/*   Updated: 2020/12/03 22:31:23 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int					get_next_line(int fd, char **line);
int					is_end_line(char *str);

size_t				ft_strlen(const char *s);

char				*join_strings_and_clean(const char *s1, const char *s2);

#endif
