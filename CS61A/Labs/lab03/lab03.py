def gcd(a, b):
    """Returns the greatest common divisor of a and b.
    Should be implemented using recursion.

    >>> gcd(34, 19)
    1
    >>> gcd(39, 91)
    13
    >>> gcd(20, 30)
    10
    >>> gcd(40, 40)
    40
    """
    "*** YOUR CODE HERE ***"
    if a <= b:
        if b % a == 0:
            return a
        else:
            return gcd(a, b % a)
    else:
        if a % b == 0:
            return b
        else:
            return gcd(a % b, b)


def hailstone(n):
    """Print out the hailstone sequence starting at n, and return the
    number of elements in the sequence.

    >>> a = hailstone(10)
    10
    5
    16
    8
    4
    2
    1
    >>> a
    7
    """
    "*** YOUR CODE HERE ***"
    print(int(n))
    if n == 1:
        return 1;
    if n % 2 == 0:
        return 1+hailstone(n/2)
    if n % 2 == 1:
        return 1+hailstone(3 * n + 1)
