#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/03/08

"""
归并分类
给定一个含有n个元素的集合,把它们按一定的次序分类(按非降次序分类)
"""


def mergesort(arr: list, low, high):
    if low >= high:
        return
    else:
        mid = int((low + high) / 2)
        mergesort(arr, low, mid)
        mergesort(arr, mid + 1, high)
        mergesorted(arr, low, high)


def mergesorted(arr: list, low, high):
    mid = int((low + high) / 2)
    templist = []
    i = low
    j = mid + 1
    while i <= mid and j <= high:
        if arr[i] <= arr[j]:
            templist.append(arr[i])
            i += 1
        else:
            templist.append(arr[j])
            j += 1
    # one of the half list was put into the templist, then expend rest of another on to templist.
    if i <= mid:
        templist.extend(arr[i:mid + 1])
    elif j <= high:
        templist.extend(arr[j:high + 1])
    #copy sorted list to arr.
    for index in range(len(templist)):
        arr[low + index] = templist[index]


if __name__ == '__main__':
    arr = [310, 285, 179, 652, 351, 423, 861, 254, 450, 520]
    mergesort(arr, 0, len(arr) - 1)
    print("sorted arr:", arr)
