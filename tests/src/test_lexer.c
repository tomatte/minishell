#include "../includes/test.h"
#include "../../src/lexer/identify_quotes.c"

/* Test(is_operator, truee)
{
	t_token	*token;

	token = identify_operator("|");
	cr_assert_str_eq("|", token->value);
	cr_assert_eq(OPERATOR, token->type);
	cr_assert_eq(PIPE, token->id);

	token = identify_operator("<<");
	cr_assert_str_eq("<<", token->value);
	cr_assert_eq(OPERATOR, token->type);
	cr_assert_eq(HERE_DOC, token->id);

	token = identify_operator(">>");
	cr_assert_str_eq(">>", token->value);
	cr_assert_eq(OPERATOR, token->type);
	cr_assert_eq(R_APPEND_OUT, token->id);

	token = identify_operator(">");
	cr_assert_str_eq(">", token->value);
	cr_assert_eq(OPERATOR, token->type);
	cr_assert_eq(R_OUTPUT, token->id);

	token = identify_operator("<");
	cr_assert_str_eq("<", token->value);
	cr_assert_eq(OPERATOR, token->type);
	cr_assert_eq(R_INPUT, token->id);
}

Test(is_operator, falsee)
{
	t_token	*token;

	token = identify_operator(" |");
	cr_assert_not(token);

	token = identify_operator("");
	cr_assert_not(token);

	token = identify_operator(".>>");
	cr_assert_not(token);

	token = identify_operator("\n");
	cr_assert_not(token);
} */
/* 
Test(is_quote, truee)
{
	cr_assert(is_quote("'"));
	cr_assert(is_quote("\""));
	cr_assert(is_quote("\" "));
	cr_assert(is_quote("\'"));
}

Test(is_quote, falsee)
{
	cr_assert_not(is_quote(" '"));
	cr_assert_not(is_quote(" \""));
	cr_assert_not(is_quote(NULL));
	cr_assert_not(is_quote(""));
	cr_assert_not(is_quote("a"));
	cr_assert_not(is_quote("\n"));
} */