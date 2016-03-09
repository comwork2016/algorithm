#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/03/09

"""
带有限期的作业排序
"""

from greedy.jobsort import quicksort


def jobsort(p: list, d: list, x: list):
    index = []  # record the origin position of arr
    for i in range(len(p)):
        index.append(i)
    temp = list(p)
    quicksort.quicksort(temp, index, 0, len(p) - 1)
    print("des sorted list index is", index)
    tp = 0
    for i in range(len(index)):
        si = index[i]  # sorted p index in origin list
        li = findsmallerindex(x, d[si])  # smaller index
        if li > 0:
            x[si] = li
            tp += p[si]
    return tp


def findsmallerindex(x: list, t):
    li = t
    for e in x:
        if e == t:
            li = findsmallerindex(x, t - 1)
    return li


if __name__ == '__main__':
    p = [100, 10, 15, 20]
    d = [2, 1, 2, 1]
    x = []
    for i in range(len(d)):
        x.append(-1)
    tp = jobsort(p, d, x)
    print("max p is",tp)
    print("job sort is",x)
