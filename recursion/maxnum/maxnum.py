#!/usr/bin/python

class MaxNumArray:
    "get max number of a array"
    __arr = []

    def __init__(self,arr):
        self.__arr = arr

    def __getMaxNumIndex(self,b,e):
        "arr is the data array, b is begin index and e is last index of the array"
        if b == e:
            return b
        # find the max number of rest array and compare with current number.
        restmaxindex = self.__getMaxNumIndex(b+1,e)
        if self.__arr[restmaxindex] > self.__arr[b]:
            return restmaxindex
        return b

    def printMaxNum(self):
        maxIndex = self.__getMaxNumIndex(0,len(self.__arr)-1)
        print("max number of arr is arr[%d]=%d"%(maxIndex,self.__arr[maxIndex]))

if __name__ == '__main__':
    arr = [10, 25, 12, 3, 41, 25, 56, 57, 38, 19]
    maxNum = MaxNumArray(arr)
    maxNum.printMaxNum()