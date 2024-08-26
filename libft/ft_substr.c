/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:40:24 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/15 17:42:14 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux;
	size_t	cont;

	cont = 0;
	if (start < 0 || ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		aux = malloc(ft_strlen(s) - start + 1);
	else
		aux = malloc(len + 1);
	if (!aux)
		return (NULL);
	s += start;
	while (len > 0 && *s != '\0')
	{
		*(aux++) = *(s++);
		cont++;
		len--;
	}
	*aux = '\0';
	while (cont-- > 0)
		aux--;
	return (aux);
}
/*int	main()
{
	char s[] = "hola mundo";
	char *res = ft_substr(s, 1, 6);
	printf("%s", res);
	free(res);
	return (0);
}*/
