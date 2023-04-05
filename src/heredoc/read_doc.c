/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:23:07 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/05 18:26:10 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	remove_line(char *str)
{
	int	len;

	if (str == NULL)
		return ;
	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
}

static char	*get_input(void)
{
	char	*value;

	value = get_next_line(STDIN_FILENO);
	remove_line(value);
	return (value);
}

t_list	*read_doc(t_token *here_end)
{
	t_list	*args;
	t_token	*arg;
	char	*value;

	args = NULL;
	while (1)
	{
		value = get_input();
		if (ft_streq(value, here_end->value))
		{
			free(value);
			break ;
		}
		arg = new_token(value, WORD, ARG);
		ft_lstadd_back(&args, lstnew_track(arg));
	}
	return (args);
}
