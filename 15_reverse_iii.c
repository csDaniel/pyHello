/* ********************************************************
*
*	url: https://leetcode.com/problems/reverse-words-in-a-string-iii/#/description
*	
*	desc: Given a string, you need to reverse the order of characters in each word within 
*	a sentence while still preserving whitespace and initial word order.
*
*	ex: 
*	Input: "Let's take LeetCode contest"
*	Output: "s'teL ekat edoCteeL tsetnoc"
*
*
******************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <string.h>


// reverses a string by reversing each word found in the string itself. 
// pre: line is a non-zero length string. reverse will be memset
// post: sets reverse to be the correct returned reverse string.
void reverse_string(char *line, char *reverse);

// testing harness to test and compare the results produced by reverse_string()
void test_func();

// tests and compares. added to allow test_func() to look cleaner and handle input better
int call_test(char *test_string);

int main (int argv, char *argc[]) {
	test_func();

	return 0;
}

void test_func() {
	int res;

	res = call_test("Let's take LeetCode contest");

}

int call_test(char *test_string) {
	char first[256];
	char second[256];

	strcpy(first, test_string);
	reverse_string(first, second);


	int len = strlen(first) - 1;
	int space;
	char sp = ' ';
	int begin, end, step;
	begin = 0;


	int i;
	for (i = 0; i < len; i++) {
		if (first[i] == sp || first[i] == '\0') {
			// space found
			end = i - 1;
			step = 0;
			while ((begin + step) <= end) {
				if (first[begin + step] != second[end - step]) {
					printf("begin:%d, end:%d\n",begin, end);
					printf("not reversed\n");
					printf("first:\t %s\n",first);
					printf("second:\t %s\n",second);	
					return -1;		
				}
				step++;
			}
			begin = end + 2;
		}
	}

	printf("they match\n");
	return 0;

}

void reverse_string(char *line, char *reverse) {
	int start = 0;
	int end = 0;
	int loc = 0;
	char space = ' ';

	int i;
	for (i = 0; i <= strlen(line); i++) {
		if (line[i] == space || line[i] == '\0') {
			end = i - 1;
			loc = 0;
			while (start <= end) {
				reverse[start] = line[end-loc];
				loc++;
				start++;
			}
			reverse[start] = ' ';
			start++;
		}
	}

}













































