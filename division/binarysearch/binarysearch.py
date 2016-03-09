#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/03/08

def binarysearch(arr: tuple, t):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = int((low + high) / 2)
        if arr[mid] == t:
            return mid
        elif arr[mid] > t:
            high = high - 1
        else:
            low = low + 1
    if low > high:
        return -1


if __name__ == '__main__':
    arr = (-15, -6, 0, 7, 9, 23, 54, 82, 101)
    t = 101
    index = binarysearch(arr, t)
    if index == -1:
        print("%s not found in arr!"%(t))
    else:
        print("%s is the %sth number of arr!"%(t,index+1))
