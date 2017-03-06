def multiple(a, b):
    """Return the smallest number n that is a multiple of both a and b.

    >>> multiple(3, 4)
    12
    >>> multiple(14, 21)
    42
    """
    "*** YOUR CODE HERE ***"
    minimum = min(a, b)
    for i in range(minimum, 0, -1):
        if a % i == 0 and b % i == 0:
            return int( a * b / i)

def unique_digits(n):
    """Return the number of unique digits in positive integer n

    >>> unique_digits(8675309) # All are unique
    7
    >>> unique_digits(1313131) # 1 and 3
    2
    >>> unique_digits(13173131) # 1, 3, and 7
    3
    >>> unique_digits(10000) # 0 and 1
    2
    >>> unique_digits(101) # 0 and 1
    2
    >>> unique_digits(10) # 0 and 1
    2
    """
    "*** YOUR CODE HERE ***"
    count = 0
    n = str(n)
    for i in range(0, 10):
        i = str(i)
        for j in n:
            if j == i:
                count+=1
                break
    
    return count

#print multiple(14, 21), multiple(1, 2), multiple(3, 4), multiple(5, 25)
#print unique_digits(8675309), unique_digits(1313131),  unique_digits(13173131)
#print unique_digits(10000), unique_digits(101), unique_digits(10) 