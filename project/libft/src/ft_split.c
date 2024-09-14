/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:31:14 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/31 17:25:19 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	*ft_free_all(char **s, size_t last)
{
	size_t	i;

	i = 0;
	while (i < last)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static size_t	ft_get_num_tokens(char *s, char c)
{
	size_t	num_tokens;

	num_tokens = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			return (num_tokens);
		while (*s != c && *s != '\0')
		{
			s++;
		}
		num_tokens++;
	}
	return (num_tokens);
}

static size_t	ft_get_word_length(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	return (len);
}

static size_t	ft_jump_to_next_word(const char *str, size_t start, char c)
{
	while (str[start] == c && str[start] != '\0')
		start++;
	return (start);
}

char	**ft_split(char const *s, char c)
{
	char	**tokens;
	size_t	num_tokens;
	size_t	i;
	size_t	start;
	size_t	len;

	num_tokens = ft_get_num_tokens((char *)s, c);
	tokens = (char **)ft_calloc(num_tokens + 1, sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	start = 0;
	i = 0;
	while (i < num_tokens && s[start] != '\0')
	{
		start = ft_jump_to_next_word(s, start, c);
		len = ft_get_word_length(s + start, c);
		if (len > 0)
		{
			tokens[i++] = ft_substr(s, start, len);
			if (tokens[i - 1] == NULL)
				return (ft_free_all(tokens, i - 1));
		}
		start = start + len;
	}
	return (tokens);
}
