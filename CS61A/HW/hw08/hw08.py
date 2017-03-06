
def deep_len(lst):
    """Returns the deep length of the list.

    >>> deep_len([1, 2, 3])     # normal list
    3
    >>> x = [1, [2, 3], 4]      # deep list
    >>> deep_len(x)
    4
    >>> x = [[1, [1, 1]], 1, [1, 1]] # deep list
    >>> deep_len(x)
    6
    >>> x = []
    >>> for i in range(100):
    ...     x = [x] + [i]       # very deep list
    ...
    >>> deep_len(x)
    100
    """
    "*** YOUR CODE HERE ***"
    #return sum([deep_len(i) if type(i) == lst else 1 for i in lst])
    """counter = 0
    for i in lst:
        if type(i) == list:
            counter += deep_len(i)
        else:
            counter += 1
    return counter"""

    return sum([deep_len(i) if type(i) == list else 1 for i in lst])