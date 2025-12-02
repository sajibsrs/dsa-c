#include "algo.h"

int srchlin(int *arr, int size, int targ) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == targ) return i;
    }
    return -1;
}

int srchbin(int *arr, int size, int targ) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (right + left) / 2;

        if (targ == arr[mid]) return mid;
        if (targ > arr[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
