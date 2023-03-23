/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:00:02 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/22 21:37:55 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	close_pipes(int **pipedes)
{
	while (*pipedes)
	{
		close((*pipedes)[0]);
		close((*pipedes)[1]);
		pipedes++;
	}
}

void	pipe_exec(t_list *tokens)
{
	t_pipe	data;

	if (!is_operator(tokens, PIPE))
		return ;
	data.pipedes = get_pipedes(tokens);
	get_commands(tokens);
	//create_commands;
	close_pipes(data.pipedes);
}

/* 
	PLANO NIVEL 1

	is_pipe() //true | false

	contar quantidade de pipes
	mallocar um array pra todos
	abrir todos os pipes

	executar primeiro comando
	{
		filho lê do stdin
		filho escreve no seu pipe
		fechar todos os pipes
	}

	executar comandos do meio
	{
		filho lê do pipe anterior
		filho escreve no seu pipe
		fechar todos os pipes
	}

	executar ultimo comando
	{
		filho lê do pipe anterior
		filho escreve no stdout
		fechar todos os pipes
	}

	fechar todos os pipes
	esperar todos os filhos
	
 */
/* PLANO NIVEL 2

	is_pipe() //true | false

	contar quantidade de pipes
	mallocar um array pra todos
	abrir todos os pipes

	executar primeiro comando
	{
		pegar argumentos do filho
		redirecionar stdout do filho pra escrita do pipe
		fechar todos os pipes
		executar comando
		tratar erro de execução
	}

	executar comandos do meio
	{
		pegar argumentos do comando
		redirecionar stdin do filho pra leitura do pipe anterior
		redirecionar stdout do filho pra escrita do pipe
		fechar todos os pipes
		executar comando
		tratar erro de execução
	}

	executar ultimo comando
	{
		redirecionar stdin do filho pra leitura do pipe anterior
		fechar todos os pipes
		executar comando
		tratar erro de execução
	}

	fechar todos os pipes
	esperar todos os filhos
	
 */