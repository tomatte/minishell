/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:23:07 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/14 22:52:00 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_endline(char *here_end, char *value)
{
	if (ft_strncmp(here_end, value, ft_strlen(here_end)) != 0)
		return (0);
	if (ft_streq("\n", &(value[ft_strlen(here_end)])))
		return (1);
	return (0);
}

static char	*get_input(void)
{
	char	*value;
	int		pid;
	int		pipedes[2];

	pipe(pipedes);
	pid = fork();
	if (pid == 0)
	{
		ft_printf("> ");
		value = get_next_line(STDIN_FILENO);
		close(pipedes[R]);
		write(pipedes[W], value, ft_strlen(value) + 1);
		close(pipedes[W]);
		free(value);
		mini_exit(0);
		return (NULL);
	}
	else
	{
		close(pipedes[W]);
		value = get_next_line(pipedes[R]);
		close(pipedes[R]);
		return (value);
	}
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
		if (is_endline(here_end->value, value))
		{
			free(value);
			break ;
		}
		arg = new_token(value, WORD, ARG);
		ft_lstadd_back(&args, lstnew_track(arg));
	}
	return (args);
}
