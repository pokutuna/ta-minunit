#include <stdio.h>
#include "minunit.h"

int mu_nfail = 0; int mu_ntest = 0; int mu_nassert = 0;

/* TODO: テストしたい関数のプロトタイプを書く*/
// int func(int);

static char* test_one()
{
    /* TODO: 関数の返り値と、期待する値を検査する */
    // mu_assert(func(1) == 1);
    return 0;
}

static char* test_two()
{
    return 0;
}

static char* all_tests()
{
    /* TODO 各テストを呼ぶ、ここで mu_assert を呼びまくってもいい */
    mu_run_test(test_one);
    mu_run_test(test_two);
    return 0;
}

int main(int argc, char **argv) {
    all_tests();
    mu_show_failures();
    return mu_nfail != 0;
}
