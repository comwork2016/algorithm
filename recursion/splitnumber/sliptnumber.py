#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/03/08
"""
[自然数拆分]任何一个大于1 的自然数n , 总可以拆分成若干个小于n
的自然数之和, 试求n的所有拆分(用不完全归纳法)。
"""

def split(n):
    if n == 2:
        list = [[1, 1]]
        return list
    else:
        list = [];
        for index in range(1, int(n / 2) + 1):
            list.append([index, n - index])
            onelist = [index]
            restlist = split(n - index)
            for l in restlist:
                #if the first element of restlist is larger than index,discard it, because the fomer has this type.
                if index <= l[0]:
                    onelist.extend(l)
                    list.append(onelist)
                # init onelist again
                onelist = [index]
        return list


if __name__ == '__main__':
    list = split(7)
    for l in list:
        print(l)
