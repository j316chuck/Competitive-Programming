class Plant:
    def __init__(self):
        """A Plant has a Leaf, a list of sugars created so far,
        and an initial height of 1"""
        "*** YOUR CODE HERE ***"
        self.height = 1
        self.leaf = Leaf(self)
        self.alive = True
        self.materials = []

    def absorb(self):
        """Calls the Leaf to create sugar"""
        "*** YOUR CODE HERE ***"
        self.eaf.absorb()





    def grow(self):
        """A Plant uses all of its sugars, each of which increases
        its height by 1"""
        "*** YOUR CODE HERE ***"
        for sugar in self.materials:
            sugar.activate()
            self.height+=1



def reverse_link(lnk): 
    #if lnk.rest is Link.empty:
    #    return Link(lnk.first)
    #else:
    #    return Link(reverse_lnk(lnk.rest), link.first)
    def reverse_to(l, to):
        if l is Link.empty:
            return to
        else:
            return reverse_to(l.rest, Link(1.first, to))
    return reverse_to(l, Link.empty)

    def reverse_to(l, to):
        if l is Link.empty:
            return to
        else:
            return reverse_to(l.rest, Link(l.first,to))

    #new_head = lnk.rest
    #lnk.rest = reverse(new_head.rest)
    #new_head.rest = lnk 
    #return new_head
def reverse_link(l):
    res = Link.empty:
    while l is not Link.empty:
        res = Link(l.first, res):
        l = l.rest
    return res
def is_valid(t):
    return helper(t, float('inf'), float('-inf'))

def helper(t, left, right):
    if t is BinaryTree.empty:
        return true
    if t.entry > maxn or t.entry < minn:
        return False
    else:
        helper(t.right, t.entry, maxn):
        helper(t.left, minn, t.entry)

def flatten(t):
    if t is BinaryTree.empty:
        return Link.empty
    left_head = flatten(t.left)
    right_head = flatten(t.right)
    if left_head is not Link.empty:
        left_end = left_head
        while left_end.rest is not Link.empty:
            left_end = left_end.rest
    left_end.rest = Link(t.label, right_head)
    return left_head 

    if t is Binary Tree.empty:
        return Link.empty
    left_head = flatten(t.left)
    right_head = flatten(t.right)
    if left_head is not Link.empty:
        left_end = left_head
        while left_end.rest is not Link.empty:
            left_end = left_end.rest
    left_end.rest = Link(t.label, right_head)
    return left_head 
    
def merge_sorted(l1, l2):
    if l1 is Link.empty:
        return l2
    if l2 is Link.empty:
        return l1
    elif l1.first < l2.first:
        return Link(l1.first, merge_sorted(l1.rest, l2))
    else:
class Leaf:
    def __init__(self, plant): # plant is a Plant instance
        """A Leaf is initially alive, and keeps track of how many
        sugars it has created"""
        "*** YOUR CODE HERE ***"
        self.plant = plant
        self.alive = True
        self.sugars_used = 0

    def absorb(self):
        """If this Leaf is alive, a Sugar is added to the plant's
        list of sugars"""
        if self.alive:
             "*** YOUR CODE HERE ***"
	           self.plant.materials.append(Sugar(self, self.plant))

    def __repr__(self):
        return "|Leaf|"


class Sugar:
    
    sugars_created = 0

    def __init__(self, leaf, plant):
        "*** YOUR CODE HERE ***"
        Sugar.sugars_created+=1
        self.leaf = leaf
        self.plant = plant

    def activate(self):
        """A sugar is used"""
        "*** YOUR CODE HERE ***"
        self.leaf.sugars_used+=1
        self.plant.materials.remove(self)



    def __repr__(self):
        return "|Sugar|"



