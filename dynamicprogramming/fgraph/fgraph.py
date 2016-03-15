#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/03/14

"""
    动态规划：多段图向前处理法
"""


def fgraph(v: list, vex: list, edge: dict, s, t,cost:dict ,path:dict):
    # init cost
    for i in range(len(vex) - 1):
        cost[i] = {}
        path[i] = {}
    for v in vex[len(vex) - 2]:
        if t in edge[v]:
            cost[len(vex) - 2][v] = edge[v][t]
            path[len(vex) - 2][v] = t
    k = len(vex) - 3  # 从倒数第二段向前处理
    while k >= 0:
        for v in vex[k]:
            for nv in edge[v]:
                if v not in cost[k] or cost[k][v] > cost[k+1][nv] + edge[v][nv]:
                    cost[k][v] = cost[k+1][nv] + edge[v][nv]
                    path[k][v] = nv
        k -= 1
    return


if __name__ == '__main__':
    v = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"]
    vex = [[v[0]],
           [v[1], v[2], v[3], v[4]],
           [v[5], v[6], v[7]],
           [v[8], v[9], v[10]],
           [v[11]]
           ]
    edge = {v[0]: {v[1]: 9, v[2]: 7, v[3]: 3, v[4]: 2},
            v[1]: {v[5]: 4, v[6]: 2, v[7]: 1},
            v[2]: {v[5]: 2, v[6]: 7},
            v[3]: {v[7]: 11},
            v[4]: {v[6]: 11, v[7]: 8},
            v[5]: {v[8]: 6, v[9]: 5},
            v[6]: {v[8]: 4, v[9]: 3},
            v[7]: {v[9]: 5, v[10]: 6},
            v[8]: {v[11]: 4},
            v[9]: {v[11]: 2},
            v[10]: {v[11]: 5}
            }
    s=vex[0][0]
    t=vex[len(vex) - 1][0]
    cost = {} # record min cost
    path = {} # record next vex of min cost
    fgraph(v, vex, edge, s, t,cost,path)
    for d in cost[0]:
        c = cost[0][d] # min cost
    pv = s # 通过前一个点找下一个点
    print("%s"%(pv),end="")
    for i in range(len(vex)-1):
        for d in path[i]:
            if d == pv:
                pv = path[i][d]
                print("-->%s"%pv,end="")
    print(" min cost from %s to %s is %d"%(s,t,c))