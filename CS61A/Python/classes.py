# class = template for all objects whose type is that class
#object = instance of some particular class
#built-in classes

#instantiating the class = creating a new object
#attribute = name-value pair associated with the object, accessible by dots
#instance attributes = instance variables or fields, properties
#methods = selector, constructor, mutator

"""
class <name>:
		<suite>
"""
class Account:
	interest = 0.02 #class attribute
	def __init__(self, account_holder):
		self.balance = 0
		self.holder = account_holder
	def deposit(self, amount):
		self.balance = self.balance+ amount
		return self.balance
	def withdraw(self, amount):
		if amount > self.balance:
			return "insufficient"
		else:
			self.balance = self.balance - amount
			return self.balance
#To evaluate a dot expression:
class CheckingAccount(Account):
	withdraw_charge = 1;
	interest = 0.01
	def withdraw(self, amount):
		return Account.withdraw(self, amount+ self.withdraw_charge)
		
'''Evaluate the <expression> to the left of the dot, which yields the object of the dot expression.
<name> is matched against the instance attributes of that object; if an attribute with that name exists, its value is returned.
If <name> does not appear among instance attributes, then <name> is looked up in the class, which yields a class attribute value.
That value is returned unless it is a function, in which case a bound method is returned instead.'''
#constructor
#two formal parameters = bound to one argument passed to class account_holder. balance = 0
#first one self is bound to newly created Account object. account_holder = bound to argument 
a = Account('Kirk')
#weee creates an instance
print(a.balance)
print(a.holder)

#mutable values = can reference same value
c = a
print(c.balance)
print(c is a)

#built in function

spock_account = Account('Spock')
spock_account.deposit(100)
print(getattr(spock_account, 'balance'))
print(hasattr(spock_account, 'deposit'))

# function vs method
# Account.deposit = function #attribute of class #two argument function
# spock_account.deposit = method #method = one argument function'

Account.deposit(spock_account, 1001)
spock_account.deposit(1000)
print(spock_account.balance)
#makes sense 
#f it names an attribute in the class, return the attribute value.
#Otherwise, look up the name in the base class, if there is one.
#okay so that .account.deposit(spock_) #got it maeks senese so account.deposit(self, 1001)
#okay so account.deposit(spock_asdlkajsldk, ajsldaskd)
#CamelCase

#parent class and super class = base class, 
#child class = subclass

#inherits but may override certain attributes

#python resolves name from left to right

class SavingsAccount(Account):
	deposit_charge = 2
	def deposit(self, amount):
		return Account.deposit(self, amount-self.deposit_charge)

class AsSeenonTVAccount(CheckingAccount, SavingsAccount):
	def __init__(self, account_holder):
		self.holder = account_holder
		self.balance = 1
such_a_deal = AsSeenonTVAccount("john")

print(such_a_deal.balance)
[c.__name__ for c in AsSeenOnTVAccount.mro()]
#multiple recurence allowed left toright in same layer, asseen on tv account checking account savings account, account, object