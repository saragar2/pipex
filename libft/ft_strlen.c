/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:23:26 by saragar2          #+#    #+#             */
/*   Updated: 2023/09/21 19:20:02 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	cont;

	cont = 0;
	while (*s != '\0')
	{
		cont ++;
		s ++;
	}
	return (cont);
}
/*int	main()
{
	const char	ex[] = "hol0\n0--0a";

	printf("%zu", ft_strlen(ex));
	printf("%zu", strlen(ex));
}*/
