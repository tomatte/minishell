#ifndef DEFINES_H
# define DEFINES_H

//TO BE USED AS TYPES AND STATES
# define NONE 0
# define START 1
# define WORD 2
# define OPERATOR 3
# define EXPANSIVE 4
# define QUOTE 5

//WORD
# define EXEC 0
# define ARG 1
# define FILE 2
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