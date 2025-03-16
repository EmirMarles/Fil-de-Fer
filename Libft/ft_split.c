/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:59 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/11 18:07:44 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_mem(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	amount_of_str(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0' && str[i] != '\n') // here ADDED \n; 
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*insert_str(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**insert(char const *s, char c, char **res, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c && s[i] != '\n') // included for the \n && s[i] != '\n'
		{ 
			i++;
			word_len++;
		}
		res[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!res)
			return (free_mem(res, word));
		insert_str(res[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	res[word] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = amount_of_str(s, c);
	res = malloc(sizeof(char *) * (num_words + 1));
	if (!res)
		return (0);
	res = insert(s, c, res, num_words);
	return (res);
}