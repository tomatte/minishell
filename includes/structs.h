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

typedef struct s_command
{
	char	**args;
	int		input_fd;
	int		output_fd;
	int		pid;
	int		status;
}	t_command;

typedef struct s_exp
{
	char	*value;
	char	*name;
	char	*start;
	char	*end;
	int		len;
}	t_exp;


#endif
