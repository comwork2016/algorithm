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
        rv.remove(nv)  # remove added vex from rest list
        # update cost dict
        for v in rv:
            if v in edge[nv]:
                if not cost[v] or (cost[v] and cost[nv] + edge[nv][v] < cost[v]):  # if there have no path from ov to v
                    cost[v] = cost[nv] + edge[nv][v]
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
    vex = ["v1", "v2", "v3", "v4", "v5", "v6","v7"]
    MAX = 100
    edge = {
        vex[0]: {vex[1]: 20, vex[2]: 50, vex[3]: 30},
        vex[1]: {vex[2]: 25, vex[5]: 70},
        vex[2]: {vex[3]: 40, vex[4]: 25, vex[5]: 50},
        vex[3]: {vex[5]: 55},
        vex[4]: {vex[5]: 10, vex[6]: 70},
        vex[5]: {vex[6]: 50}
    }
    ov = vex[0]  # origin vex
    cost={}
    path = {}
    dijkstra(vex, edge, ov,cost,path)
    for v in cost:
        pathstack = []
        pv = path[v]
        while pv != ov:
            pathstack.append(pv)
            pv = path[pv]
        pathstack.append(pv)
        print("%s--->%s cost is:%d   "%(ov,v,cost[v]),end="")
        psv = pathstack.pop()
        while psv:
            print("%s-->"%(psv),end="")
            if len(pathstack):
                psv = pathstack.pop()
            else:
                psv = None
        print(v)

