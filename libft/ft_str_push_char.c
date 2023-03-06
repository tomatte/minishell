/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_push_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:16:41 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/12 15:18:01 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_str_push_char(char **str, char c)
{
	size_t	len;
	char	*s;
	char	*new;

	s = *str;
	if (!str || !s || !c)
		return ;
	len = ft_strlen(s);
	new = (char *) malloc(len + 2);
	if (!new)
		return ;
	ft_strlcpy(new, s, len + 1);
	new[len] = c;
	new[len + 1] = '\0';
	free(s);
	*str = new;
}
