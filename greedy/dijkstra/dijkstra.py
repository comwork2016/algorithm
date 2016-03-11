#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/03/11

def dijkstra(vex: list, edge: dict, ov,cost:dict,path:dict):
    # {'B':2} record nearest cost from B to ov is 2
    # {'B':'C'} record nearest cost from B to ov and last vex from B to ov is C
    rv = list(vex)  # rest vex
    av = []  # added vex
    av.append(ov)
    rv.remove(ov)
    # init cost
    for v in rv:
        if v in edge[ov]:
            cost[v] = edge[ov][v]
            path[v] = ov
        else:
            cost[v] = None
            path[v] = None
    for vi in vex:
        nv = chooseshortest(cost, av, ov)  # next vex
        if not nv:
            break;
        av.append(nv)  # add next vex to added list
        rv.remove(nv)
        # update cost dict
        for v in rv:
            if nv in edge[v]:
                if not cost[v] or (cost[v] and cost[nv] + edge[v][nv] < cost[v]):  # if there have no path from ov to v
                    cost[v] = cost[nv] + edge[v][nv]
                    path[v] = nv
    return path


def chooseshortest(cost: dict, av: list, ov):  # return shortest vex
    min = MAX
    dv = None
    for v in cost:
        if v not in av and cost[v] and min > cost[v]:
            min = cost[v]
            dv = v
    return dv


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
    ov = vex[0]  # origin vex
    cost={}
    path = {}
    dijkstra(vex, edge, ov,cost,path)
    for v in cost:
        print("cost is:%d   %s"%(cost[v],v),end="")
        pv = path[v]
        while pv != ov:
            print("--->%s"%(pv),end="")
            pv = path[pv]
        print("--->%s"%(pv))

