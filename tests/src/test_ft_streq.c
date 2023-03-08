#include "../includes/test.h"

Test(ft_streq, equals)
{
	cr_assert(ft_streq("eba", "eba"));
	cr_assert(ft_streq("", ""));
	cr_assert(ft_streq("da siudh uiasghdiu ", "da siudh uiasghdiu "));
	cr_assert(ft_streq("1", "1"));
	cr_assert(ft_streq(" ", " "));
	cr_assert(ft_streq(NULL, NULL));
}

Test(ft_streq, not_eq)
{
	cr_assert_not(ft_streq("uva verde", "uva"));
	cr_assert_not(ft_streq("uva", "uva verde"));
	cr_assert_not(ft_streq("uva", NULL));
	cr_assert_not(ft_streq(NULL, "uva"));
	cr_assert_not(ft_streq("a", ""));
	cr_assert_not(ft_streq("", "a"));
	cr_assert_not(ft_streq(NULL, ""));
	cr_assert_not(ft_streq("", NULL));
}