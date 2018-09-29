#include <stdio.h>
#define N 10
typedef int array_t[N][N];
/*
.L3: // beginning of inner for loop the j one
	movl (%edx), %esi // moving pointer from i index
	movl (%eax), %ecx // moving pointer from j index 
	addl $4, %eax // offsetting the i pointer by a value of i*n+j
	addl $40, %edx // offsetting j pointer by a value of j*n+i
	movl %esi, -4(%eax) // swapping the pointer values i->j
	movl %ecx, -40(%edx) // swapping pointer values j->i
	cmpl %ebx, %eax // does compare for loop conditional
	jne .L3 jumps back to the beginning of the for loop 
*/

void transpose_old(array_t a)
{
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<i;++j)
		{
			int t = a[i][j];
			a[i][j] = a[j][i];			
			a[j][i] = t;
		}	
	}
}
// used example from the book given in the assignment details and an example from the friday (2/9) lecture slides, as well as swap as an example to do this pointer arithmatic, I may have used a few extra variables than necessary they are just for clarity when I look back on this assignment
void transpose(array_t a)
{
	int temp, add1, add2;
	int *a0index = &a[0][0]; //marks the beginning of the offset location so it can be used in offsetting for the pointers
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<i;++j)
		{
			add1 = (i*N+j); //address of i index
			add2 = (j*N+i); //address of j index
			int* ptr1 = a0index + add1; // offset location for i
			int* ptr2 = a0index + add2; // offset location for j
			temp = *ptr1; //stores i index
			*ptr1 = *ptr2; // swaps value of i index to that of j index
			*ptr2 = temp; // stores i index in j index
			
		}
	}
}
// arbitrary print function so i could test my transpose_pointers
void print_array(array_t a)
{
	for (int i = 0;i<N;++i)	
	{
		printf("{ ");
		for(int j = 0;j<N;++j)
		{
			printf("%d ", a[i][j]);
		}	
		printf("}\n");
	}
	printf("\n");
}

int main(void)
{
	array_t a;
	print_array(a); // pre-transpose print
	transpose(a);
	print_array(a); // post-transpose print
}
