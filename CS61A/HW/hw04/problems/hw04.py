HW_SOURCE_FILE = 'hw04.py'
import math

def g(n):
    """Return the value of G(n), computed recursively.

    >>> g(1)
    1
    >>> g(2)
    2
    >>> g(3)
    3
    >>> g(4)
    10
    >>> g(5)
    22
    >>> from construct_check import check
    >>> check(HW_SOURCE_FILE, 'g', ['While', 'For'])
    True
    """
    "*** YOUR CODE HERE ***"
    if n == 1 or n == 2 or n == 3:
        return n
    else:
        return g(n-1) + 2*g(n-2) + 3*g(n-3);


def g_iter(n):
    """Return the value of G(n), computed iteratively.

    >>> g_iter(1)
    1
    >>> g_iter(2)
    2
    >>> g_iter(3)
    3
    >>> g_iter(4)
    10
    >>> g_iter(5)
    22
    >>> from construct_check import check
    >>> check(HW_SOURCE_FILE, 'g_iter', ['Recursion'])
    True
    """
    "*** YOUR CODE HERE ***"
    sum = 0
    mylist = [];
    for i in range(1, n+1):
        if i == 1 or i == 2 or i == 3:
            sum = i
            mylist.append(i);
        else:
            sum = mylist[i-2] + 2*mylist[i-3] + 3*mylist[i-4] #decrease by 2 not 1 because array starts at 0
            mylist.append(sum);
    return sum;

def pingpong(n):
    """Return the nth element of the ping-pong sequence.

    >>> pingpong(7)
    7
    >>> pingpong(8)
    6
    >>> pingpong(15)
    1
    >>> pingpong(21)
    -1
    >>> pingpong(22)
    0
    >>> pingpong(30)
    6
    >>> pingpong(68)
    2
    >>> pingpong(69)
    1
    >>> pingpong(70)
    0
    >>> pingpong(71)
    1
    >>> pingpong(72)
    0
    >>> pingpong(100)
    2
    >>> from construct_check import check
    >>> check(HW_SOURCE_FILE, 'pingpong', ['Assign', 'AugAssign'])
    True
    """
    "*** YOUR CODE HERE ***"
    """res = 0
    change = 1;
    for i in range(1, n+1):
        res += change;
        if has_seven(i) or i % 7 == 0:
            change *=-1;
    return res
    """

    """
    int total = 0;
    while n > 0:
        if n == 1:
            total = 1;
        if n == 2: 
            total = 2;
        n--;
    """
    """if n == 1:
            return 1
        elif n == 2:
            return 2
        elif (n-1) % 7 == 0 or has_seven(n-1):
            return pingpong(n-2)
        else: 
            return (2*pingpong(n-1)-pingpong(n-2))"""

    def ping(count, change, result):
        if n == count:
            return result
        elif count % 7 == 0 or has_seven(count):
            return ping(count+1, -change, result-change)
        else:
            return ping(count+1, change, result+change)

    return ping(1, 1, 1)

def has_seven(k):
    """Returns True if at least one of the digits of k is a 7, False otherwise.

    >>> has_seven(3)
    False
    >>> has_seven(7)
    True
    >>> has_seven(2734)
    True
    >>> has_seven(2634)
    False
    >>> has_seven(734)
    True
    >>> has_seven(7777)
    True
    """
    if k % 10 == 7:
        return True
    elif k < 10:
        return False
    else:
        return has_seven(k // 10)

#for i in range(1, 22):
#   print(pingpong(i))

#print(pingpong(68))

#print("hello")
"""mem = []
for i in range(0, 1000):
    mem.append(0)
mem[0] = 1;
"""
def count_change(amount):
    """Return the number of ways to make change for amount.

    >>> count_change(7)
    6
    >>> count_change(10)
    14
    >>> count_change(20)
    60
    >>> count_change(100)
    9828
    """
    "*** YOUR CODE HERE ***"
    #me trying dynamic programming el o el
    """for i in range(0, amount):
        print(mem[amount]+" ")
    print('\n')
    if amount == 0:
        return mem[0]
    elif amount < 0: 
        return 0;
    elif mem[amount] != 0:
        return mem[amount]
    else:
        total = 0;
        for i in range(1, amount):
            if int(math.log(i , 2)) == math.log(i, 2):
                mem[amount-i] = count_change(amount-i)
                total += mem[amount-i]
        total = mem[amount]
        return mem[amount]
    """
    """"total = 0:
    for i in range(1, amount):
        if int(math.log(i, 2) == math.log(i, 2)):
            total+=term(prev)

    def term(prev):
        sum = 0;
        if amount == 0:
            return 1
        elif amount < 0: 
            return 0
        else:
            for i in range(1, amount):
                sum+=count_change(amount, )

    return total:"""

    """def calculate(amount, use): #amount = amount left, used = biggest power of 2 used previously
        if amount == 0:
            return 1;
        total = 0
        for i in range(used+1, amount):
            if int(math.log(i, 2)==math.log(i, 2)):
                for j in range(amount, -1, -i):
                    total+=calculate(j, i)
        return total
        if amount == 0:
            return 1
        elif amount < 0:
            return 0
        elif use > amount:
            return 0
        else:
            for i in range(use+1, amount):
                if int(math.log(i, 2)) == math.log(i, 2):
                    return calculate(amount-i, i)+calculate(amount, i+1)

    return calculate(amount, 0)"""

    def partition(n, m):
        if n < 0:
            return 0
        elif n == 0:
            return 1
        elif m == 0:
            return 0
        else:
            return partition(n-m, m)+ partition(n, m//2)

    for i in range(amount, 0, -1):
        if int(math.log(i, 2)) == math.log(i, 2):
            return partition(amount, i);

#print(count_change(7))
#print(count_change(10))
#print(count_change(4));
#print(count_change(7))
###################
# Extra Questions #
###################

from operator import sub, mul

def make_anonymous_factorial():
    """Return the value of an expression that computes factorial.

    >>> make_anonymous_factorial()(5)
    120
    >>> from construct_check import check
    >>> check(HW_SOURCE_FILE, 'make_anonymous_factorial', ['Assign', 'AugAssign', 'FunctionDef', 'Recursion'])
    True
    """
    #return lambda x:  if x == 5 else mul(x,  'YOUR_EXPRESSION_HERE'
