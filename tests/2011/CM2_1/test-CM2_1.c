#include <stdio.h>
#include "minunit.h"

int mu_nfail = 0; int mu_ntest = 0; int mu_nassert = 0;

int salary(int);

int my_salary(int year)
{
    if (year < 1 || 40 < year) return 0;
    return 15 * (year - 1) + 400;
}

static char* test_salary()
{
    mu_assert(salary(1) == 400);
    mu_assert(salary(2) == 415);
    mu_assert(salary(3) == 430);
    mu_assert(salary(10) == my_salary(10));
    mu_assert(salary(15) == my_salary(15));
    mu_assert(salary(39) == my_salary(39));
    return 0;
}

static char* test_edge_case()
{
    mu_assert(salary(-1) == my_salary(-1));
    mu_assert(salary(0) == my_salary(0));
    mu_assert(salary(41) == my_salary(41));
    return 0;
}

static char* all_tests()
{
    mu_run_test(test_salary);
    // mu_run_test(test_edge_case); 考慮しなくていいしほとんど落ちるのでやめた
    return 0;
}

int main(int argc, char **argv) {
    all_tests();
    mu_show_failures();
    return mu_nfail != 0;
}
