#!/usr/bin/python

import sys

def lines():
	print("-----------------")

# testing for hello world
def helloWorld():
	print ("hello world")
	print ("{}".format(sys.argv))

# testing for echo
def helloBack():
	print("{}".format(sys.argv[0]))
	print("{}".format(sys.argv[1]))

# testing for a fizzbuzz, for the first time ever!
# multiples of 3, fizz.
# multiples of 5, buzz
# for both, fizzbuzz
def fb(input):
	numTest = False

	# check if int or string. 
	if ( isinstance(input, str)  ):
		if (str.isdigit(input)):
			numTest = True
	
	if ( isinstance(input, int)):
		numTest = True
	
	if numTest:
		num = float(input)
		#print("Performing fizzbuzz on {}".format(num))
		
		if num % 3 == 0 and num % 5 == 0:
			print ("fizzbuzz")
		elif num % 3 == 0:
			print("fizz: {} / 3 = {}".format(num, (num / 3)))
		elif num % 5 == 0: 
			print("buzz: {} / 5 = {}".format(num, (num / 5)))
		else:
			print("{}".format(num))

# main control function to handle all these little functions
def main():
	helloWorld()
	lines()
	helloBack()
	lines()
	fb(sys.argv[1])
	lines()

	for i in range(1,101):
		fb(i)

main()


















