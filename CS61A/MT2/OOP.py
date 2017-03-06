a class serves as a template for its instances

class <name>:
	<suite>

class Clown:
	nose = 'big and red'

	def dance():
		return 'No thanks'
Clown.nose

Clown.dance

Clown

a = Account('Jim')
a.holder
a.balance


When a class is called

a new instane of that class is created
the __init__ method of the class is called with the new object as its first argument (named self)

class Account:
	def __init__(self, account_holder):
		self.balance = 0
		self.holder = account_holder

c = a 
assignment does not create a new object

getattr(tom_acount, 'balance')
hasattr(tom_account, 'deposit')
may return instance attributes or attributes of its class

class CheckingAccount(Account):
	withdraw_fee = 1
	interest = 0.01
	def withdraw(self, amount):
		return Account.withdraw(self, amount+self.withdraw_fee)
		return super().withdraw(amount+self.withdraw_fee)

I think I get classes pretty easy e rev pretty easy review :)

pretty easy review :)
1. withdraw(self, amount):
	self.amount+
	etc.
2.	super().withdraw(amount+self.withdraw_fee)
	calls class above its
3.	Account.withdraw(self, amount+self.withdraw_fee)

4. Create functions in class, methods in object instances

5. Account.withdraw(spock, amount+self.withdraw_fee)
6. hasattr(oject, 'string')
7. getattr('object', 'string')
change in instance does not change class attributes
instance attribute first
8. self references instance object

9.inheritance
goes to upper class, 
then left to right

