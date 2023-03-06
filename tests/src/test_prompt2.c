#include "../../src/prompt/get_prompt_msg.c"
#include "../includes/test.h"

Test(prompt, join_user_host)
{
	cr_assert_str_eq(join_user_host("max", "joe"), "max@joe:");
	cr_assert_str_eq(join_user_host("max", NULL), "max:");
	cr_assert_str_neq(join_user_host("max", "joe"), "max@joeeee:");
	cr_assert_str_eq(join_user_host("random_user", "random_hostname"), "random_user@random_hostname:");
}

Test(prompt, join_with_dir)
{
	char	*full;

	full = join_with_dir("max@joe:", "~/codes/42/minishell/tests");
	cr_assert_str_eq(full, "max@joe:~/codes/42/minishell/tests$ ");

	cr_assert_str_neq(full, "/codes/42/minishell/tests");

	full = join_with_dir("random_user@random_hostname:", "~/codes/42/minishell/tests");
	cr_assert_str_eq(full, "random_user@random_hostname:~/codes/42/minishell/tests$ ");
}