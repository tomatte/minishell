#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_token
{
	char	*value;
	int		type;
	int		id;
}	t_token;

typedef struct s_file
{
	int		fd;
	int		id;
	char	*name;
}	t_file;

typedef struct s_task
{
	char	**args1;
	char	**args2;
	int		type;
	int		file_fd;
	char	*value;
}	t_task;

#endif