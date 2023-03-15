/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:06:10 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/15 14:40:36 by dbrandao         ###   ########.fr       */
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
	t_task	*task;

	if (in_error())
		return ;
	files = get_files(tokens);
	task = create_task(tokens, files);
	free(task);
	print_files(files);
	clear_files(files);
}

/* SIMPLE AND IMPORTANT!!!
	create task
	exec task

	create exec command task
	exec command task

	create pipe task
	exec pipe task
 */
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

	redirection
		|, >, <, >>
		if (redirection)
			fd = pipe()

 */


/* 

	exec_pipe()
	{
		if (not_pipe)
			return
		exec_command1();
		exec_command2();
		return (output);
	}

	redirect_output(char *output)
	{
		if (not_redirect_output)
			return ;
		write(fd, output, size)
	}

	char	*output;

while (list)
{
	exec_pipe(list)
	redirect_output(list)

}



ter uma struct contendo toda a informação necessária para
a execução de uma tarefa

criar uma função que irá extrair da lista de tokens essas informações
e criar um t_exec item contendo-as

após executar essa tarefa, chamar a função pra extrair a proxima tarefa
e assim por diante

mesmo se nao houver um output da tarefa anterior, o proximo
comando deve ser executado normalmente

exemplo: echo a | echo | cat file1
nesse exemplo nenhum output será passado para cat
mas esse comando ja possui o argumento file1 que será
executado normalmente
e mesmo se nao tivesse nao tem problema
basta executar o comando contendo seu proprio name como argumento

struct typedef	s_exec
{
	char *command1[] -> args
	char *command2[] -> args
	int type -> (PIPE, R_OUT, R_IN, R_AOUT)
	int file_fd;
	char *value;
}	t_exec;

 */