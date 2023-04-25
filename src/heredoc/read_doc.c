/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:23:07 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
		if (is_endline(end, value))
		{
			free(value);
			break ;
		}
		if (value == NULL)
			break ;
		result = join_and_free(result, value);
	}
	if (result == NULL)
		result = ft_strdup("");
	add_to_tracker(result);
	return (result);
}

static int	child_err(int status)
{
	if (status == 0)
		return (0);
	set_state(-1);
	set_error(130);
	return (1);
}

void	read_fork(char *end)
{
	int		pid;
	int		fd;
	int		status;
	char	*text;

	pid = fork();
	if (pid == 0)
	{
		fd = open(HERE_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		set_sig_here();
		text = get_input(end);
		write(fd, text, ft_strlen(text));
		close(fd);
		mini_exit(0);
	}
	waitpid(pid, &status, WUNTRACED);
	child_err(status);
}
