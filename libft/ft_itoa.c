/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:29:50 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/21 20:35:32 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*moldauxneg(size_t len, int res, char *aux)
{
	int		sol;
	size_t	tam;

	if (aux[0] == '-')
		tam = 1;
	else
		tam = 0;
	while (len > tam)
	{
		sol = res % 10;
		res = res / 10;
		aux[--len] = (char)sol + '0';
	}
	return (aux);
}

static char	*moldauxpos(size_t len, int res, char *aux)
{
	int	sol;

	while (len > 0)
	{
		sol = res % 10;
		res = res / 10;
		aux[--len] = (char)sol + '0';
	}
	return (aux);
}

static char	*createaux(size_t len, int res, char *aux, int n)
{
	if (n != -2147483648)
		len++;
	if (n < 0)
		moldauxneg(len, res, aux);
	else
		moldauxpos(len, res, aux);
	return (aux);
}

static size_t	newlen(int res)
{
	int	len;

	len = 1;
	while (res / 10 != 0)
	{
		res = res / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*aux;
	size_t	len;
	int		res;

	res = n;
	len = newlen(res);
	if (n < 0)
		len += 1;
	aux = malloc(len + 1);
	if (!aux)
		return (NULL);
	if (n < 0)
	{
		if (res == -2147483648)
		{
			aux[len - 1] = '8';
			res = 214748364;
		}
		else
			res *= -1;
		aux[0] = '-';
	}
	aux[len--] = '\0';
	createaux(len, res, aux, n);
	return (aux);
}
