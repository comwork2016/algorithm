#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/03/08

def quicksort(arr: list, index: list, low, high):
    if low >= high:
        return
    else:
        pivotpos = partition(arr,index, low, high)
        quicksort(arr, index, low, pivotpos - 1)
        quicksort(arr, index, pivotpos + 1, high)


def partition(arr: list, index: list, low, high):
    # chose arr[low] as pivot
    pivot = arr[low]
    pivotindex = index[low]
    i = low
    j = high
    while i < j:
        while i < j and arr[j] < pivot:
            j -= 1
        if i < j:
            #move a[j] to arr[i] and record change in index.
            arr[i] = arr[j]
            index[i] = index[j]
            i += 1
        while i < j and arr[i] > pivot:
            i += 1
        if i < j:
            #move a[i] to arr[j] and record change in index.
            arr[j] = arr[i]
            index[j] = index[i]
            j -= 1
    arr[i] = pivot
    index[i] = pivotindex
    return i
