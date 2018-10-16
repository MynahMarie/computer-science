#!/usr/local/bin/python3

def count7(N):
    '''
    N: a non-negative integer
    '''

    # def countEach(num, c=0):
    #     if num == 0:
    #         # print(str(c))
    #         return c
    #     else:
    #         if num % 10 == 7:
    #             c += 1
    #         countEach((num // 10), c)
    #
    # countEach(N)

    if N < 10 and N == 7:
        return 1
    elif N < 10 and N != 7:
        return 0
    elif N > 10 and N % 10 == 7:
        return 1 + count7(N // 10)
    else:
        return 0 + count7(N // 10)



# Test Cases
# print("1")
count7(7)
# print("2")
count7(77)
# print("3")
count7(171)
count7(16789384772)
