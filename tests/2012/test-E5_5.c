#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "minunit.h"

int mu_nfail = 0; int mu_ntest = 0; int mu_nassert = 0;

int polynomial(int);

int my_polynomial(int x) {
  return 2 * x * x - 5 * x + 3;
}

static char* test_basic()
{
  int i, x;
  for (i = 0; i < 10; i++) {
    int x = (int)rand() % 100;
    mu_assert(polynomial(x) == my_polynomial(x));
  }
  return 0;
}

static char* test_edge()
{
  mu_assert(polynomial(0) == my_polynomial(0));
  mu_assert(polynomial(-1) == my_polynomial(-1));
  mu_assert(polynomial(INT_MAX) == my_polynomial(INT_MAX));
  return 0;
}

static char* all_tests()
{
  mu_run_test(test_basic);
  mu_run_test(test_edge);
  return 0;
}

int main(int argc, char **argv) {
  srand((unsigned)time(NULL));

  all_tests();
  mu_show_failures();
  return mu_nfail != 0;
}
