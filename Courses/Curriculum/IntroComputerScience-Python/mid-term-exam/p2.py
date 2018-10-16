#!/usr/local/bin/python3

def dotProduct(listA, listB):
    result = 0
    for i in range(len(listA)):
        print("result, i: " + str(result) + " " + str(i))
        result += listA[i] * listB[i]
    print(result)




# Test Cases
dotProduct([1,2,3], [4,5,6]) #Shoud return 32
