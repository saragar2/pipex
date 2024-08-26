/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:41:17 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/13 12:06:25 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == '\t' && c == '\t')
			return (1);
		if (set[i] == '\n' && c == '\n')
			return (1);
		if (set[i] == ' ' && c == ' ')
			return (1);
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_emptystr(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	s;
	size_t	e;
	size_t	i;

	i = 0;
	s = 0;
	e = ft_strlen(s1) - 1;
	while ((s1[s] && ft_isset (s1[s], set)))
		s++;
	while ((e > s && ft_isset (s1[e], set)))
		e--;
	if (s1[s] == '\0')
		return (ft_emptystr());
	str = (char *)malloc(sizeof(char) * (e - s) + 2);
	if (!str)
		return (NULL);
	while (s <= e)
		str[i++] = s1[s++];
	str[i] = '\0';
	return (str);
}
