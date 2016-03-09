#!/usr/bin/python

"""
[简单的0/1 背包问题]设一背包可容物品的最大质量为m,
现有n件物品, 质量为m1 , m2 , ⋯ , mn
mi,均为正整数,要从n件物品中挑选若干件,使放入背包的质量之和正好为m。
"""


def knap(ms: tuple, n: int, m: int, list: list) -> list:
    "ms is the quality list, n is the count of things,\
     m is the total quality we want, and list is the index of selected things."

    # select the last thing m[n].
    if ms[n] == m:
        list.append(n)
        return list
    elif ms[n] > m:
        # ms[n] cannot be put into bag,discard it and find next.
        restlist = []
        if n >= 1:
            restlist = knap(ms, n - 1, m, list)
        return restlist
    else:
        if n >= 1:
            # put this thing into bag
            restlist = knap(ms, n - 1, m - ms[n], list)
            if not restlist:
                restlist = knap(ms, n - 1, m, list)
                return restlist
            else:
                list.append(n)
                # find a complete solution of this knap
                return list


if __name__ == '__main__':
    m = 49  # total quality
    n = 9  # count of things
    ms = (6, 3, 12, 5, 11, 25, 26, 7, 18, 19)  # quality list
    list = []
    list = knap(ms, n, m, list)
    # """
    if not list:
        print("No solution")
        exit()
    result = str(m) + " = "
    for i in list:
        result = result + str(ms[i]) + " + "
    result = result.rstrip()[:-1].rstrip()
    print(result)
    # """

