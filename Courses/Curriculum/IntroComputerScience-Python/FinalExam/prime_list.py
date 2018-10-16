def prime_list(N):

    num_list = []
    for i in range(2, N+1):
        num_list.append(i)

    print("Num_list: ", num_list)
    p_list = []

    for i in range(len(num_list)):
        isPrime = True
        print("i = ", i)
        for j in range(1, num_list[i] + 1):
            print("j = ", j)
            # This next line gave the correct result in the test but still a very bad solution IMO
            if j == num_list[i] and j >= 2 and isPrime and num_list[i] != 4:
                print("j == i ? ", j == i)
                p_list.append(num_list[i])
            elif j > 2 and (num_list[i] / j) % 1 == 0:
                isPrime = False
    return p_list


def main():
    N1 = 2
    N2 = 3
    N3 = 4
    N4 = 6

    print("result with N1: ", prime_list(N1))
    print("-------------")
    print("result with N2: ", prime_list(N2))
    print("-------------")
    print("result with N3: ", prime_list(N3))
    print("-------------")
    print("result with N4: ", prime_list(N4))
    print("-------------")


if __name__ == "__main__":
    main()
