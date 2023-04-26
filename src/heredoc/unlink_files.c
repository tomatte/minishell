/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:53:43 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/26 11:02:54 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*get_here_filename(int num)
{
	char	*filename;
	char	*number;

	number = ft_itoa(num);
	filename = ft_strjoin(HERE_FILE, number);
	free(number);
	add_to_tracker(filename);
	return (filename);
}

void	unlink_files(void)
{
	char	*filename;
	int		num;

	num = 0;
	while (1)
	{
		filename = get_here_filename(num);
		if (access(filename, F_OK) == 0)
			unlink(filename);
		else
			break ;
		num++;
	}
}
