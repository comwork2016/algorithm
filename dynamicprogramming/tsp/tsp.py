#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/04/09

'''
TSP问题（旅行商问题）是指旅行家要旅行n个城市，要求各个城市经历且仅经历一次然后回到出发城市，并要求所走的路程最短。
'''

MAXINT = 1000

def findfirst10(flag:list):
    pos10 = -1
    count1 = 0
    for i in range(len(flag)-1):
        if flag[i] ==1 and flag[i+1] == 0:
            pos10 = i
            return pos10,count1
        if flag[i] == 1:
            count1+=1
    return pos10,count1

# 获取length中的num组合，除开vo
def combination(length,num,vo):
    comb = []
    flag = []
    for i in range(length-1):
        if i < num:
            flag.append(1)
        else:
            flag.append(0)
    finallist = list(flag)
    finallist.insert(vo,0)
    comb.append(finallist)
    pos10,count1 = findfirst10(flag)
    while pos10 != -1:
        # swap 10 to 01
        flag[pos10] = 0
        flag[pos10+1] = 1
        for i in range(pos10):
            if i< count1:
                flag[i] = 1
            else:
                flag[i] = 0
        finallist = list(flag)
        finallist.insert(vo,0)
        comb.append(finallist)
        pos10,count1 = findfirst10(flag)
    return comb;

# 标志列表中选中元素的集合
def getlistfromcomb(flaglist:list):
    elem = []
    for i in range(len(flaglist)):
        if flaglist[i] == 1:
            elem.append(i)
    return elem

def dsp(cost:list,vo):
    length = len(vex)
    # g{i,S} 表示从i点出发，经过S中的点各一次后回到点的最小距离
    g={}
    path={}# g{i,S} 表示从i点出发时，S中的下一个点
    # init g，从Vex-vo中的各点出发，不经过其它点回到vo点的最小距离
    for i in range(length):
        if i!=vo:
            g[i] = {():cost[i][vo]}
            path[i]={():None}
        else:
            g[i]={}
            path[i]={}
    # k表示从集合vex中取出k个元素
    for k in range(1,length):
        # 获取length中的num组合，除开vo
        comb = combination(length,k,vo)
        # 遍历组合中的元素
        for flaglist in comb:
            # 标志列表中选中元素的集合
            S = getlistfromcomb(flaglist)
            # 遍历所有的点
            for i in range(length):
                # 如果是出发点，且不是最终状态，即S中存放的是除vo外的所有点，不处理
                if k!= length-1 and i==vo:
                    continue
                if i in S: # 起点在要经过的点集中，则不处理
                    continue
                # g( i , S) = min{cij + g( j , S - {j})}
                # find min start point to add
                minv = -1
                ming = MAXINT
                for v in S:
                    listcpy = list(S) # copy a list
                    listcpy.remove(v)
                    if v!=i:# 与起点的值不同
                        if ming > cost[i][v] + g[v][tuple(listcpy)]:
                            minv = v
                            ming = cost[i][v] + g[v][tuple(listcpy)]
                if minv == -1:
                    continue
                path[i][tuple(S)] = minv
                g[i][tuple(S)] = ming
    return g,path

if __name__ == '__main__':
    vex=['a','b','c','d']
    cost=[
        [0,3,6,7],
        [5,0,2,3],
        [6,4,0,2],
        [3,7,5,0]
    ]
    vo = 2 # 起点
    g,path = dsp(cost,vo)
    cost = 0
    key = ()
    for k in g[vo]:
        cost = g[vo][k]
        key = k
    print("lowest cost from",vex[vo],"is",cost)
    print("path is",vex[vo],end="")
    node = path[vo][key]
    while node!= None:
        print("-->",vex[node],end="")
        S = list(key)
        S.remove(node)
        key = tuple(S)
        node = path[node][key]
    print("-->",vex[vo])

