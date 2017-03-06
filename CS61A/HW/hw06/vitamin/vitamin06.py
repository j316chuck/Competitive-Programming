def make_counter():
    """Return a counter function.

    >>> c = make_counter()
    >>> c('a')
    1
    >>> c('a')
    2
    >>> c('b')
    1
    >>> c('a')
    3
    >>> c2 = make_counter()
    >>> c2('b')
    1
    >>> c2('b')
    2
    >>> c('b') + c2('b')
    5
    """
    "*** YOUR CODE HERE ***"
    #dictionary have mutable values not keys
    mystring = {}
    def counter(s):
        nonlocal mystring
        if s in mystring:
            mystring[s] = mystring[s]+1;
            return mystring[s]
        else:
            mystring[s] = 1;
            return mystring[s]
    return counter

def make_fib():
    """Returns a function that returns the next Fibonacci number
    every time it is called.

    >>> fib = make_fib()
    >>> fib()
    0
    >>> fib()
    1
    >>> fib()
    1
    >>> fib()
    2
    >>> fib()
    3
    >>> fib2 = make_fib()
    >>> fib() + sum([fib2() for _ in range(5)])
    12
    """
    "*** YOUR CODE HERE ***"
    fib_1 = 0; fib_2 = 0;
    def fib():
        nonlocal fib_1, fib_2
        if fib_1 == 0 and fib_2 == 0:
            fib_1 = 1
            return fib_2
        else:
            fib_1, fib_2 = fib_1+fib_2, fib_1;
            return fib_2
    return fib 

class Account:
    """An account has a balance and a holder.

    >>> a = Account('John')
    >>> a.deposit(10)
    10
    >>> a.balance
    10
    >>> a.interest
    0.02

    >>> a.time_to_retire(10.25) # 10 -> 10.2 -> 10.404
    2
    >>> a.balance               # balance should not change
    10
    >>> a.time_to_retire(11)    # 10 -> 10.2 -> ... -> 11.040808032
    5
    >>> a.time_to_retire(100)
    117
    """

    interest = 0.02  # A class attribute

    def __init__(self, account_holder):
        self.holder = account_holder
        self.balance = 0

    def deposit(self, amount):
        """Add amount to balance."""
        self.balance = self.balance + amount
        return self.balance

    def withdraw(self, amount):
        """Subtract amount from balance if funds are available."""
        if amount > self.balance:
            return 'Insufficient funds'
        self.balance = self.balance - amount
        return self.balance

    def time_to_retire(self, amount):
        """Return the number of years until balance would grow to amount."""
        assert self.balance > 0 and amount > 0 and self.interest > 0
        "*** YOUR CODE HERE ***"
        counter = 0;
        balance = self.balance
        #print(balance) 
        #print(balance, amount)
        while balance < amount:
            #print(balance, amount)
            counter+=1
            balance = balance * Account.interest + balance
        return counter
#a = Account('John')
#a.deposit(10)
#print(a.balance)
#print(a.time_to_retire(12))
class FreeChecking(Account):
    """A bank account that charges for withdrawals, but the first two are free!

    >>> ch = FreeChecking('Jack')
    >>> ch.balance = 20
    >>> ch.withdraw(3)    # First one's free
    17
    >>> ch.withdraw(100)  # And the second
    'Insufficient funds'
    >>> ch.balance
    17
    >>> ch.withdraw(3)    # Ok, two free withdrawals is enough
    13
    >>> ch.withdraw(3)
    9
    >>> ch2 = FreeChecking('John')
    >>> ch2.balance = 10
    >>> ch2.withdraw(3) # No fee
    7
    >>> ch.withdraw(3)  # ch still charges a fee
    5
    """
    withdraw_fee = 1
    free_withdrawals = 2

    "*** YOUR CODE HERE ***"
    def withdraw(self, amount):
        if self.balance < amount and self.free_withdrawals > 0:
            self.free_withdrawals-=1
            return 'Insufficient funds'
        elif self.balance < amount and self.free_withdrawls == 0:
            return 'Insufficient funds'
        elif self.free_withdrawals > 0:
            self.free_withdrawals = self.free_withdrawals-1
            self.balance -= amount
            return self.balance
        else:
            self.balance = self.balance-amount-self.withdraw_fee 
            return self.balance