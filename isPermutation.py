#!/usr/bin/python

# http://stackoverflow.com/questions/10806866/counting-each-letters-frequency-in-a-string
import collections

def isPermutation(stringA, stringB):
	# mapping will take O(a + b)
	mapA = collections.Counter(stringA)
	mapB = collections.Counter(stringB)

	# im not sure on the runtime here
	if len(stringA.strip())- stringA.count(' ') is not len(stringB.strip()) - stringB.count(' '):
		return False

	# this will work in constant time, there is a finite number of characters to be stores O(1)
	for a in mapA:
		if mapA[a] is not mapB[a]:
			if a is not " ":
				return False
		else:
			return True





def testSuite():
	setA = "ba", "cat", "ogre", "cheese", "be ul"
	setB = "bat", "act", "gore", "ch:", "blue"
	
	for a, b in zip(setA, setB):
		print("Testing {}, {}".format(a,b))
		print("{}".format(isPermutation(a,b)))


testSuite()