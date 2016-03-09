#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/03/08

def quicksort(arr: list, low, high):
    if low >= high:
        return
    else:
        pivotpos = partition(arr, low, high)
        quicksort(arr, low, pivotpos - 1)
        quicksort(arr, pivotpos + 1, high)


def partition(arr: list, low, high):
    # chose arr[low] as pivot
    pivot = arr[low]
    i = low
    j = high
    while i < j:
        while i < j and arr[j] > pivot:
            j -= 1
        if i < j:
            arr[i] = arr[j]
            i += 1
        while i < j and arr[i] < pivot:
            i += 1
        if i < j:
            arr[j] = arr[i]
            j -= 1
    arr[i] = pivot
    return i


if __name__ == '__main__':
    arr = [60, 70, 75, 80, 85, 60, 55, 50, 45]
    # arr = [60, 70, 75, 80, 85, 60, 55, 50, 45]
    quicksort(arr, 0, len(arr) - 1)
    print("quicksorted arr:", arr)
