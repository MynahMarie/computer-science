def swapSort(L): 
    """ L is a list on integers """
    print("Original L: ", L)
    for i in range(len(L)):
        for j in range(i+1, len(L)):
            if L[j] < L[i]:
            # the next line is a short 
            # form for swap L[i] and L[j]
                L[j], L[i] = L[i], L[j] 
                print(L)
    print("Final L: ", L)


def modSwapSort(L): 
    """ L is a list on integers """
    print("Original L: ", L)
    for i in range(len(L)):
        for j in range(len(L)):
            if L[j] < L[i]:
                # the next line is a short 
                # form for swap L[i] and L[j]
                L[j], L[i] = L[i], L[j] 
                print(L)
    print("Final L: ", L)


def search(L, e):
    for i in range(len(L)):
        print("i = " + str(i))
        print("L[i:] = " + str(L[i:]))
        if L[i] == e:
            print("True")
            return True
        if L[i] > e:
            print("False")
            return False
    print("False")
    return False


def newsearch(L, e):
    size = len(L)
    for i in range(size):
        print("i = " + str(i))
        print("L[size-i-1] = " + str(L[size-i-1]))
        print("L[i] = " + str(L[i]))
        if L[size-i-1] == e:
            print("True")
            return True
        if L[i] < e:
            print("False")
            return False
    print("False")
    return False


def main():

    L = [[], [2], [2, 5], [2, 5, 7, 8, 9], [2, 5, 7, 8, 9, 12, 16, 34]]
    e = [2, 4, 34, 33]
    U = [[37, 3894, 1, 0, 37894, 56, 859], [2, 7, 484, 34], [], [4],
         [1872983, 3, 7]]

    for i in range(len(L)):
        print("-------------------")
        # print("L = " + str(L[i]))
        for j in e:

            print("e = " + str(j))
            # print("[*] search()")
            # search(L[i], j)
            # print("[*] newsearch()")
            # newsearch(L[i], j)
            print("[*] swapSort()")
            swapSort(U[i][:])
            print("[*] modSwapSort()")
            modSwapSort(U[i][:])
            print("------------------")


if __name__ == "__main__":
    main()


    
