#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/03/09

from greedy.knapsack import quicksort


def knapsack(w: list, p: list, m, x: list):
    arr = []
    index = []  # record the origin position of arr
    for i in range(len(w)):
        arr.append(p[i] / w[i])
        index.append(i)
    quicksort.quicksort(arr, index, 0, len(arr) - 1)
    print("des sorted list index is ", index)
    mc = m #rest m
    tp = 0 #total p
    for i in range(len(index)):
        si = index[i]  # sorted list index
        if mc < w[si]:
            break
        mc = mc - w[si]
        tp = tp + p[si]
        x[si] = 1
    if i <= len(index):
        si = index[i]
        x[si] = mc / w[si]
        tp = tp + p[si]*x[si]
    return tp

if __name__ == '__main__':
    w = [18, 15, 10]
    p = [25, 24, 15]
    m = 20
    x = [0] * len(w)
    tp = knapsack(w, p, m, x)
    print("total p is %f"%(tp))
    print("x list is",x)
