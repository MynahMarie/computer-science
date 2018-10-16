def McNuggets(n):
    """
    n is an int

    Returns True if some integer combination of 6, 9 and 20 equals n
    Otherwise returns False.
    """

    vals = [6, 9, 20]

    if n in vals or (n % vals[0] == 0 or n % vals[1] == 0 or n % vals[2] == 0):
        return True
    elif n < vals[0]:
        return False
    elif n > vals[0] and n < vals[1]:
        return McNuggets(n % vals[0])
    elif n > vals[1] and n < vals[2]:
        return McNuggets(n % vals[1])
    else:
        return McNuggets(n % vals[2])


def main():

    for i in range(1, 29):
        print("i = ", i, " ", McNuggets(i))


if __name__ == "__main__":
    main()
