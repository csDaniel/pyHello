#!/usr/bin/python

class rec(object):

	# compute the factorial of a number
	def factorial(self, num):
		if num is 1:
			return num
		else:	
			return num * (self.factorial(num-1))
		
	# computer the sum of natural numbers until N
	def natural(self, num):
		if num is 1:
			return num
		else:
			return num + (self.natural(num-1))
			
	# write a function for multiply(a,b) where a and b are both positive integers, but you can only use the + or − operators.
	def multiply(self, a, b):
		if a is 1:
			return b 
		else:
			return b + (self.multiply(a-1, b))
	
	# In the lecture, we discussed a method to raise a double to an integer power. In this question, write a recursive function that allows raising to a negative integer power as well.
	# A negative exponent means how many times to divide by the number. Example: 8-1 = 1 ÷ 8 = 1/8 = 0.125. Or many divides: Example: 5-3 = 1 ÷ 5 ÷ 5 ÷ 5 = 0.008.
	def raisepow(self, num, pow):
		
		if pow > 0:
			return num * (self.raisepow(num, pow-1))
		elif pow < 0:
			return (self.raisepow(num, pow+1) / num)
		else:
			return 1
	
	
	# Find Greatest Common Divisor (GCD) of 2 numbers using recursion.
	def gcd(self, a, b):
		if a < b:
			return self.gcd(a, b-a)
		elif a > b:
			return self.gcd(a-b, b)
		else:
			return a
	
	# Write a recursive function to reverse a string. Write a recursive function to reverse the words in a string, i.e., ”cat is running” becomes ”running is cat”.
	
	# . [Medium hard] A word is considered elfish if it contains the letters: e, l, and f in it, in any order. For example, we would say that the following words are elfish: whiteleaf, tasteful, unfriendly,
	# and waffles, because they each contain those letters. • Write a predicate function called elfish? that, given a word, tells us if that word is elfish or not.
	# • Write a more generalized predicate function called x-ish? that, given two words, returns true if all the letters of the first word are contained in the second.
	'''
	. [Hard example] Coin game: Alice and Bob are playing a game
	using a bunch of coins. The players pick several coins out of the
	bunch in turn. Each time a player is allowed to pick 1, 2 or 4 coins,
	and the player that gets the last coin is the winner. Assume that
	both players are very smart and he/she will try his/her best to
	work out a strategy to win the game. For example, if there are 2
	1
	coins and Alice is the first player to pick, she will definitely pick 2
	coins and win. If there are 3 coins and Alice is still the first player
	to pick, no matter she picks 1 or 2 coins, Bob will get the last coin
	and win the game. Given the number of coins and the order of
	players (which means the first and the second players to pick the
	coins), you are required to write a program to calculate the winner
	of the game, and calculate how many different strategies there are
	for he/she to win the game. You should use recursion to solve
	the problem, and the parameters are read from the command line.
	You can assume that there are no more than 30 coins.
	Here are some sample runs of the program:
	./pickcoin 1 alice bob
	alice 1
	./pickcoin 2 bob alice
	bob 1
	./pickcoin 3 alice bob
	bob 2
	./pickcoin 10 alice bob
	alice 22
	./pickcoin 25 alice bob
	alice 3344
	./pickcoin 30 alice bob
	bob 18272
	'''

# testing		
recurse = rec()

for x in range(1,10):
	print("{} factorial is {}".format(x, recurse.factorial(x)))

for x in range(1,10):
	print("{} natural sum is {}".format(x, recurse.natural(x)))
	
for x in range(1,5):
	for y in range(1,5):
		print("{} x {} = {}".format(x,y,recurse.multiply(x,y)))

for x in [a/10 for a in range(5, 50, 5)]:
	for y in range(-6,0):
		print ("{}^{} = {}".format(x,y,recurse.raisepow(x,y)))
'''
for x in range(20,100,3):
	for y in range(20, 100, 2):
		print("{} x {} = {}".format(x,y,recurse.gcd(x,y)))
'''
print("{} x {} = {}".format(252,105,recurse.gcd(252,105)))































