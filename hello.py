#!/usr/bin/python

import sys

def helloWorld():
	print ("hello world")
	print ("{}".format(sys.argv))
helloWorld()

def helloBack():
	print("{}".format(sys.argv[0]))
	print("{}".format(sys.argv[1]))
helloBack()