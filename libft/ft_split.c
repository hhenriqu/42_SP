/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:37:14 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/06/12 18:57:35 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	size_t	words;

	words = 0;
	if (*s == '\0')
		return (words);
	if (c == '\0')
		return (1);
	while (*s == c && *s)
		s++;
	while (*s)
	{
		words++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (words);
}

void	*rollback(char **tab)
{
	while (*tab)
		free(*tab);
	free(tab);
	return (NULL);
}

char	**write_words(char **tab, const char *s, char c)
{
	size_t	l;
	size_t	i;

	i = 0;
	while (*s)
	{
		l = 0;
		while (s[l] != c && s[l])
			l++;
		tab[i] = (char *) malloc(l * sizeof(char) + 1);
		if (tab[i] == NULL)
			return (rollback(tab));
		tab[i][l] = '\0';
		while (l > 0)
		{
			tab[i][l - 1] = s[l - 1];
			l--;
		}
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;

	words = count_words(s, c);
	tab = (char **) malloc((words + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (*s == c && *s)
		s++;
	tab = write_words(tab, s, c);
	tab[words] = NULL;
	return (tab);
}
