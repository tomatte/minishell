/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:23:07 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/15 13:48:22 by dbrandao         ###   ########.fr       */
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

static char	*get_input(char *end)
{
	char	*result;
	char	*value;

	result = NULL;
	while (1)
	{
		ft_putstr("> ");
		value = get_next_line(STDIN_FILENO);
		if (value == NULL || is_endline(end, value))
			break ;
		result = join_and_free(result, value);
	}
	if (result == NULL)
		result = ft_strdup("");
	add_to_tracker(result);
	return (result);
}

static char	*read_fork(char *end)
{
	int		pid;
	int		pipedes[2];
	char	*text;

	pipe(pipedes);
	pid = fork();
	if (pid == 0)
	{
		text = get_input(end);
		close(pipedes[R]);
		write(pipedes[W], text, ft_strlen(text) + 1);
		close(pipedes[W]);
		mini_exit(0);
	}
	else
	{
		waitpid(pid, NULL, WUNTRACED);
		close(pipedes[W]);
		text = read_all(pipedes[R]);
		close(pipedes[R]);
	}
	return (text);
}

t_list	*read_doc(t_token *here_end)
{
	t_list	*args;
	char	*text;

	text = read_fork(here_end->value);
	args = extract_tokens(text);
	return (args);
}
