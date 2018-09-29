#include <stdio.h>

int sum(int from, int to)
{
	int result = 0;
	do 
	{
		result+=from;
		from++;
	} while (from <= to);
	return result;
}

int sum_asm(int from, int to)
{
	int result = 0;
	// Ensure that argument *from* is stored in %ecx, 
	// argument *to* is in %edx, *result* is in %eax - do not modify
	__asm__("movl %0, %%ecx # from in ecx;" :: "r" ( from ));
	__asm__("movl %0, %%edx # to in edx;" :: "r" ( to ));
	__asm__("movl %0, %%eax # result in eax;" :: "r" ( result ));

	// Your IA32 code goes below - comment each instruction...
	
	__asm__(
	"LOOP:;" // sets up the loop
	"addl %ecx, %eax;" // adds from to result stores in result
	"addl $1, %ecx;" // increments from
	"cmpl %edx, %ecx;" // compares to see it it needs to go back through again
	"jle LOOP;"); // takes it back to the top
	// Ensure that *result* is in %eax for return - do not modify.
	__asm__("movl %%eax, %0 #result in eax;" : "=r" ( result ));
	return result;
		
}	

int main(void)
{	
	//printf("%d\n", sum(1,6));
	printf( "%d\n", sum_asm(1,6));
	printf( "%d\n", sum_asm(3,5));
	return 0;
}
