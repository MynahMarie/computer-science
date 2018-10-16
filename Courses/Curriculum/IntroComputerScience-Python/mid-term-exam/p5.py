#!/usr/local/bin/python3

def general_poly (L):
    """
    L, a list of numbers (n0, n1, n2, ... nk)
    Returns a function, which when applied to a value x, returns the value
    n0 * x^k + n1 * x^(k-1) + ... nk * x^0
    """
    def poly(x):
        k = len(L) - 1
        sum = 0

        for item in L:
            sum += item * (x**k)
            k -= 1
        print(str(sum))
        return sum
    return poly

general_poly([1, 2, 3, 4])(2)
general_poly([3,2,1])(2)
