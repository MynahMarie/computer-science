def f(a, b):
    return a + b


def dict_interdiff(d1, d2):
    '''
    d1, d2: dicts whose keys and values are integers
    Returns a tuple of dictionaries according to the instructions above
    '''
    k1 = list(d1.keys())
    k2 = list(d2.keys())

    def intersect(d1, d2):
        intersect_dict = {}
        for i in range(len(k1)):
            for j in range(len(k2)):
                if k1[i] in k2:
                    intersect_dict[k1[i]] = f(d1[k1[i]], d2[k1[i]])
        print("intersect_dict = ", intersect_dict)
        return intersect_dict

    def difference(d1, d2):
        diff_dict = {}
        for i in range(len(k1)):
            for j in range(len(k2)):
                if k1[i] not in k2:
                    diff_dict[k1[i]] = d1[k1[i]]
                elif k2[j] not in k1:
                    diff_dict[k2[j]] = d2[k2[j]]
        print("diff_dict = ", diff_dict)
        sorted_dict = {k: diff_dict[k] for k in sorted(diff_dict.keys())}
        return sorted_dict

    return (intersect(dict(d1), dict(d2)), difference(dict(d1), dict(d2)))

def main():
    d1 = {1: 10, 2:40, 3:20}
    d2 = {2:20, 3:10, 5:20}

    d3 = {1:30, 2:20, 3:30, 5:80}
    d4 = {1:40, 2:50, 3:60, 4:70, 6:90}

    print(dict_interdiff(dict(d1), dict(d2)))
    print(dict_interdiff(dict(d3), dict(d4)))

if __name__ == "__main__":
    main()
