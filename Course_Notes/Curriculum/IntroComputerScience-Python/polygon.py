import math

# Area: 0.25 * n * (s**2) / tan( pi/n )
# Permimeter Squared: (n * s)**2

def polysum(n, s):

    """
    Given a number of sides 'n' and the length of each sides 's', 
    produce the sum of the area and squared perimeter of this polygon.
    """
    return round((0.25 * n * (s**2) / math.tan(math.pi/n)) + ((n * s)**2), 4)
