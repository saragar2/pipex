/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:06:26 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/13 14:08:19 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		cont;
	char	*snew1;
	char	*snew2;

	cont = 0;
	snew1 = (char *) s1;
	snew2 = (char *) s2;
	if (n == 0)
		return (0);
	while (n - 1 > 0 && *snew1 == *snew2)
	{
		cont += *snew1 - *snew2;
		snew1++;
		snew2++;
		n--;
	}
	if (*snew1 != *snew2)
		cont = (unsigned char)*snew1 - (unsigned char)*snew2 + cont;
	return (cont);
}
/*int	main()
{
	char	s1[] = "buenos";
	char	s2[] = "b1upermegadias";

	printf("%i", ft_memcmp(s1, s2, 4));
	printf("\n");
	printf("%i", memcmp(s1, s2, 4));
	return (0);
}*/
