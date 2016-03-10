#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/03/10

from greedy.spanningtree.kruskal import quicksort


def kruskal(vex: list, edge: dict, pedge: list):
    uset = {}  # union set to detect if there is a loop in spanning tree
    # init uset
    for v in vex:
        uset[v] = v  # use itself as its parent
    # sort edge asc
    elist = quicksort.sortedgeasc(edge)
    for d in elist:
        # {'2': '1'} refer to edge vex 2 to vex 1
        for k in d:
            vi = k
            vj = d[k]
        ri = findusetroot(vi, uset)  # root node of vi
        rj = findusetroot(vj, uset)  # root node of vj
        if ri != rj:  # vi and vj not in the same union set, add edge to spanning tree
            pedge.append(d)
            uset[rj] = vi


def findusetroot(v, uset: list):
    while v != uset[v]:
        v = uset[v]
    return v


if __name__ == '__main__':
    vex = ["1", "2", "3", "4", "5", "6"]
    MAX = 100
    edge = {
        vex[0]: {vex[1]: 10, vex[3]: 30, vex[4]: 45},
        vex[1]: {vex[0]: 10, vex[2]: 50, vex[4]: 40, vex[5]: 25},
        vex[2]: {vex[1]: 50, vex[4]: 35, vex[5]: 15},
        vex[3]: {vex[0]: 30, vex[5]: 20},
        vex[4]: {vex[0]: 45, vex[1]: 40, vex[2]: 35, vex[5]: 55},
        vex[5]: {vex[1]: 25, vex[2]: 15, vex[3]: 20, vex[4]: 55}
    }
    pedge = []
    kruskal(vex, edge, pedge)
    tc = 0  # total cost
    print("spanning tree is:")
    for d in pedge:
        for k in d:
            vi = k
            vj = d[k]
        tc += edge[vi][vj]
        print("%s--->%s:%d" % (vi, vj, edge[vi][vj]))
    print("lowest cost of spanning tree is:", tc)
