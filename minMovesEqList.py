#!/bin/usr/python
from datetime import datetime

class Solution(object):

	def minMoves(self, nums):
		min_moves = 0
		if nums:
			while len(set(nums)) > 1:
				#print (nums)
				current_max = nums.index(max(nums))
				for n in range(len(nums)):
					if n != current_max:
						nums[n] += 1
				min_moves += 1

		#print nums
		return min_moves

	def minMoves2(self, nums):

		min_moves = 0
		if nums:
			while min(nums) != max(nums):
				print nums
				current_max = nums.index(max(nums))
				for n in range(len(nums)):
					if n != current_max:
						nums[n] += 1
				min_moves += 1

		#print nums
		return min_moves










def test_suite():
	sol = Solution()
	'''
	tests = [
			[1,2,3],
			[1,2,3,4],
			[1,2,3,4,5]
	]

	for n in tests:
		a = datetime.now()
		print("Result:{}".format(sol.minMoves(n)))
		b = datetime.now()
		print ("Runtime: {}".format((b-a).microseconds))
	'''
	tests = [
			[1,2,3],
			[1,2,3,4],
			[1,2,3,4,5]
	]
	for n in tests:
		a = datetime.now()
		print("Result:{}".format(sol.minMoves2(n)))
		b = datetime.now()
		print ("Runtime: {}".format((b-a).microseconds))


	n = [1,2147483647]
	#print("Result:{}".format(sol.minMoves(n)))

test_suite()