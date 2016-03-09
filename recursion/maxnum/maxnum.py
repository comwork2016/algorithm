#!/usr/bin/python
def getmaxnumindex(arr, b, e):
    "arr is the data array, b is begin index and e is last index of the array"
    if b == e:
        return b
    # find the max number of rest array and compare with current number.
    restmaxindex = getmaxnumindex(arr, b + 1, e)
    if arr[restmaxindex] > arr[b]:
        return restmaxindex
    return b


if __name__ == '__main__':
    arr = (10, 25, 12, 3, 41, 25, 56, 57, 38, 19)
    maxIndex = getmaxnumindex(arr, 0, 9)
    print("max number of arr is arr[%d]=%d"%(maxIndex,arr[maxIndex]))