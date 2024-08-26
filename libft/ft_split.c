/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:19:50 by saragar2          #+#    #+#             */
/*   Updated: 2023/10/13 13:49:57 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cpal(char const *s, char c)
{
	int	palabras;

	palabras = 0;
	if (*s && (*s != c))
		palabras++;
	while (*s)
	{
		if ((*s == c) && (*(s +1) != c) && (*(s + 1) != '\0'))
			palabras++;
		s++;
	}
	return (palabras);
}

static char	*annadir(char const *s, int tampal)
{
	char	*aux;
	int		j;

	j = 0;
	aux = malloc(tampal + 1);
	if (!aux)
		return (0);
	aux[tampal] = '\0';
	j = 0;
	while (j < tampal)
	{
		*aux = *s;
		s++;
		aux++;
		j++;
	}
	aux -= tampal;
	return (aux);
}

static void	rm_all(char **sol, int i)
{
	while (i >= 0)
	{
		free(sol[i]);
		i--;
	}
	free(sol);
}

static int	hacer(const char *s, char c, int i, char **sol)
{
	int	tampal;

	tampal = 0;
	while (*s && (*s != c))
	{
		tampal++;
		s++;
	}
	s -= tampal;
	sol[i] = annadir(s, tampal);
	if (!sol[i])
	{
		rm_all(sol, i);
		return (0);
	}
	return (tampal);
}

char	**ft_split(char const *s, char c)
{
	char	**sol;
	int		tampal;
	int		i;

	while (*s == c && *s != '\0')
		s++;
	sol = malloc(((cpal(s, c)) + 1) * sizeof(char *));
	if (!sol)
		return (0);
	i = 0;
	while (*s)
	{
		tampal = hacer(s, c, i, sol);
		if (tampal == 0)
			return (0);
		s += tampal;
		while (*s == c && *s)
			s++;
		i++;
	}
	sol[i] = NULL;
	return (sol);
}
/*int main(void)
{
    char const *cadena = "Hola,Mundo,Esta,Es,Una,Prueba";
    char **palabras;
    char delimitador = ',';
	int i = 0;

    palabras = ft_split(cadena, delimitador);

    while (palabras[i])
    {
        printf("%s\n", palabras[i]);
        i++;
    }
    i = 0;
    while (palabras[i])
    {
        free(palabras[i]);
        i++;
    }
    free(palabras);
    return (0);
}*/
