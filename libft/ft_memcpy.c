/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:20:59 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/19 19:01:16 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*auxdst;
	char	*auxsrc;

	auxdst = (char *) dst;
	auxsrc = (char *) src;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		*auxdst = *auxsrc;
		auxdst++;
		auxsrc++;
		n--;
	}
	return (dst);
}
/*int	main()
{
	char	src[] = "zy\0xw\0vu\0\0tsr";
	char	dst[20];
	int	n = 11;
	printf("%s", ft_memcpy(dst, src, n));
	printf("%s", memcpy(dst, src, n));
	return (0);
}*/
