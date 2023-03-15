/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:06:10 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/14 22:10:11 by dbrandao         ###   ########.fr       */
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

void	executor(t_list *tokens)
{
	t_list	*files;

	if (in_error())
		return ;
	files = get_files(tokens);
	print_files(files);
	clear_files(files);
}

/* primeiramente lidar com os arquivos:
	files_action
	{
		pegar todos os tokens do tipo file e armazenar numa lista
		se for out_file e precisar, criar o arquivo
		abrir todos os arquivos e armazenar o fd
		fazer função pra fechar todos os arquivos depois
	}

	criar um executor pro pipe
	criar um executor pros redirections
	criar um executor pro here_doc

 */