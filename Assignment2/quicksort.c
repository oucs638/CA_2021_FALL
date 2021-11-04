#include <stdio.h>
#include <stdlib.h>

void print_nums(int *nums, int n)
{
    volatile char *tx = (volatile char *) 0x40002000;
    for (int i = 0; i < n; i++) {
        *tx = nums[i] + '0';
        if (i == (n - 1))
            *tx = '\n';
        else
            *tx = ' ';
    }
}

void print_str(int mode)
{
    volatile char *tx = (volatile char *) 0x40002000;
    if (mode == 0) {
        const char *str0 = "\nThe nums before sorting:\n";
        while (*str0) {
            *tx = *str0;
            str0++;
        }
    } else if (mode == 1) {
        const char *str1 = "\nThe nums after sorting:\n";
        while (*str1) {
            *tx = *str1;
            str1++;
        }
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *nums, int l, int r)
{
    swap(&nums[(l + r) / 2], &nums[r]);
    int p = l;

    for (int i = l; i < r; i++) {
        if (nums[i] < nums[r]) {
            swap(&nums[i], &nums[p]);
            p++;
        }
    }

    swap(&nums[p], &nums[r]);
    return p;
}

void quicksort(int *nums, int l, int r)
{
    if (l >= r)
        return;

    int p = partition(nums, l, r);
    quicksort(nums, l, p - 1);
    quicksort(nums, p + 1, r);
}

void _start()
{
    int nums[] = {5, 7, 3, 1, 9, 2, 4};
    int n = 7;

    print_str(0);
    print_nums(nums, n);
    quicksort(nums, 0, n - 1);
    print_str(1);
    print_nums(nums, n);
}
