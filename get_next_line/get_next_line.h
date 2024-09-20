/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:33:21 by saragar2          #+#    #+#             */
/*   Updated: 2023/11/26 15:05:28 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*createbuf(int fd, char *buf, int *i, int *k);
char	*newbuf(char *buf, int i, int j);
char	*createbufaux(char *buf, int i, char *bufaux, int j);
char	*bufauxfornull(char *bufaux, char *buf);
char	*buffornull(int fd, char *bufaux);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif
#endif
