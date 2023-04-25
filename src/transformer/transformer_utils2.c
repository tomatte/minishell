/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:23:51 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_opening_quote(char *str)
{
	while (*str && !is_quote(*str))
		str++;
	return (str);
}

char	*get_closing_quote(char *s, char quote)
{
	s++;
	while (*s != quote)
		s++;
	return (s);
}

void	move_quote_left(char *str, char *start)
{
	char	c;

	while (str > start)
	{
		c = *(str - 1);
		*(str - 1) = *str;
		*str = c;
		str--;
	}
	*str = UNIT_SEPARATOR;
}

void	move_quote_right(char *s, char **str, char *end)
{
	char	c;

	while (s < end - 1)
	{
		c = *(s + 1);
		*(s + 1) = *s;
		*s = c;
		s++;
	}
	*s = UNIT_SEPARATOR;
	*str = (end);
}
