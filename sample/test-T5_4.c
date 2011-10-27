#include <stdio.h>
#include "minunit.h"

int mu_nfail = 0; int mu_ntest = 0; int mu_nassert = 0;

int cubic(int); // (1) テストしたい関数のプロトタイプ

static char* test_cubic() // (2) 1つ目のテスト
{
    mu_assert(cubic(2) == 8); // (2) アサーション
    mu_assert(cubic(5) == 125);
    mu_assert(cubic(100) == 1000000);
    return 0;
}

static char* test_cubic_edge_case() // (2) 2つ目のテスト
{
    mu_assert(cubic(0) == 0);
    mu_assert(cubic(-1) == -1);
}

static char* all_tests()
{
    // (3) テスト関数を呼ぶ
    mu_run_test(test_cubic);
    mu_run_test(test_cubic_edge_case);
    return 0;
}

int main(int argc, char **argv) {
    all_tests();
    mu_show_failures();
    return mu_nfail != 0;
}

