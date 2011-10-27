#include <stdio.h>
#include "minunit.h"

int cubic(int); // (1) テストしたい関数のプロトタイプ

int mu_nfail = 0; int mu_ntest = 0; int mu_nassert = 0;

static char* test_cubic()
{
    mu_assert(cubic(2) == 8);
    mu_assert(cubic(5) == 125);
    mu_assert(cubic(100) == 1000000);
    return 0;
}

static char* test_cubic_edge_case()
{
    mu_assert(cubic(0) == 0);
    mu_assert(cubic(-1) == -1);
}

static char* all_tests()
{
    mu_run_test(test_cubic);
    mu_run_test(test_cubic_edge_case);
    return 0;
}

int main(int argc, char **argv) {
    all_tests();
    mu_show_failures();
    return mu_nfail != 0;
}

