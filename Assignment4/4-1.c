#include <stdio.h>

/*
Worked closely with Mariah McRae, and Daniel Loyd on this problem. 
loop:
	pushl %ebp // saves ebp register
	movl %esp, %ebp // moves the value of esp to ebp
	pushl %esi // save esi register
	pushl %ebx // save ebx register

	movl 8(%ebp), %esi // int x stored in esi register
	movl 12(%ebp), %ecx // int y stored in ecx register
	movl $2, %edx // mask assignment?, mask = 2
	movl $-1, %eax // result assignment, result = -1
.L2:
	movl %esi, %ebx // ebx register = x 
	andl %edx, %ebx // ebx register = ebx & mask
	xorl %ebx, %eax	// result ^= ebx register
	sall %cl, %edx // mask <<= y because y is shorter a small value only the "least significant byte" matters for this calculation 
	cmpl $1, %edx // mask > 1
	jg .L2 // tells the compare to use the greater than function as the condition for going back to the start of the loop
	
	popl %ebx // reverts ebx back to previous scope
	popl %esi // restore register back to prev scope
	popl %ebp // restores frame pointer
	ret	// returns value store in eax, result
*/

int loop(int x, int y) 
{
	int result = -1;
	for(int mask = 2; mask > 1 ; mask <<= y )
	{
		result ^= (x & mask);
	}
	return result;
}

int main(void) 
{
	printf("%d\n",loop(1,5));
	printf("%d\n",loop(2,3));
	printf("%d\n",loop(3,3));
	printf("%d\n",loop(4,2));
	printf("%d\n",loop(5,1));
}
