#include "../includes/test.h"
#include "../../src/lexer/lexer.c"

Test(is_operator, truee)
{
	cr_assert(is_operator("<dasdas"));
	cr_assert(is_operator("<"));
	cr_assert(is_operator("< "));
	cr_assert(is_operator("<<dasdas"));
	cr_assert(is_operator(">>dasdas"));
	cr_assert(is_operator(">>"));
	cr_assert(is_operator("<<"));
	cr_assert(is_operator("<< "));
	cr_assert(is_operator(">> "));
	cr_assert(is_operator("| "));
	cr_assert(is_operator("|"));
	cr_assert(is_operator("|dasdsa"));
}

Test(is_operator, falsee)
{
	cr_assert_not(is_operator(" |"));
	cr_assert_not(is_operator("a|"));
	cr_assert_not(is_operator(" <"));
	cr_assert_not(is_operator(""));
	cr_assert_not(is_operator("s"));
	cr_assert_not(is_operator(" "));
	cr_assert_not(is_operator("a>"));
	cr_assert_not(is_operator(" >>"));
	cr_assert_not(is_operator(" |"));
	cr_assert_not(is_operator(NULL));
	cr_assert_not(is_operator(" <<"));
}