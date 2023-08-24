/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:02:03 by vpolojie          #+#    #+#             */
/*   Updated: 2022/03/26 13:08:22 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_check(char c, char charset)
{
	if (c == charset)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_nb_mots(char *str, char charset)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_check(str[i +1], charset) == 1)
			&& ft_check(str[i], charset) == 0)
			words++;
		i++;
	}
	return (words);
}

void	ft_write_word(char *dest, char *from, char charset)
{
	int		i;

	i = 0;
	while (ft_check(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_write_split(char **strs, char *str, char charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_check(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_check(str[i + j], charset) == 0)
				j++;
			strs[word] = (char *)malloc(sizeof(char) * (j + 1));
			ft_write_word(strs[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char const *str, char charset)
{
	char	**strs;
	int		indice_mots;

	indice_mots = ft_nb_mots((char *)str, charset);
	strs = (char **)malloc(sizeof(char *) * (indice_mots + 1));
	strs[indice_mots] = 0;
	ft_write_split(strs, (char *)str, charset);
	return (strs);
}
