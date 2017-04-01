#!/usr/bin/python

# operates in O(a) time. it iterates through only a
def oneAway(a, b):

	lettersChanged = 0
	la = 0 
	lb = 0
	
	if len(a) + 1 is len(b) or len(a) -1 is len(b) or len(a) is len(b):
		while la < len(a) -1 and lb < len(b) -1:
			if a[la] is not b[lb]:
				if la is 0 or lb is 0:
					#first char
					if a[la] is not b[lb + 1]:
						lettersChanged += 1
					
				elif la is len(a) or lb is len(b):
					# final char
					if a[la] is not b[lb - 1]:
						lettersChanged += 1
				else:
					if a[la] is not b[lb - 1] or a[la] is not b[lb + 1]:
						lettersChanged += 1
			la += 1
			lb += 1
		if lettersChanged > 1:
			return False
		else:
			return True
	else:
		return False
	
	
  
  
def testSuite():
	setA = "pale", "pales", "pale", "pale", "asdfg"
	setB = "ple", "pale", "bale", "bake", "asd"
	
	for a, b in zip(setA, setB):
		print("Testing {},{}:\t{}".format(a,b,oneAway(a,b)))
testSuite()