from lab07 import *
#never assign if there is no return 
# Q6
def reverse_other(t):
    """Reverse the roots of every other level of the tree using mutation.

    >>> t = Tree(1, [Tree(2), Tree(3), Tree(4)])
    >>> reverse_other(t)
    >>> t
    Tree(1, [Tree(4), Tree(3), Tree(2)])
    >>> t = Tree(1, [Tree(2, [Tree(5, [Tree(7), Tree(8)]), Tree(6)]), Tree(3)])
    >>> reverse_other(t)
    >>> t
    Tree(1, [Tree(3, [Tree(5, [Tree(8), Tree(7)]), Tree(6)]), Tree(2)])
    """
    "*** YOUR CODE HERE ***"
    #if t.is_leaf():
    #    return 
    #t.branches = [b for b in t.branches]
    #t.branches.reverse()
    #for b in t.branches:
    #    if b.branches:
    #        reverse_other(b.branches)

    """def reverse_helper(t, need_reverse):
        if t.is_leaf():
            return 
        n 


    reverse_helper(t, True)"""
    #for b in t.branches:
    #    if b.branches is not Tree.empty:
    #        reverse_other(b.branches)
    #t i said i will ctch up :) :) :) and its all godo and i said hi and it was fun :)

    def reverse_helper(t, need_reverse):
        
        if t.is_leaf():
            return 
        
        if need_reverse is True:
            new_copy = [b.root for b in t.branches][::-1]
            for i in range(len(t.branches)):
                t.branches[i].root = new_copy[i]

        for b in t.branches:
           reverse_helper(b, not need_reverse)
        
        #new_labs = [child.root for child in t.branches][::-1]
        #for i in range(len(t.branches)):
        #   reverse_helper(t.branches[i], not need_reverse)
        #    if need_reverse:
        #        t.branches[i].root = new_labs[i]
    reverse_helper(t, True)

# Q7
def cumulative_sum(t):
    """Mutates t where each node's root becomes the sum of all entries in the
    corresponding subtree rooted at t.

    >>> t = Tree(1, [Tree(3, [Tree(5)]), Tree(7)])
    >>> cumulative_sum(t)
    >>> t
    Tree(16, [Tree(8, [Tree(5)]), Tree(7)])
    """
    "*** YOUR CODE HERE ***"

    if t.is_leaf():
        return 
    for b in t.branches:
        cumulative_sum(b)
    t.root += sum([b.root for b in t.branches])

# Q8
def deep_map_mut(fn, link):
    """Mutates a deep link by replacing each item found with the
    result of calling fn on the item.  Does NOT create new Links (so
    no use of Link's constructor)

    Does not return the modified Link object.

    >>> link1 = Link(3, Link(Link(4), Link(5, Link(6))))
    >>> deep_map_mut(lambda x: x * x, link1)
    >>> print_link(link1)
    <9 <16> 25 36>
    """
    "*** YOUR CODE HERE ***"
    if link is Link.empty:
        return
    else:
        deep_map_mut(fn, link.rest)
    if isinstance(link.first, Link):
        deep_map_mut(fn, link.first)
    else:
        link.first = fn(link.first)

# Q9
def has_cycle(link):
    """Return whether link contains a cycle.

    >>> s = Link(1, Link(2, Link(3)))
    >>> s.rest.rest.rest = s
    >>> has_cycle(s)
    True
    >>> t = Link(1, Link(2, Link(3)))
    >>> has_cycle(t)
    False
    >>> u = Link(2, Link(2, Link(2)))
    >>> has_cycle(u)
    False
    """
    "*** YOUR CODE HERE ***"
    """s = {link[0]}
    curr_link = Link(link[0])
    i = 0
    while i != len(link):
        i+=1
        curr_link = Link(curr_link, link[i])
        if curr_link in s:
            return True
        s.append(curr_link)
    return False"""
    #curr_link = Link(link.first)
    """s = {Link(link.first)}
    while link is not Link.empty:
        link = link.rest
        if link in s:
            return True
        s.add(link)
    return False
    """
    s = []
    while link is not Link.empty:
        if link in s:
            return True
        s.append(link)
        link = link.rest
    return False

def has_cycle_constant(link):
    """Return whether link contains a cycle.

    >>> s = Link(1, Link(2, Link(3)))
    >>> s.rest.rest.rest = s
    >>> has_cycle_constant(s)
    True
    >>> t = Link(1, Link(2, Link(3)))
    >>> has_cycle_constant(t)
    False
    """
    "*** YOUR CODE HERE ***"
    if link is Link.empty:
        return False
    slow = link
    fast = link.rest
    while fast is not Link.empty:
        if fast.rest == Link.empty:
            return False
        elif fast == slow or fast.rest == slow:
            return True
        else:
            slow = link.rest
            fast = fast.rest.rest
    return False

def insert(link, value, index):
    
    
    if index == 0:
        link.rest = Link(link.first, link.rest)
        link.first = value
    elif link is Link.empty:
        raise IndexError
    else:
        insert(link.rest, value, index-1)

def same_shape(t1, t2):
    
    if t1.is_leaf() and t2.is_leaf():
        return True
    
    if len(t1.branches) == len(t2.branches):
        for i in range(len(t1.branches)):
            if same_shape(t1.branches[i], t2.branches[i]) is False:
                return False
        return True

    else:
        return False

    #return len(t1.branches) == len(t2.branches) and 
     #   all(same_shape(st1, st2) for st1, st2 in zip(t1.branches, t2. branches)) 