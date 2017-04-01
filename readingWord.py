#!/bin/usr/python

import olefile
from docx import Document
import sys, os
import subprocess

def lines():
	print("-----------------------")

#http://python-docx.readthedocs.io/en/latest/api/document.html#coreproperties-objects
def file_is_docx(filename):
	print("Opening as DOCX: {}".format(filename))
	doc = []
	content = Document(filename)
	for p in content.paragraphs:
		#print p.text
		doc.append(p.text)
	return ''.join(doc)

#https://www.tutorialspoint.com/python/os_pipe.htm
def file_is_doc(filename):
	print("Opening as DOC: {}".format(filename))

	r, w = os.pipe()

	processid = os.fork()
	doc = ''
	if processid:
		#parent process
		os.close(w)
		r = os.fdopen(r)
		#print("Parent reading")
		doc = r.read()
		#print ("text = {}".format(doc))
		#sys.exit(0)
	else:
		# child process
		os.close(r)
		w = os.fdopen(w, 'w')
		#print ("Piping in {}".format(filename))
		#content = subprocess.call("antiword %s" % filename, shell = True)
		command_line = ["antiword", filename]
		#contents = subprocess.Popen(command_line, stdout=subprocess.PIPE)
		contents = subprocess.check_output(command_line)
		#contents = subprocess.call(("antiword %s" %filename, shell=True), stdout=subprocess.PIPE)
		#w.write(str(subprocess.call("antiword %s" %filename, shell = True), stdout=subprocess.PIPE)))
		w.write(str(contents))
		w.write('')
		#w.write("test written by child...")
		w.close()
		#print "child bye"
		sys.exit(0)
	return doc

def display_contents(loc, contents):
	print("Filename: {}".format(loc))
	print("Contents: {}".format(contents))


def main_suite():
	lines()

	print sys.argv
	for doc in sys.argv[1:]:
		if doc[-1] == 'x':
			#docx file
			ret = file_is_docx(doc)
			display_contents(doc, ret)
		else:
			ret = file_is_doc(doc)
			display_contents(doc, ret)
main_suite()