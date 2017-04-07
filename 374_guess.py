#!/usr/bin/python

import sys

class Solution(object):
	def __init__(self):
		self.secret = 0;



	def guess_number(self, n):
		ans = 1
		low = 0
		high = n

		while ans is not 0:

			attempt = (high+low) / 2
			ans = self.guess(attempt)

			if ans is 1 :
				low = attempt+1
			if ans is -1:
				high = attempt-1
		return attempt

	def guess(self, num):
		if num > self.secret:
			return -1
		elif num < self.secret:
			return 1
		else:
			return 0


def main():

	# n, ans
	tests = [
		[10, 6],
		[100000, 9999],
		[5,5]
	]
	s = Solution()
	for test in tests:
		s.secret = test[1]
		print("Secret number: {}".format(s.secret))
		print("Answer is: {}".format(s.guess_number(test[0])))


main()