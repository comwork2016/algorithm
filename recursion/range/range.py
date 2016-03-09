#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/3/8

"""
求 n 个元素的全排列。
"""


def dorange(e: list, k, n):
    "e: list of elements, range from k to n"
    if k == n:
        print(e)
    else:
        for index in range(k, n+1):
            et = list(e)
            et[index], et[k] = et[k], et[index]  # swap e[index] to the begin of list
            dorange(et, k + 1, n)

if __name__ == '__main__':
    e = ["a", "b", "c"]
    dorange(e, 0, 2)