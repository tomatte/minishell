/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:06:10 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/24 16:24:26 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_files(t_list *files)
{
	t_file	*file;

	while (files)
	{
		file = (t_file *) files->content;
		ft_printf("%d ", file->id);
		files = files->next;
	}
	ft_printf("\n");
}

static int	verify_error(void)
{
	if (in_error())
	{
		ft_printf("EXEC ERROR\n");
		return (1);
	}
	return (0);
}

void	executor(t_list *tokens, char **envp)
{
	t_list	*files;

	if (in_error())
		return ;
	files = get_files(tokens);
	pipe_exec(tokens, envp);
	clear_files(files);
	while (wait(NULL) != -1)
		;
}
