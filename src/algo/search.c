#include "algo.h"

int srchlin(int targ, int *arr, int len) {
    for (int i; i < len; i++) {
        if (arr[i] == targ) return i;
    }
    return -1;
}

int srchbin(int targ, int *arr, int len) {
    int high = len - 1, mid, low = 0;

    while (low <= high) {
        mid = (high + low) / 2;

        if (arr[mid] == targ) {
            return mid;
        } else if (arr[mid] < targ) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
