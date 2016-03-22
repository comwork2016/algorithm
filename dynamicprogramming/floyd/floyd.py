#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/03/21

MAX = 100

def floyd(vex:list,cost:list):
    A = []
    for i in range(len(cost)):
        A.append([])
        for j in range(len(cost)):
            A[i].append(cost[i][j])
    for k in range(len(vex)):
        for i in range(len(A)):
            for j in range(len(A)):
                if A[i][j] > A[i][k] + A[k][j]:
                    A[i][j] = A[i][k] + A[k][j]
    return A



if __name__ == '__main__':
    vex = ["1", "2", "3"]
    #成本矩阵
    cost = [
        [0,4,11],
        [6,0,2],
        [3,MAX,0]
    ]
    A = floyd(vex,cost)
    for l in A:
        print(l)
