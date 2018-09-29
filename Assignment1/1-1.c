#include <stdio.h>

void printBytes(unsigned char *start, int len) {
	for(int i=0;i<len; ++i){
		printf("%.2x", start[i]);
	}
	printf("\n");
}

void printInt(int x){
	printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x){
	printBytes((unsigned char *) &x, sizeof(float));
}

void printShort(short x){
	printBytes((unsigned char *) &x, sizeof(short));
}

void printLong(long x){
	printBytes((unsigned char *) &x, sizeof(long));
}

void printDouble(double x){
	printBytes((unsigned char *) &x, sizeof(double));
}

void main() {
	// some pretty interesting stuff happened here my output looked 	like this, in respective order, I don't know that this is 		technically right.

	printInt(5); // 05000000
	printFloat(5); // 0000a040
	printShort(5); // 0500
	printLong(5); // 0500000000000000
	printDouble(5); // 0000000000001440

	// I believe this has something to do with how much memory is used 		to store each so ints are 1B, floats are 1B, shorts a 1 "nibble", 		while Longs and doubles are stored with 2B. Not sure why the 		double value has the 144 in it, but I'm unfamiliar with how 		doubles are stored, so everthing could be fine.
}
	
