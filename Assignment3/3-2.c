#include <stdio.h>

int decode(int x, int y, int z)
{
	/* 
	movl 12(%ebp), %edx
	subl 16(%ebp), %edx
	movl %edx, %eax
	sall $31, %eax
	sarl $31, %eax
	imull 8(%ebp), %edx
	xorl %edx, %eax
	*/
	int edx = y;
	edx = edx - z;
	signed int eax = edx;
	eax = eax << 31;
	eax = eax >> 31;
	edx = edx * x;
	eax = eax ^ edx;
	printf("%d\n",eax);
	return eax;
}

int main(void) 
{
	decode(1, 2, 4); // -2
	decode(-4, -8, -12); // -16
}

