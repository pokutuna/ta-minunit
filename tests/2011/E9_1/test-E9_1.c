#include <stdio.h>
#include <math.h>
#include "minunit.h"

#define SIZE 5

int mu_nfail = 0; int mu_ntest = 0; int mu_nassert = 0;

// test functions
double average(double[]);
double variance(double[]);
double standard_deviation(double[]);

// samples
double example1[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
double example2[] = { 2.0, 2.0, 2.0, 2.0, 2.0 };
double example3[] = { 0.0, 10.0, 0.0, 10.0, 0.0};
double example4[] = { 0.0, 0.0, 0.0, 0.0, 0.0};

static int in_delta(double num, double expect)
{
    double delta = 0.001;
    return (expect - delta) <= num && num <= (expect + delta);
}

double my_average(double nums[])
{
    int i;
    double buf = 0.0;
    for (i = 0; i < SIZE; i++) {
        buf += nums[i];
    }
    return buf / SIZE;
}

double my_variance(double nums[])
{
    int i;
    double buf = 0.0;
    double average = my_average(nums);
    for (i = 0; i < SIZE; i++) {
        buf += pow(nums[i] - average, 2.0);
    }
    return buf / SIZE;
}

double my_standard_deviation(double nums[])
{
    return sqrt(my_variance(nums));
}



static char* test_average()
{
    mu_assert(in_delta(average(example1), my_average(example1)));
    mu_assert(in_delta(average(example2), my_average(example2)));
    mu_assert(in_delta(average(example3), my_average(example3)));
    mu_assert(in_delta(average(example4), my_average(example4)));
    return 0;
}

static char* test_variance()
{
    mu_assert(in_delta(variance(example1), my_variance(example1)));
    mu_assert(in_delta(variance(example2), my_variance(example2)));
    mu_assert(in_delta(variance(example3), my_variance(example3)));
    mu_assert(in_delta(variance(example4), my_variance(example4)));
    return 0;
}

static char* test_standard_deviation()
{
    mu_assert(in_delta(standard_deviation(example1), my_standard_deviation(example1)));
    mu_assert(in_delta(standard_deviation(example2), my_standard_deviation(example2)));
    mu_assert(in_delta(standard_deviation(example3), my_standard_deviation(example3)));
    mu_assert(in_delta(standard_deviation(example4), my_standard_deviation(example4)));
    return 0;
}

static char* all_tests()
{
    mu_run_test(test_average);
    mu_run_test(test_variance);
    mu_run_test(test_standard_deviation);
    return 0;
}

int main(int argc, char **argv) {
    all_tests();
    mu_show_failures();
    return mu_nfail != 0;
}
