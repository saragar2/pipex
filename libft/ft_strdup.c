/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:13:21 by saragar2          #+#    #+#             */
/*   Updated: 2023/09/24 11:10:11 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*aux;
	int		len;

	len = ft_strlen(s1);
	aux = malloc(len + 1);
	if (!aux)
		return (NULL);
	while (*s1 != '\0')
	{
		*aux = *s1;
		aux++;
		s1++;
	}
	*aux = '\0';
	while (len > 0)
	{
		len--;
		aux--;
	}
	return (aux);
}
/*int	main()
{
	char s[] = "hola mundo";
	char *res = ft_strdup(s);
	printf("%s", res);
	free(res);
	return (0);
}*/
