#include <stdio.h>
#include <math.h>
#include "minunit.h"

int mu_nfail = 0; int mu_ntest = 0; int mu_nassert = 0;

// test target
double myexp(double);


double fact(double i)
{
    return i == 1 ? 1.0 : i * fact(i - 1.0);
}

double calc_clause(double x, int k)
{
    return k == 0 ? 1 : pow(x, k) / fact(k);
}

double expect_myexp(double x)
{
    int k = 0;
    double threshold = pow(10, -6);
    double result = 0.0;

    while (1) {
        double num = calc_clause(x, k);
        if (num < threshold) break;
        result += num;
        k++;
    }
    return result;
}

static int in_delta(double num, double expect)
{
    double delta = 0.001;
    return (expect - delta) <= num && num <= (expect + delta);
}

static char* test_example()
{
    mu_assert(in_delta(myexp(1.0), 2.71828));
    mu_assert(in_delta(myexp(2.0), 7.38906));
    mu_assert(in_delta(myexp(3.0), 20.08554));
    mu_assert(in_delta(myexp(4.0), 54.59815));
    mu_assert(in_delta(myexp(5.0), 148.41316));
    mu_assert(in_delta(myexp(6.0), 403.42879));
    mu_assert(in_delta(myexp(7.0), 1096.63316));
    mu_assert(in_delta(myexp(8.0), 2980.95799));
    mu_assert(in_delta(myexp(9.0), 8103.08393));
    mu_assert(in_delta(myexp(10.0), 22026.46579));
    return 0;
}

static char* test_more()
{
    mu_assert(in_delta(myexp(0.0), expect_myexp(0.0)));
    mu_assert(in_delta(myexp(15.0), expect_myexp(15.0)));
    mu_assert(in_delta(myexp(1.1), expect_myexp(1.1)));
    mu_assert(in_delta(myexp(3.3), expect_myexp(3.3)));
    mu_assert(in_delta(myexp(6.6), expect_myexp(6.6)));
    return 0;
}

static char* all_tests()
{
    mu_run_test(test_example);
    mu_run_test(test_more);
    return 0;
}

int main(int argc, char **argv) {
    all_tests();
    mu_show_failures();
    return mu_nfail != 0;
}
