#include <stdio.h>
#define N 4
typedef int array_t[N][N];
int dim()
{
    return N;
}
void f(array_t a, int x, int y)
{
    for(int i = 0; i < dim(); ++i)
    {
        for(int j = 0; j < dim(); ++j)
        {
            a[i][j] = i * x * y + j;
        }
    }
}

void f_opt(array_t a, int x, int y)
{
    int len = dim();
    int i,j;
    int xy = x*y;
    int *origin = &a[0][0]; // use pointer logic because its faster
    for (i = 0; i<len; i++)
    {
        int ixy = i*xy; 
        for(j=0; j<len; j++)
        {
            int *ptr1 = origin + (i*len+j); // offset
            *ptr1 = ixy + j; // a[i][j] = i*x*y + j 
        } 
    }
}
// from my project 4-2
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
    print_array(a);
    int x = 1;
    int y = 2;
    f(a, x, y);
    print_array(a);
    array_t b;
    print_array(b);
    f_opt(b, x, y);
    print_array(b);   
}
