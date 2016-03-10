#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/03/08

def sortedgeasc(edge: dict):
    "sort edge asc"
    elist = []  # edge list
    wlist = []  # weight list
    for vi in edge:
        for vj in edge[vi]:
            if {vi: vj} not in elist and {vj: vi} not in elist and edge[vi]:
                elist.append({vi: vj})
                wlist.append(edge[vi][vj])
    quicksort(wlist, elist, 0, len(elist) - 1)
    return elist



def quicksort(arr: list, notelist: list, low, high):
    if low >= high:
        return
    else:
        pivotpos = partition(arr, notelist, low, high)
        quicksort(arr, notelist, low, pivotpos - 1)
        quicksort(arr, notelist, pivotpos + 1, high)


def partition(arr: list, notelist: list, low, high):
    # chose arr[low] as pivot
    pivot = arr[low]
    notepivot = notelist[low]
    i = low
    j = high
    while i < j:
        while i < j and arr[j] > pivot:
            j -= 1
        if i < j:
            # move a[j] to arr[i]
            arr[i] = arr[j]
            notelist[i] = notelist[j]
            i += 1
        while i < j and arr[i] < pivot:
            i += 1
        if i < j:
            # move a[i] to arr[j]
            arr[j] = arr[i]
            notelist[j] = notelist[i]
            j -= 1
    arr[i] = pivot
    notelist[i] = notepivot
    return i
