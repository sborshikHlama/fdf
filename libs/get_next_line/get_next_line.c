/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:00:33 by aevstign          #+#    #+#             */
/*   Updated: 2023/11/16 19:27:03 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = read_append(fd, string);
	if (!string)
		return (NULL);
	line = get_line(string);
	string = update_line(string);
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

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		lines;

// 	lines = 1;
// 	fd = open("test.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 		printf("%d->%s\n", lines++, line);
// 	return (0);
// }
