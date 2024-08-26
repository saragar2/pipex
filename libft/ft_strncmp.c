/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:50:11 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/13 13:51:17 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	cont;

	cont = 0;
	if (n == 0)
		return (0);
	n -= 1;
	while (n > 0 && *s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
		n--;
	}
	if (*s1 != *s2)
		cont = (unsigned char)*s1 - (unsigned char)*s2;
	return (cont);
}
/*int	main()
{
	char	s1[] = "buenos";
	char	s2[] = "supermegadias";

	printf("%i", ft_strncmp(s1, s2, 7));
	printf("\n");
	printf("%i", strncmp(s1, s2, 7));
	return (0);
}*/
