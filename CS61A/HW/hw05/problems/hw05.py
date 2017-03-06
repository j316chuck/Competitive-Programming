def print_move(origin, destination):
    """Print instructions to move a disk."""
    print("Move the top disk from rod", origin, "to rod", destination)

def move_stack(n, start, end):
    """Print the moves required to move n disks on the start pole to the end
    pole without violating the rules of Towers of Hanoi.

    n -- number of disks
    start -- a pole position, either 1, 2, or 3
    end -- a pole position, either 1, 2, or 3

    There are exactly three poles, and start and end must be different. Assume
    that the start pole has at least n disks of increasing size, and the end
    pole is either empty or has a top disk larger than the top n start disks.

    >>> move_stack(1, 1, 3)
    Move the top disk from rod 1 to rod 3
    >>> move_stack(2, 1, 3)
    Move the top disk from rod 1 to rod 2
    Move the top disk from rod 1 to rod 3
    Move the top disk from rod 2 to rod 3
    >>> move_stack(3, 1, 3)
    Move the top disk from rod 1 to rod 3
    Move the top disk from rod 1 to rod 2
    Move the top disk from rod 3 to rod 2
    Move the top disk from rod 1 to rod 3
    Move the top disk from rod 2 to rod 1
    Move the top disk from rod 2 to rod 3
    Move the top disk from rod 1 to rod 3
    """
    assert 1 <= start <= 3 and 1 <= end <= 3 and start != end, "Bad start/end"
    "*** YOUR CODE HERE ***"
    if n == 1:
        print("Move the top disk from rod %d to rod %d" % (start, end))
        return
    else:
        move_stack(n-1, start, 6-start-end)
        move_stack(1, start, end)
        move_stack(n-1, 6-start-end, end)
        #move_stack(n-1, start, end-1)
        #move_stack(1, start, end)
        #move_stack(n-1, start+1, end)
        #return 2*move_stack(n-1, start, end)+1

def interval(a, b):
    """Construct an interval from a to b."""
    return [a, b]

def lower_bound(x):
    """Return the lower bound of interval x."""
    "*** YOUR CODE HERE ***"
    if x[0] > x[1]:
        return x[1]
    else:
        return x[0]

def upper_bound(x):
    """Return the upper bound of interval x."""
    "*** YOUR CODE HERE ***"
    if x[1] > x[0]:
        return x[1]
    else:
        return x[0]

def str_interval(x):
    """Return a string representation of interval x."""
    return '{0} to {1}'.format(lower_bound(x), upper_bound(x))

def add_interval(x, y):
    """Return an interval that contains the sum of any value in interval x and
    any value in interval y."""
    lower = lower_bound(x) + lower_bound(y)
    upper = upper_bound(x) + upper_bound(y)
    return interval(lower, upper)

def mul_interval(x, y):
    """Return the interval that contains the product of any value in x and any
    value in y."""
    p1 = lower_bound(x)*lower_bound(y)
    p2 = lower_bound(x)*upper_bound(y)
    p3 = upper_bound(x)*lower_bound(y)
    p4 = upper_bound(x)*upper_bound(y)
    return interval(min(p1, p2, p3, p4), max(p1, p2, p3, p4))

def sub_interval(x, y):
    """Return the interval that contains the difference between any value in x
    and any value in y."""
    "*** YOUR CODE HERE ***"
    p1 = lower_bound(x)-lower_bound(y)
    p2 = lower_bound(x)-upper_bound(y)
    p3 = upper_bound(x)-lower_bound(y)
    p4 = upper_bound(x)-upper_bound(y)

    return interval(min(p1, p2, p3, p4), max(p1, p2, p3, p4))
    
    

def div_interval(x, y):
    """Return the interval that contains the quotient of any value in x divided by
    any value in y. Division is implemented as the multiplication of x by the
    reciprocal of y."""
    "*** YOUR CODE HERE ***"
    assert 1/lower_bound(y) > 0 or 1/upper_bound(y) < 0 
    reciprocal_y = interval(1/upper_bound(y), 1/lower_bound(y))

    return mul_interval(x, reciprocal_y)

def par1(r1, r2):
    return div_interval(mul_interval(r1, r2), add_interval(r1, r2))

def par2(r1, r2):
    one = interval(1, 1)
    rep_r1 = div_interval(one, r1)
    rep_r2 = div_interval(one, r2)
    return div_interval(one, add_interval(rep_r1, rep_r2))

def check_par():
    """Return two intervals that give different results for parallel resistors.

    >>> r1, r2 = check_par()
    >>> x = par1(r1, r2)
    >>> y = par2(r1, r2)
    >>> lower_bound(x) != lower_bound(y) or upper_bound(x) != upper_bound(y)
    True
    """
    r1 = interval(1/6, 1/8) # Replace this line!
    r2 = interval(-1/3, -1/5) # Replace this line!
    #r1 = interval(1, 2)
    #r2 = interval(1, 2)
    #print(par1(r1, r2), par2(r1, r2)) 
    return r1, r2

def multiple_references_explanation():
    return """ There is a problem with the calculation of par1. For every calculation, 
    there is a fixed correct interval. However, combining two combinations that calculate upon 
    the same interval will produce erroneous results that is larger than what it should be. Take for 
    example (1, 2) and (1, 2). When you use par2, the results of each operation matches what it should be
    in real life. (div_interval(one, r1) = (1/2, 1), add_interval(rep_r1, rep_r2) = (1, 2), etc) because
    it does one operation after the other. However, in par1, when you combine expressions together, you get an error. 
    For instance, mul_interal(r1, r2) = (1, 4) and add_interval((1,2), (1,2)) = (1, 4). These two intervals
    are overlapping!!! and thus when you divide them it gives the result (1, 16) which is far too large"""

def quadratic(x, a, b, c):
    """Return the interval that is the range of the quadratic defined by
    coefficients a, b, and c, for domain interval x.

    >>> str_interval(quadratic(interval(0, 2), -2, 3, -1))
    '-3 to 0.125'
    >>> str_interval(quadratic(interval(1, 3), 2, -3, 1))
    '0 to 10'
    """
    "*** YOUR CODE HERE ***"
    extrema = -b/(2*a)
    quadratic = lambda x: a*x*x + b*x + c        
    #print(quadratic(0), quadratic(2), quadratic(3/4), extrema, lower_bound(x), upper_bound(x))
    if extrema < lower_bound(x) or extrema > upper_bound(x):
        minimum = min(quadratic(lower_bound(x)), quadratic(upper_bound(x)))
        maximum = max(quadratic(lower_bound(x)), quadratic(upper_bound(x)))
    else:   
        #print("hello")         
        minimum = min(quadratic(lower_bound(x)), quadratic(upper_bound(x)), quadratic(extrema))
        maximum = max(quadratic(lower_bound(x)), quadratic(upper_bound(x)), quadratic(extrema))
    #print(minimum, maximum)
    #print(interval(minimum, maximum))
    return interval(minimum, maximum)

def polynomial(x, c):
    """Return the interval that is the range of the polynomial defined by
    coefficients c, for domain interval x.

    >>> str_interval(polynomial(interval(0, 2), [-1, 3, -2]))
    '-3 to 0.125'
    >>> str_interval(polynomial(interval(1, 3), [1, -3, 2]))
    '0 to 10'
    >>> str_interval(polynomial(interval(0.5, 2.25), [10, 24, -6, -8, 3]))
    '18.0 to 23.0'
    """
    "*** YOUR CODE HERE ***"

