#include <stdio.h>

unsigned int extract(unsigned int x, int i){
	unsigned int shft = i << 3;
	unsigned int mask = 0xFF << shft;
	unsigned int iso = x & mask; // just re-did the masking that we did from the last project
	iso = iso >> shft;
	unsigned int b1 = x & 0x80000000;
	b1 = b1 >> 31;
	b1 = ~(b1-1);
	b1 = b1 >> 8;
	b1 = b1 << 8; // makes space for the or slide down
	unsigned int res = iso | b1; 
	printf("0x%08X\n", res);
	return res;	
	// I think I did this in the worst way possible but I'm going to leave it this way so that i can make a note to review and streamline it for the midterm review, it's functional... it's just poor coding.
}

int main(void){
	extract(0x12345678,0);
	extract(0xABCDEF00,2);

/*      this was my thought process on this one
	unsigned int x = 0xABCDEF00;
	unsigned int mask = 0xFF;
	unsigned int x1 = 0x12345678;
	unsigned int i = 0;
	unsigned int shft = i << 3;
	unsigned int p = mask << shft;
	unsigned int iso = x1 & p;
	iso = iso >> shft;
	unsigned int a = x1 & 0x80000000; 
	unsigned int b = a >> 31;
	b = ~(b-1);
	b = b >> 8;
	b = b << 8;
	unsigned int res = iso | b;
	printf("0x%08X\n", res);
*/
}

