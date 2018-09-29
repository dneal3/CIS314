#include <stdio.h>
#include <time.h>

void inner(float *u, float *v, int length, float *dest)
{
    int i = 0;
    float sum = 0.0f;
    for(i=0; i< length; ++i)
    {
        sum += u[i] * v[i];
    }
    *dest = sum;
}

void inner2(float *u, float *v, int length, float *dest)
{
    int i = 0;
    float sum, sum1, sum2, sum3 = 0.0f;
    for(i=0;i<length;i+=4)
    {
        sum += u[i] * v[i];
        sum1 += u[i+1] * v[i+1];
        sum2 += u[i+2] * v[i+2];
        sum3 += u[i+3] * v[i+3];
    }
    for(;i<length;i++)
    {
        sum += u[i] * v[i];
    }
    *dest = sum + sum1 + sum2 + sum3;
}

int main(void) 
{
    float u = 1.0f;
    float v = 2.0f;
    float *u1 = &u;
    float *v1 = &v;
    int length = 3;
    float dest = 0.0f; 
    float *dest1 = &dest;
    clock_t start = clock();
    inner(u1, v1, length, dest1);
    // got this from stack overflow posted on piazza
    float diff = clock() - start;
    diff = diff * 1000 / CLOCKS_PER_SEC;
    printf("clock speed %f\n", diff/1000);
    start = clock();
    inner2(u1,v1,length,dest1);
    diff = clock() - start;
    diff = diff * 1000 / CLOCKS_PER_SEC;
    printf("clock speed %f\n", diff/1000);
}
