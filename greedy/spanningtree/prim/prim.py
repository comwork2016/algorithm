#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/03/09


def prim(vex: list, edge: dict, pedge: dict):
    # add first vex
    pvex = []
    pvex.append(vex[0])
    pedge.clear()
    lowcost = {}
    # init lowcost
    for pv in pvex:
        for v in vex:
            if v != pv:
                if v in edge[pv]:  # edge exists between pv and v
                    lowcost[v] = pv
                else:
                    lowcost[v] = None
    for index in range(len(vex) - 1):
        # find min edge to elements in pvex
        min = MAX
        for v in lowcost.keys():
            if lowcost[v] and lowcost[v] in edge[v] and min > edge[v][lowcost[v]]:
                min = edge[v][lowcost[v]]
                mv = v  # record the min vex that not in pvex
        pvex.append(mv)
        pedge[mv] = lowcost[mv]
        lowcost.pop(mv)
        # update lowcost when add a new vex(mv)
        for v in lowcost:
            if (not lowcost[v]) or (v in edge[mv]) and edge[v][lowcost[v]] > edge[v][mv]:
                lowcost[v] = mv


if __name__ == '__main__':
    vex = ["1", "2", "3", "4", "5", "6"]
    MAX = 100
    edge = {
        vex[0]: {vex[1]: 10, vex[3]: 30, vex[4]: 45},
        vex[1]: {vex[0]: 10, vex[2]: 50, vex[4]: 40, vex[5]: 25},
        vex[2]: {vex[1]: 50, vex[4]: 35, vex[5]: 15},
        vex[3]: {vex[0]: 30, vex[5]: 20},
        vex[4]: {vex[0]: 45, vex[1]: 40, vex[2]: 34, vex[5]: 55},
        vex[5]: {vex[1]: 25, vex[2]: 15, vex[3]: 20, vex[4]: 55}
    }
    pedge = {}
    prim(vex, edge, pedge)
    tc = 0  # total cost
    print("spanning tree is:")
    for key in pedge:
        tc += edge[key][pedge[key]]
        print("%s--->%s:%d" % (key, pedge[key], edge[key][pedge[key]]))
    print("lowest cost of spanning tree is:", tc)
