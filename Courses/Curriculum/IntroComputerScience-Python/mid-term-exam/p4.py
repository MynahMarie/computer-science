#!/usr/local/bin/python3

def flatten(aList):
    flatL = []

    def flat(l, lf):
        for el in l:
            if isinstance(el, list):
                flat(el, lf)
            else:
                lf.append(el)
        return lf

    result = flat(aList, flatL)
    print(result)

# Test Cases

flatten([[1,'a',['cat'],2],[[[3]],'dog'],4,5])
