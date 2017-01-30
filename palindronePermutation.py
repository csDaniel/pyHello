#!/usr/bin/python

import collections

# this will work at O(n), but will fail with special characters.
def palindronePermutation(phrase):
	singleSolo = 0	
	pmap = collections.Counter(phrase)
	
	for letter in pmap:
		if pmap[letter] is 1:
			singleSolo += 1
			if singleSolo > 1:
				return False
	return True

	# this will work at I think O(n) and disregards any non-alphabetical characters
def pp(phrase):
	singleSolo = 0	
	pmap = collections.Counter(''.join(e for e in phrase if e.isalpha()))
	
	for letter in pmap:
		if pmap[letter] is 1:
			singleSolo += 1
			if singleSolo > 1:
				return False
	return True


def testSuite():
  tests = "kayak", "adobo", "wee", "us", "a man, a plan, a canal, panama!"
  
  for a in tests:
    #print("Testing {}:\t{}".format(a, palindronePermutation(a)))
    print("Testing {}:\t{}".format(a, pp(a)))

testSuite()