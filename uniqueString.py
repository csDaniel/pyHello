#!/usr/bin/python

def uniqueString(input):
	#O(n log n)
	sortedInput = sorted(input)

	#O(n)
	for current in range(0,len(sortedInput)-1):
		if sortedInput[current] == sortedInput[current + 1]:
			if sortedInput[current] is not " ":
				return False

	return True

	
def testSuite():
	cases = "beasto", "hot dog", "baracuda", "lol", "the quick brown fox jumped over the lazy dog", "big cat orf", "Lel"
	
	for case in cases:
		print ("Input Test: {}".format(case))
		print ("{}".format(str(uniqueString(case))))

testSuite()	


