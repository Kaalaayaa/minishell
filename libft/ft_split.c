/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:37:59 by kchatela          #+#    #+#             */
/*   Updated: 2024/11/28 16:24:48 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0')
		{
			count++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
	}
	return (count);
}

static char	*get_word(const char **s, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = 0;
	while ((*s)[i] == c)
		i++;
	while ((*s)[i + len] && (*s)[i + len] != c)
		len++;
	if (len == 0)
		return (NULL);
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, &(*s)[i], len + 1);
	*s = &(*s)[i + len];
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		i;
	char	**result;

	words = count_words(s, c);
	i = 0;
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (i < words)
	{
		result[i] = get_word(&s, c);
		if (!result[i])
		{
			while (i-- > 0)
			{
				free(result[i]);
			}
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

/*#include <stdio.h>

int main(void)
{
	char s[] = "Kalaya Laila Bim Chatelain";
	char **result = ft_split(s, ' ');  // Call the split function

// Iterate through the array of strings and print each one
	int i = 0;
	while (result[i] != NULL)
	{
    	printf("%s\n", result[i]);  // Print each word followed by a new line
   		i++;
	}
}*/
