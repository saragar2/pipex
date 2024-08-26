/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:21:41 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/05 18:30:04 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*sol;
	int		i;

	len = ft_strlen(s);
	i = 0;
	sol = malloc(len + 1);
	if (!sol || !s || !f)
		return (NULL);
	while (i < len)
	{
		sol[i] = f(i, s[i]);
		i++;
	}
	sol[i] = '\0';
	return (sol);
}
/*char	onemoreo(unsigned int i, char c)
{
	if (i % 2 == 0)
		return ('0');
	else
		return (c);
}

int     main()
{
        char *sol = "hello world999";
        printf("%s", ft_strmapi(sol, onemoreo));
        return (0);
}*/
