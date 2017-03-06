class Fib():
    """A Fibonacci number.

    >>> start = Fib()
    >>> start
    0
    >>> start.next()
    1
    >>> start.next().next()
    1
    >>> start.next().next().next()
    2
    >>> start.next().next().next().next()
    3
    >>> start.next().next().next().next().next()
    5
    >>> start.next().next().next().next().next().next()
    8
    """

    def __init__(self):
        self.value = 0

    def next(self):
        "*** YOUR CODE HERE ***"
        a = Fib()
        if self.value == 0:
            a.value = 1
            a.previous = 0
        else:
            a.value, a.previous = self.value + self.previous, self.value
        return a
            #print(self.value, self.previous)
    

    def __repr__(self):
        return str(self.value)

#start = Fib()
#print(start.next())
#print(start.value, start.previous)
#print(start.next().next())
#print(start.value, start.previous)

class VendingMachine:
    """A vending machine that vends some product for some price.

    >>> v = VendingMachine('candy', 10)
    >>> v.vend()
    'Machine is out of stock.'
    >>> v.restock(2)
    'Current candy stock: 2'
    >>> v.vend()
    'You must deposit $10 more.'
    >>> v.deposit(7)
    'Current balance: $7'
    >>> v.vend()
    'You must deposit $3 more.'
    >>> v.deposit(5)
    'Current balance: $12'
    >>> v.vend()
    'Here is your candy and $2 change.'
    >>> v.deposit(10)
    'Current balance: $10'
    >>> v.vend()
    'Here is your candy.'
    >>> v.deposit(15)
    'Machine is out of stock. Here is your $15.'

    >>> w = VendingMachine('soda', 2)
    >>> w.restock(3)
    'Current soda stock: 3'
    >>> w.deposit(2)
    'Current balance: $2'
    >>> w.vend()
    'Here is your soda.'
    """
    "*** YOUR CODE HERE ***"
    def __init__(self, candy, price):
        self.stock = 0
        self.price = price
        self.candy = candy
        self.cash = 0

    def restock(self, stock):
        self.stock+=stock
        return 'Current {0} stock: {1}'.format(self.candy, self.stock)
    
    def vend(self):
        if self.stock == 0:
            return 'Machine is out of stock.'
        elif self.cash < self.price:
            return 'You must deposit ${0} more.'.format(self.price-self.cash)
        elif self.cash == self.price:
            self.cash -= self.price
            self.stock = self.stock - 1
            return 'Here is your {0}.'.format(self.candy)
        else:
            prev = self.cash
            self.cash = 0;
            self.stock = self.stock - 1
            return 'Here is your {1} and ${0} change.'.format(prev-self.price, self.candy)

    def deposit(self, cash):
        if self.stock == 0:
            return 'Machine is out of stock. Here is your ${0}.'.format(cash)
        else:
            self.cash+=cash
            return 'Current balance: ${0}'.format(self.cash)

class MissManners:
    """A container class that only forward messages that say please.

    >>> v = VendingMachine('teaspoon', 10)
    >>> v.restock(2)
    'Current teaspoon stock: 2'

    >>> m = MissManners(v)
    >>> m.ask('vend')
    'You must learn to say please first.'
    >>> m.ask('please vend')
    'You must deposit $10 more.'
    >>> m.ask('please deposit', 20)
    'Current balance: $20'
    >>> m.ask('now will you vend?')
    'You must learn to say please first.'
    >>> m.ask('please hand over a teaspoon')
    'Thanks for asking, but I know not how to hand over a teaspoon.'
    >>> m.ask('please vend')
    'Here is your teaspoon and $10 change.'

    >>> double_fussy = MissManners(m) # Composed MissManners objects
    >>> double_fussy.ask('deposit', 10)
    'You must learn to say please first.'
    >>> double_fussy.ask('please deposit', 10)
    'Thanks for asking, but I know not how to deposit.'
    >>> double_fussy.ask('please please deposit', 10)
    'Thanks for asking, but I know not how to please deposit.'
    >>> double_fussy.ask('please ask', 'please deposit', 10)
    'Current balance: $10'
    """
    def __init__(self, obj):
        self.obj = obj

    def ask(self, message, *args):
        magic_word = 'please '
        if not message.startswith(magic_word):
            return 'You must learn to say please first.'
        "*** YOUR CODE HERE ***"
        """old = message.split()[1:]
        old_message = old[0]
        for i in range(1, len(old)):
            old_message = old_message + " " + old[i]
        message = message.split()[1]"""
        old_message = message.split()[1:]
        message = message.split()[1]
        #print(message)
        if hasattr(self.obj, message):
            func = getattr(self.obj, message)
            return func(*args)
        else:
            return 'Thanks for asking, but I know not how to {0}.'.format(' '.join(old_message))

"""v = VendingMachine('teaspoon', 10)
v.restock(2)
m = MissManners(v)
m.ask('vend')
print(m.ask('please vend'))
"""