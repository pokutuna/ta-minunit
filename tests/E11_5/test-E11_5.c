#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "minunit.h"

int mu_nfail = 0; int mu_ntest = 0; int mu_nassert = 0;

// prototypes
typedef struct complex {
    double re;
    double im;
} complex_t;

complex_t complex_add(complex_t a, complex_t b);
complex_t complex_mul(complex_t a, complex_t b);

complex_t my_add(complex_t a, complex_t b)
{
    complex_t dest;
    dest.re = a.re + b.re;
    dest.im = a.im + b.im;
    return dest;
}

complex_t my_mul(complex_t a, complex_t b)
{
    complex_t dest;
    dest.re = a.re * b.re - a.im * b.im;
    dest.im = a.re * b.im + b.re * a.im;
    return dest;
}

int in_delta(double num, double expect)
{
    double delta = 0.001;
    return (expect - delta) <= num && num <= (expect + delta);
}

int assert_complex(complex_t a, complex_t b)
{
    return in_delta(a.re, b.re) && in_delta(a.im, b.im);
}

complex_t random_complex(void)
{
    complex_t c;
    c.re = (double)rand() / (double)RAND_MAX;
    c.im = (double)rand() / (double)RAND_MAX;
    return c;
}

static char* test_mul()
{
    int i;
    complex_t orig;
    complex_t test;

    complex_t a = { 1.5, 2.1 };
    complex_t b = { 0.3, -2.5 };
    orig = complex_mul(a, b);
    test = my_mul(a, b);
    mu_assert(assert_complex(orig, test));


    for (i = 0; i < 5; i++) {
        a = random_complex();
        b = random_complex();
        orig = complex_mul(a, b);
        test = my_mul(a, b);
        mu_assert(assert_complex(orig, test));
    }

    return 0;
}

static char* test_add()
{
    int i;
    complex_t orig;
    complex_t test;

    complex_t a = { 1.5, 2.1 };
    complex_t b = { 0.3, -2.5 };
    orig = complex_add(a, b);
    test = my_add(a, b);
    mu_assert(assert_complex(orig, test));

    for (i = 0; i < 5; i++) {
        a = random_complex();
        b = random_complex();
        orig = complex_add(a, b);
        test = my_add(a, b);
        mu_assert(assert_complex(orig, test));
    }

    return 0;
}

static char* all_tests()
{
    srand((unsigned int) time(NULL));
    mu_run_test(test_add);
    mu_run_test(test_mul);
    return 0;
}

int main(int argc, char **argv) {
    all_tests();
    mu_show_failures();
    return mu_nfail != 0;
}
