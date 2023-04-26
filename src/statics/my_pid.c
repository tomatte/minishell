/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:37:33 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/26 12:40:42 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	*spid(void)
{
	static int	pid = 1;

	return (&pid);
}

void	set_my_pid(int pid)
{
	int	*mypid;

	mypid = spid();
	*mypid = pid;
}

int	get_my_pid(void)
{
	int	*mypid;

	mypid = spid();
	return (*mypid);
}
