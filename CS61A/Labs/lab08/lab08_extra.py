def make_advanced_counter_maker():
    """Makes a function that makes counters that understands the
    messages "count", "global-count", "reset", and "global-reset".
    See the examples below:

    >>> make_counter = make_advanced_counter_maker()
    >>> tom_counter = make_counter()
    >>> tom_counter('count')
    1
    >>> tom_counter('count')
    2
    >>> tom_counter('global-count')
    1
    >>> jon_counter = make_counter()
    >>> jon_counter('global-count')
    2
    >>> jon_counter('count')
    1
    >>> jon_counter('reset')
    >>> jon_counter('count')
    1
    >>> tom_counter('count')
    3
    >>> jon_counter('global-count')
    3
    >>> jon_counter('global-reset')
    >>> tom_counter('global-count')
    1
    """
    "*** YOUR CODE HERE ***"
    global_count = 0
    def make_counter():
        count = 0      
        def counter(action):
            nonlocal count, global_count
            if action == 'count':
                count+=1
                return count
            elif action == 'global-count':
                global_count+=1
                return global_count
            elif action == 'reset':
                count = 0
            elif action == 'global-reset':
                global_count = 0
       
        return counter
   
    return make_counter

def trade(first, second):
    """Exchange the smallest prefixes of first and second that have equal sum.

    >>> a = [1, 1, 3, 2, 1, 1, 4]
    >>> b = [4, 3, 2, 7]
    >>> trade(a, b) # Trades 1+1+3+2=7 for 4+3=7
    'Deal!'
    >>> a
    [4, 3, 1, 1, 4]
    >>> b
    [1, 1, 3, 2, 2, 7]
    >>> c = [3, 3, 2, 4, 1]
    >>> trade(b, c)
    'No deal!'
    >>> b
    [1, 1, 3, 2, 2, 7]
    >>> c
    [3, 3, 2, 4, 1]
    >>> trade(a, c)
    'Deal!'
    >>> a
    [3, 3, 2, 1, 4]
    >>> b
    [1, 1, 3, 2, 2, 7]
    >>> c
    [4, 3, 1, 4, 1]
    """
    m, n = 1, 1

    "*** YOUR CODE HERE ***"
    deal = False
    min_sum = 1000000
    for i in range(1, len(first)):
        for j in range(1, len(second)):
            if sum(first[:i]) == sum(second[:j]):
                deal = True
                if sum(first[:i]) < min_sum:
                    m = i 
                    n = j
                    min_sum = sum(first[:i])

    if deal: 
        first[:m], second[:n] = second[:n], first[:m]
        return 'Deal!'
    else:
        return 'No deal!'

def boom(n):
    sum = 0
    a, b = 1, 1 
    while a <= n*n:
        while b <= n*n:
            sum += (a*b)
            b += 1
        b = 0
        a += 1
    return sum

def remove_duplicates(lnk):
    if lnk == Link.empty or lnk.rest == Link.empty:
        return lnk
    else:
        if lnk.first == lnk.rest.first
            #lnk.first = lnk.rest.first
            lnk.rest = lnk.rest.rest
            remove_duplicates(lnk)
            return lnk
        else:
            remove_duplicates(lnk.rest)
            return lnk

