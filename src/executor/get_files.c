/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:39:41 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/14 22:14:13 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_list	*get_files_list(t_list *tokens)
{
	t_list	*files;
	t_file	*file;
	t_token	*token;

	files = NULL;
	while (tokens)
	{
		token = (t_token *) tokens->content;
		if (token->id == IN_FILE || token->id == OUT_FILE)
		{
			file = (t_file *) malloc(sizeof(t_file));
			file->id = token->id;
			file->name = token->value;
			ft_lstadd_back(&files, ft_lstnew(file));
		}
		tokens = tokens->next;
	}
	return (files);
}

static int	open_file(t_file *file)
{
	int	fd;

	if (file->id == OUT_FILE)
	{
		fd = open(file->name, O_WRONLY);
		if (fd < 0)
			fd = creat(file->name, 00664);
		if (fd < 0)
			set_state(CREATE_FILE_ERROR);
	}
	else
	{
		fd = open(file->name, O_RDONLY);
		if (fd < 0)
			set_state(OPEN_FILE_ERROR);
	}
	return (fd);
}

static void	open_files(t_list *files)
{
	t_file	*file;
	int		fd;

	while (files)
	{
		file = (t_file *) files->content;
		fd = open_file(file);
		file->fd = fd;
		files = files->next;
	}
}

t_list	*get_files(t_list *tokens)
{
	t_list	*files;

	files = get_files_list(tokens);
	open_files(files);
	return (files);
}