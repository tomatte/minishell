/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:06:10 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/14 20:07:25 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	executor(t_list *tokens)
{
	int	pid;
	int	fd[2];

	(void) pid;
	(void) fd;
	if (in_error())
		return ;
	files_action(tokens);
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