#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on 2016/3/7


def hanoi(n, X, Y, Z):
    "n is the number of plates, X is the source pillar, Y is assist pillar and Z is the destination pillar"
    if n < 1:
        return
    hanoi(n - 1, X, Z, Y)
    # move plate n from X to Z
    print("move plate %d from %s to %s" % (n, X, Z))
    hanoi(n - 1, Y, X, Z)


if __name__ == '__main__':
    hanoi(3, "X", "Y", "Z")
