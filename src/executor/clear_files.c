/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:27:44 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/14 20:29:03 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	del_file(void *file)
{
	ft_printf("closed %d\n", ((t_file *) file)->fd);
	close(((t_file *) file)->fd);
	free(file);
}

void	clear_files(t_list *files)
{
	ft_lstclear(&files, del_file);
}
