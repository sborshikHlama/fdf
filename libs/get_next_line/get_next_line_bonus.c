/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:22:13 by aevstign          #+#    #+#             */
/*   Updated: 2023/11/16 19:42:57 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*string[1000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string[fd] = read_append(fd, string[fd]);
	if (!string[fd])
		return (NULL);
	line = get_line(string[fd]);
	string[fd] = update_line(string[fd]);
	return (line);
}

char	*read_append(int fd, char *string)
{
	char	*tmp;
	int		bytes;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr_gnl(string, '\n') && bytes != 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[bytes] = '\0';
		string = ft_strjoin_gnl(string, tmp);
	}
	free(tmp);
	return (string);
}
