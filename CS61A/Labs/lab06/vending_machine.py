def vending_machine(snacks):
    """Cycles through list of snacks.

    >>> vender = vending_machine(('chips', 'chocolate', 'popcorn'))
    >>> vender()
    'chips'
    >>> vender()
    'chocolate'
    >>> vender()
    'popcorn'
    >>> vender()
    'chips'
    >>> other = vending_machine(('brownie',))
    >>> other()
    'brownie'
    >>> vender()
    'chocolate'
    """
    "*** YOUR CODE HERE ***"
    counter = 0
    def cycle():
        nonlocal counter
        counter+=1
        counter %= len(snacks)
        return snacks[counter-1]
    return cycle