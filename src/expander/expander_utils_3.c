/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:20:06 by kchatela          #+#    #+#             */
/*   Updated: 2025/12/05 17:24:20 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	escape_quotes(char *quoted_text, char *escaped)
{
	size_t	n;
	size_t	k;

	n = 0;
	k = 0;
	while (quoted_text[n])
	{
		if (quoted_text[n] == '"' || quoted_text[n] == '\'')
			escaped[k++] = '\x1f';
		escaped[k++] = quoted_text[n];
		n++;
	}
	escaped[k] = '\0';
}

size_t	handle_single_quote(const char *str, size_t i, char **res)
{
	size_t	j;
	char	*quoted_text;
	char	*escaped;

	j = i + 1;
	while (str[j] && str[j] != '\'')
		j++;
	quoted_text = ft_substr(str, i + 1, j - i - 1);
	escaped = malloc(ft_strlen(quoted_text) * 2 + 1);
	if (!escaped)
		return (j + 1);
	escape_quotes(quoted_text, escaped);
	append_and_free(res, escaped);
	free(escaped);
	free(quoted_text);
	if (str[j] == '\'')
		i = j + 1;
	else
		i = j;
	return (i);
}
