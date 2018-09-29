#include <stdio.h>

int even(unsigned int x) {
	// learned about the bit masks from 1.3, and I figured that if I were to [and] the intial hex number against a mask hex number that could isolate all the even spaces (0x55555555, 5 = 0101), and from that if the new hex number was then not equal to zero then the number contained a '1' bit in an even index.
	unsigned int mask = 0x55555555;
	//printf("0x%08X\n", x);
	//printf("0x%08X\n", mask);
	unsigned int xmask = x & mask;
	//printf("0x%08X\n", xmask);
	int q = (xmask != 0x0);
	printf("%i\n",q);
	return q;
}

int main(void) {
	even(0x0);
	even(0x1);
	even(0x2);
	even(0x3);
	even(0xFFFFFFFF);
	even(0xAAAAAAAA);
	
}
