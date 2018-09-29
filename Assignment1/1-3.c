#include <stdio.h>

unsigned int replace(unsigned int x, int i, unsigned int y){
	unsigned int q = 0xFF << (i<<3);
	unsigned int p = 0xFFFFFFFF ^ q;
	unsigned int replace = y << (i<<3);
	unsigned int a = x & p;
	a =  a|replace;
	printf("0x%08X\n", a);
	return a;

}

int main(void){
	replace(0x12345678, 0, 0xAB);
	replace(0x12345678, 2, 0xAB);

// This was my thought process im going to leave it here for studying purposes, I'm not certain I need to source this, but someone on piazza asked about this question and the person that replied gave us a hint and so did the instructor, those were the only outside materials i used for this problem.
/*
	int i =2;
	unsigned int q = 0xFF << (i<<3);
	unsigned int p = 0xFFFFFFFF ^ q;
	unsigned int replace = 0xAA << (i<<3);
	unsigned int b = 0x12345678;
	unsigned int a = b & p;
	a =  a|replace;
	printf("0x%08X\n" , q);
	printf("0x%08X\n" , p);
	printf("0x%08X\n" , replace);
	printf("0x%08X\n" , a);
	return 0;
*/	

	
}
