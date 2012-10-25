#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "minunit.h"

int mu_nfail = 0; int mu_ntest = 0; int mu_nassert = 0;

int num_days(int, int);

// for test
int get_day(int month)
{
    int mdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month < 1 || 12 < month) return -1;
    return mdays[month % 13 - 1];
}

int my_num_days(int month, int day)
{
    if (get_day(month) < day) return -1; // validate date
    if (day < 25) return 25 - day + 1;
    else {
        return (get_day(month) - day) + 25 + 1;
    }
}


static char* test_num_days_under_25()
{
    mu_assert(num_days(5, 21) == 5);
    mu_assert(num_days(1, 1) == 25);
    mu_assert(num_days(1, 24) == 2);
    mu_assert(num_days(2, 21) == 5);
    mu_assert(num_days(1, 10) == 16);
    return 0;
}

static char* test_num_days_over_25()
{
    mu_assert(num_days(7, 25) == 32);
    mu_assert(num_days(2, 28) == 26);
    mu_assert(num_days(12, 31) == 26);
    mu_assert(num_days(2, 25) == 29);
    mu_assert(num_days(9, 30) == 26);
    return 0;
}

static char* test_random_days()
{
    srand((unsigned int) time(NULL));
    int i, random_month, random_day;
    for (i = 0; i < 5; i++) {
        random_month = rand() % 12 + 1;
        random_day = rand() % 31 + 1;
        if (get_day(random_month) < random_day) continue;

        mu_assert(num_days(random_month, random_day) == my_num_days(random_month, random_day));
    }
    return 0;
}

static char* all_tests()
{
    mu_run_test(test_num_days_under_25);
    mu_run_test(test_num_days_over_25);
    mu_run_test(test_random_days);
    return 0;
}

int main(int argc, char **argv) {
    all_tests();
    mu_show_failures();
    return mu_nfail != 0;
}
