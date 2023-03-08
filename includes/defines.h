#ifndef DEFINES_H
# define DEFINES_H

//TO BE USED AS TYPES AND STATES
# define NONE 0
# define WORD 1
# define OPERATOR 2
# define EXPANSIVE 3
# define QUOTE 4

//WORD
# define BUILTIN 0
# define PATH_PROG 1
# define FILE_PROG 2
# define ARG 3
# define DELIMITER "$'\"<|>"

//QUOTE
# define SIMPLE_QUOTES 0
# define DOUBLE_QUOTES 1

//EXPANSIVE
# define ENV_VAR 0
# define EXIT_STAT 1

//OPERATOR
# define HERE_DOC 0
# define R_APPEND_OUT 1
# define R_INPUT 2
# define R_OUTPUT 3
# define PIPE 4

# define OP_NUM 5

//ERRORS
# define ERR_UNCLOSED_QUOTES -2

#endif