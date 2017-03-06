###########
# Mobiles #
###########

def tree(root, branches=[]):
    for branch in branches:
        assert is_tree(branch), 'branches must be trees'
    return [root] + list(branches)

def root(tree):
    return tree[0]

def branches(tree):
    return tree[1:]

def is_tree(tree):
    if type(tree) != list or len(tree) < 1:
        return False
    for branch in branches(tree):
        if not is_tree(branch):
            return False
    return True

def is_leaf(tree):
    return not branches(tree)

def mobile(left, right):
    """Construct a mobile from a left side and a right side."""
    return tree(None, [left, right])

def sides(m):
    """Select the sides of a mobile."""
    return branches(m)

def side(length, mobile_or_weight):
    """Construct a side: a length of rod with a mobile or weight at the end."""
    return tree(length, [mobile_or_weight])

def length(s):
    """Select the length of a side."""
    return root(s)

def end(s):
    """Select the mobile or weight hanging at the end of a side."""
    return branches(s)[0]

def weight(size):
    """Construct a weight of some size."""
    assert size > 0
    "*** YOUR CODE HERE ***"
    return tree(size, [])

def size(w):
    """Select the size of a weight."""
    "*** YOUR CODE HERE ***"
    return root(w)

def is_weight(w):
    """Whether w is a weight, not a mobile."""
    "*** YOUR CODE HERE ***"

    if root(w):
        return True
    else:
        return False
        

def examples():
    t = mobile(side(1, weight(2)),
               side(2, weight(1)))
    u = mobile(side(5, weight(1)),
               side(1, mobile(side(2, weight(3)),
                              side(3, weight(2)))))
    v = mobile(side(4, t), side(2, u))
    return (t, u, v)


def total_weight(m):
    """Return the total weight of m, a weight or mobile.

    >>> t, u, v = examples()
    >>> total_weight(t)
    3
    >>> total_weight(u)
    6
    >>> total_weight(v)
    9
    """
    if is_weight(m):
        return size(m)
    else:
        return sum([total_weight(end(s)) for s in sides(m)])

#t, u, v = examples()
#print(total_weight(t))
#print(total_weight(u))
#print(total_weight(v))
def balanced(m):
    """Return whether m is balanced.

    >>> t, u, v = examples()
    >>> balanced(t)
    True
    >>> balanced(v)
    True
    >>> w = mobile(side(3, t), side(2, u))
    >>> balanced(w)
    False
    >>> balanced(mobile(side(1, v), side(1, w)))
    False
    >>> balanced(mobile(side(1, w), side(1, v)))
    False
    """
    "*** YOUR CODE HERE ***"
    left = sides(m)[0] #side(1,v)
    right = sides(m)[1] #side(1, w)
    right_weight = total_weight(end(right)) #total_weight(v)
    left_weight = total_weight(end(left)) #total_weight(w)
    right_torque = right_weight * length(right) 
    left_torque = left_weight * length(left)
    #print(right_torque, right_torque, left_weight, right_weight)
    if left_torque == right_torque:
        left_res = True
        right_res = True
        if not is_weight(end(left)):
            left_res = balanced(end(left))
        if not is_weight(end(right)): 
            right_res = balanced(end(right))
        return right_res and left_res
    else:
        return False
#t, u, v = examples()
#w = mobile(side(3, t), side(2, u))
#print(balanced(mobile(side(1, v), side(1, w))))

def with_totals(m):
    """Return a mobile with total weights stored as the root of each mobile.

    >>> t, _, v = examples()
    >>> root(with_totals(t))
    3
    >>> print(root(t))                           # t should not change
    None
    >>> root(with_totals(v))
    9
    >>> [root(end(s)) for s in sides(with_totals(v))]
    [3, 6]
    >>> [root(end(s)) for s in sides(v)]         # v should not change
    [None, None]
    """
    """t = mobile(side(1, weight(2)),
               side(2, weight(1)))
    u = mobile(side(5, weight(1)),
               side(1, mobile(side(2, weight(3)),
                              side(3, weight(2)))))
    v = mobile(side(4, t), side(2, u))"""
    "*** YOUR CODE HERE ***"
    left_side = sides(m)[0]
    right_side = sides(m)[1]
    left = None
    right = None
    if is_weight(end(left_side)):
        left = left_side
    else:
        left = side(length(left_side), with_totals(end(left_side)))
    if is_weight(end(right_side)):
        right = right_side
    else:
        right = side(length(right_side), with_totals(end(right_side)))

    return tree(total_weight(m), [left, right])

############
# Mutation #
############

def make_withdraw(balance, password):
    """Return a password-protected withdraw function.

    >>> w = make_withdraw(100, 'hax0r')
    >>> w(25, 'hax0r')
    75
    >>> w(90, 'hax0r')
    'Insufficient funds'
    >>> w(25, 'hwat')
    'Incorrect password'
    >>> w(25, 'hax0r')
    50
    >>> w(75, 'a')
    'Incorrect password'
    >>> w(10, 'hax0r')
    40
    >>> w(20, 'n00b')
    'Incorrect password'
    >>> w(10, 'hax0r')
    "Your account is locked. Attempts: ['hwat', 'a', 'n00b']"
    >>> w(10, 'l33t')
    "Your account is locked. Attempts: ['hwat', 'a', 'n00b']"
    """
    "*** YOUR CODE HERE ***"
    locked = 0
    wrong_passwords = []
    bal = balance
    def withdraw(amount, attempt):
        
        nonlocal locked, wrong_passwords, bal
        
        if locked >= 3:
            return "Your account is locked. Attempts: " + str(wrong_passwords)
        elif attempt != password:
            locked+=1
            wrong_passwords.append(attempt)
            return 'Incorrect password'
        elif attempt == password:
            if bal < amount:
                return 'Insufficient funds'
            else:
                bal = bal-amount
                return bal

    return withdraw 

def make_joint(withdraw, old_password, new_password):
    """Return a password-protected withdraw function that has joint access to
    the balance of withdraw.

    >>> w = make_withdraw(100, 'hax0r')
    >>> w(25, 'hax0r')
    75
    >>> make_joint(w, 'my', 'secret')
    'Incorrect password'
    >>> j = make_joint(w, 'hax0r', 'secret')
    >>> w(25, 'secret')
    'Incorrect password'
    >>> j(25, 'secret')
    50
    >>> j(25, 'hax0r')
    25
    >>> j(100, 'secret')
    'Insufficient funds'

    >>> j2 = make_joint(j, 'secret', 'code')
    >>> j2(5, 'code')
    20
    >>> j2(5, 'secret')
    15
    >>> j2(5, 'hax0r')
    10

    >>> j2(25, 'password')
    'Incorrect password'
    >>> j2(5, 'secret')
    "Your account is locked. Attempts: ['my', 'secret', 'password']"
    >>> j(5, 'secret')
    "Your account is locked. Attempts: ['my', 'secret', 'password']"
    >>> w(5, 'hax0r')
    "Your account is locked. Attempts: ['my', 'secret', 'password']"
    >>> make_joint(w, 'hax0r', 'hello')
    "Your account is locked. Attempts: ['my', 'secret', 'password']"
    """
    "*** YOUR CODE HERE ***"

    def wdraw(amount, attempt):
        if attempt == old_password or attempt == new_password:            
            return withdraw(amount, old_password)
        else: 
            return withdraw(amount, attempt)
    result = withdraw(0, old_password)
    if type(result) == str:
        return result
    else: 
        return wdraw


"""w = make_withdraw(100, 'hax0r')
w(25, 'hax0r')
make_joint(w, 'my', 'secret')
j = make_joint(w, 'hax0r', 'secret')
w(25, 'secret')
j(25, 'secret')
print(j(25, 'hax0r'))
print(j(100, 'secret'))
j2 = make_joint(j, 'secret', 'code')
print(j2(5, 'code'))
print(j2(5, 'secret'))
"""