#!/usr/bin/python

#Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        
        if len(num1) > len(num2):
            big = num1
            small = num2
        else:
            big = num2
            small = num1
            
        answer = []

        carry = 0
        small_length = len(small) - 1
        for a in big[::-1]:
            #print("{}",format(answer))
            if small_length >= 0:
                temp = int(a) + int(small[small_length])
                small_length -= 1
            else:
                temp = int(a)
            temp += carry
            ans = temp % 10
            carry = temp / 10
            #answer.insert(0,ans)
            answer.append(ans)

        if carry > 0:
            #answer.insert(0,carry)
            answer.append(carry)

        answer.reverse()

        return ''.join(map(str, answer))
            
            


def main():
	test_cases = ["584", "55", "12", "0"]

	s = Solution()
	for a in xrange(0, len(test_cases), 2):
		ans = s.addStrings(test_cases[a], test_cases[a+1])
		print("answer: {}".format(ans))
main()







