#include <stdio.h>
#include <math.h>
#include "minunit.h"

#define N 10000

int mu_nfail = 0; int mu_ntest = 0; int mu_nassert = 0;

// test functions
void sequence(int, int, int[]);

void my_sequence(int n, int x, int dest[])
{
    int i;
    for (i = 1; i <= n; i++) {
        if (i == 1) {
            dest[i] = x;
        } else {
            dest[i] = next_val(dest[i-1]);
        }
    }
    return;
}

int next_val(int a)
{
    return 2 * a + 1;
}

int seq_equals(int n, int a[], int b[])
{
    int i;
    for (i = 1; i <= n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

void clear_array(int ary[])
{
    int i;
    for (i = 0; i < N; i++) {
        ary[i] = 0;
    }
    return;
}

static char* test_sequence()
{
    int orig[N];
    int test[N];

    sequence(10, 10, orig);
    my_sequence(10, 10, test);
    mu_assert(seq_equals(10, orig, test));
    clear_array(orig);
    clear_array(test);

    sequence(10, 0, orig);
    my_sequence(10, 0, test);
    mu_assert(seq_equals(10, orig, test));
    clear_array(orig);
    clear_array(test);

    sequence(5, 1, orig);
    my_sequence(5, 1, test);
    mu_assert(seq_equals(5, orig, test));
    clear_array(orig);
    clear_array(test);

    return 0;
}

static char* test_sequence_edge()
{
    int orig[N];
    int test[N];

    sequence(1, 0, orig);
    my_sequence(1, 0, test);
    mu_assert(seq_equals(1, orig, test));
    clear_array(orig);
    clear_array(test);

    sequence(0, 0, orig);
    my_sequence(0, 0, test);
    mu_assert(seq_equals(0, orig, test));
    clear_array(orig);
    clear_array(test);

    sequence(1000, 0, orig);
    my_sequence(1000, 0, test);
    mu_assert(seq_equals(1000, orig, test));
    clear_array(orig);
    clear_array(test);

    return 0;
}

static char* all_tests()
{
    mu_run_test(test_sequence);
    mu_run_test(test_sequence_edge);
    return 0;
}

int main(int argc, char **argv) {
    all_tests();
    mu_show_failures();
    return mu_nfail != 0;
}
