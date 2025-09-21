#include "algo.h"

void ins_srt(int arr[], int len) {
    int i, current, j;

    for (i = 1; i < len; i++) {
        current = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = current;
    }
}
