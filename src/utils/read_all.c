/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:52:44 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*join_and_free(char *s1, char *s2)
{
	char	*result;

	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	result = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (result);
}

char	*read_all(int fd)
{
	char	*str;
	char	*aux;

	str = NULL;
	while (1)
	{
		aux = get_next_line(fd);
		if (!aux)
			return (str);
		str = join_and_free(str, aux);
	}
}
