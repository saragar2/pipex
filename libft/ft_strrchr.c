/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:24:19 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/19 19:21:27 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*search;
	size_t	len;

	len = ft_strlen(s);
	while (*s != '\0')
		s++;
	if (*s == (char)c)
	{
		search = (char *) s;
		return (search);
	}
	s--;
	while (len-- > 0)
	{
		if (*s == (char)c)
		{
			search = (char *) s;
			return (search);
		}
		else
			s--;
	}
	return (NULL);
}
/*int main()
{
    const char *s = "Bonjour";
    char c = '\0';
    //char *res = ft_strrchr(s, c);
	printf("1. %s\n", ft_strrchr(s, c));
	printf("2. %s", strrchr(s, c));
	
    if (res != NULL)
	{
		//unir las dos siguientes en una
        printf("Se encontró '%c' en la posición
		%ld de la cadena.\n", c, res - s);
    }
	else
	{
        printf("'%c' no se encontró een la cadena.\n", c);
    }

    return 0;
}*/
