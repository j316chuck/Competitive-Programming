from lab03 import *
import math

def is_palindrome(n):
    """
    Fill in the blanks '_____' to check if a number
    is a palindrome.

    >>> is_palindrome(12321)
    True
    >>> is_palindrome(42)
    False
    >>> is_palindrome(2015)
    False
    >>> is_palindrome(55)
    True
    """
    x, y = n, 0
    f = lambda: y*10 + x%10
    while x > 0:
        x, y = x//10, f()
    return y == n

def skip_mul(n):
    """Return the product of n * (n - 2) * (n - 4) * ...

    >>> skip_mul(5) # 5 * 3 * 1
    15
    >>> skip_mul(8) # 8 * 6 * 4 * 2
    384
    """
    if n == 2:
        return 2
    if n == 1:
        return 1
    else:
        return n * skip_mul(n - 2)

def count_up(n):
    """Print out all numbers up to and including n in ascending order.

    >>> count_up(5)
    1
    2
    3
    4
    5
    """
    def counter(i):
        "*** YOUR CODE HERE ***"
        if n == i:
            print(n)
            return
        else:
            print(i)
            return counter(i+1);

    counter(1)

def ab_plus_c(a, b, c):
    """Computes a * b + c.

    >>> ab_plus_c(2, 4, 3)  # 2 * 4 + 3
    11
    >>> ab_plus_c(0, 3, 2)  # 0 * 3 + 2
    2
    >>> ab_plus_c(3, 0, 2)  # 3 * 0 + 2
    2
    """
    "*** YOUR CODE HERE ***"
    if b == 0:
        return c
    else:
        return a + ab_plus_c(a, b-1, c)

def is_prime(n):
    """Returns True if n is a prime number and False otherwise.

    >>> is_prime(2)
    True
    >>> is_prime(16)
    False
    >>> is_prime(521)
    True
    """
    "*** YOUR CODE HERE ***"
    if n == 1: 
        return False 

    def square_root(k):
        if k > math.sqrt(n):
            return True
        else:
            if n % k == 0:
                return False;
            elif n % k != 0:
                return square_root(k+1)
    return square_root(2)

def interleaved_sum(n, odd_term, even_term):
    """Compute the sum odd_term(1) + even_term(2) + odd_term(3) + ..., up
    to n.

    >>> # 1 + 2^2 + 3 + 4^2 + 5
    ... interleaved_sum(5, lambda x: x, lambda x: x*x)
    29
    """
    "*** YOUR CODE HERE ***"
    if n == 1:
        return odd_term(1)
    if n % 2 == 1:
        return odd_term(n) + interleaved_sum(n-1, odd_term, even_term)
    if n % 2 == 0:
        return even_term(n) + interleaved_sum(n-1, odd_term, even_term)


def ten_pairs(n):
    """Return the number of ten-pairs within positive integer n.

    >>> ten_pairs(7823952)
    3
    >>> ten_pairs(55055)
    6
    >>> ten_pairs(9641469)
    6
    """
    "*** YOUR CODE HERE ***"
    def used(i, k):
        if k == 0:
            return 0
        if k % 10 == i:
            return 1 + used(i, k//10)
        if k % 10 != i:
            return used(i, k//10)

    return int(used(1, n)* used(9, n) + used(2, n)*used(8, n) + used(3, n) * used(7, n) +used(4, n) * used(6, n) + (used(5, n)*(used(5, n)-1))//2)

def test(n):
    x = n+1
    def test2(j):
        y = j+1
        def test3(k):
            return j + x + n
        return test3
    return test2(0)

print(test(1)(3))