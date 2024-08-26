/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:18:10 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/21 21:06:53 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (*(haystack + i) != '\0' && haystack[i] == needle[k] && i < len)
		{
			if (needle[k + 1] == '\0' && len != 0)
				return ((char *)haystack + i - k);
			i++;
			k++;
		}
		i -= k;
		i++;
		k = 0;
	}
	return (0);
}
/*
int	main(void)
{
	char str1[] = "nem";
	char str2[] = "";
	printf("%s\n", strnstr(str2, str1, 8));
	char s1[] = "nem";
	char s2[] = "";
	printf("%s", ft_strnstr(s2, s1, 8));
	return (0);
}
*/
