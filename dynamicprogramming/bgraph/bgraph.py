#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/03/17

"""
    动态规划：多段图向后处理法
"""


def bgraph(vex: list, edge: dict, s, t, cost: dict, path: dict):
    # init cost
    for i in range(len(vex)):
        cost[i] = {}
        path[i] = {}
    for v in vex[1]:
        cost[1][v] = edge[s][v]
        path[1][v] = s
    for k in range(1, len(vex) - 1):
        for v in vex[k]:
            for nv in edge[v]:
                if nv not in cost[k + 1] or cost[k + 1][nv] > cost[k][v] + edge[v][nv]:
                    cost[k + 1][nv] = cost[k][v] + edge[v][nv]
                    path[k + 1][nv] = v
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
    s = vex[0][0]
    t = vex[len(vex) - 1][0]
    cost = {}  # record min cost
    path = {}  # record prior vex of min cost
    bgraph(vex, edge, s, t, cost, path)
    for d in cost[len(vex) - 1]:
        c = cost[len(vex) - 1][d]  # min cost
    ps = []  # path stack to reverse the path
    pv = t  # 通过后一个点找前一个点
    i = len(vex) - 1
    while i >= 0:
        for d in path[i]:
            if (d == pv):
                pv = path[i][d]
                ps.append(pv)
        i -= 1
    v = ps.pop()
    while v:
        print("%s-->" % v, end="")
        if ps:
            v = ps.pop()
        else:
            break;
    print("%s min cost from %s to %s is %d" % (t, s, t, c))
