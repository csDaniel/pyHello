#include <stdio.h>
#include <stdlib.h>

class MyClass{
	public:
		int val;
		void set_x(int val) {
			x = val;
		}
	protected:
		static int x;
};

class MyNew: public MyClass {
	public:
		int return_val() {
			return val;
		}
		int return_x( const MyNew &mn) {
			return mn.x;
		}
	protected:
		int y;
};


int main(int argc, char *argv[]) {
	printf("Hello World\n");

	MyClass g;
	g.val = 45;
	printf("G: %d\n",g.val);


	MyClass *h = (MyClass*)malloc(sizeof(MyClass));
	h->val = 55;
	printf("H: %d\n",h->val);

	free(h);

	MyNew b;
	b.val = 12;
	int a = b.return_val();
	printf("B: %d\n",a);

	MyClass c;
	MyNew d;
	c.set_x(5);
	//d.y = d.x;
	printf("d.y= %d\n",d.return_x());
	



	return 0;
}