#include "../includes/test.h"

Test(state, get_and_set)
{
	cr_assert_eq(get_state(), 0);

	set_state(2);
	cr_assert_neq(get_state(), 0);
	cr_assert_eq(get_state(), 2);

	set_state(-1);
	cr_assert_eq(get_state(), 2);

	set_state(1);
	cr_assert_eq(get_state(), 1);
}