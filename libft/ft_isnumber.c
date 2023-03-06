/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:43:33 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 02:32:24 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	pass_spaces(char **str)
{
	while (ft_isspace(**str))
		(*str)++;
}

static int	is_number(char *str)
{
	if (!str)
		return (0);
	if (ft_issign(*str))
		str++;
	if (!*str)
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (!ft_isspace(*str) && *str != '\0')
		return (0);
	return (1);
}

char	*ft_isnumber(char *str)
{
	if (!str || !*str)
		return (NULL);
	pass_spaces(&str);
	if (!ft_isdigit(*str) && !ft_issign(*str))
		return (NULL);
	if (is_number(str))
		return (str);
	return (NULL);
}
