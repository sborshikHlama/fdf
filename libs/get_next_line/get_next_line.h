/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:43:25 by aevstign          #+#    #+#             */
/*   Updated: 2023/11/16 19:45:51 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# include <fcntl.h> 
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*read_append(int fd, char *string);
char	*get_line(char *s);
size_t	ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *s, char *buff);
char	*ft_strchr_gnl(char *s, int c);
char	*update_line(char *s);

#endif