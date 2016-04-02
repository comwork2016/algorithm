#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/04/02
'''
二分检索树（Binary Search Tree）的定义：
二分检索树是一棵二元树，它或者为空，或者其每个结点的数据元素都可以比较大小，且满足下面性质：
（1）T的左子树中的所有元素都比根结点中的元素小。
（2）T的右子树中的所有元素都比根结点中的元素大。
（3）T的左子树和右子树也是二分检索树。
注：Binary Search Tree要求树中的结点元素值互异。
'''

from dynamicprogramming.optimalbinarysearchtree import node


def obst(num: list, P: list, Q: list, length):
    # init W[],C[],R[]
    W = []
    C = []
    R = []
    for i in range(length + 1):
        W.append([])
        C.append([])
        R.append([])
        for j in range(length + 1):
            W[i].append(0)
            C[i].append(0)
            R[i].append(0)
        W[i][i] = Q[i]
        C[i][i] = 0
    # init single node of each number
    for i in range(length):
        W[i][i + 1] = P[i + 1] + Q[i + 1] + W[i][i]
        C[i][i + 1] = W[i][i + 1] + C[i][i]  # C[i][j] = W[i][j] + min{C[i][k-1]+C[k][j]}
        R[i][i + 1] = i + 1
    # use single node to find the root node of tree
    for d in range(2, length + 1):  # d refers to delta of each loop
        for i in range(length + 1 - d):
            j = i + d
            W[i][j] = P[j] + Q[j] + W[i][j - 1]
            # find min k to be the root
            mink = i + 1
            mincost = C[i][mink - 1] + C[mink][j]
            for k in range(i + 1, j + 1):
                if C[i][k - 1] + C[k][j] < mincost:
                    mink = k
                    mincost = C[i][k - 1] + C[k][j]
            C[i][j] = W[i][j] + C[i][mink - 1] + C[mink][j]
            R[i][j] = mink
    return W, C, R


def createbst(num: list, start, end, R: list):
    'create binary search tree using root node'
    if start >= end:
        return None
    root = node.node()
    rootindex = R[start][end]
    root.data = num[rootindex]
    root.lchild = createbst(num, start, rootindex - 1, R)
    root.rchild = createbst(num, rootindex, end, R)
    return root

def allpath(root:node.node, stack:list):
    'output all paths'
    if root:
        stack.append(root.data)
        if not root.lchild and not root.rchild: # lchild and rchild None refer to leaf node
            print(stack)
        else:
            allpath(root.lchild,stack)
            allpath(root.rchild,stack)
        stack.pop()

if __name__ == '__main__':
    num = [None, 12, 23, 34, 45, 56, 64]  # 输入的树已排好序
    P = [None, 3, 3, 1, 3, 2, 2]
#    P = [None, 1, 1, 1, 1, 1, 1]
    Q = [4, 2, 1, 2, 3, 4, 5]
#    Q = [1, 1, 1, 1, 1, 1, 1]
    length = len(num) - 1
    W, C, R = obst(num, P, Q, length)
    print("min cost is", C[0][length], "and the root node is", num[R[0][length]])
    root = createbst(num, 0, length, R)
    stack = []
    allpath(root,stack)

