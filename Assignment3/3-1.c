#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 256
// got pointers from daniel loyd and mariah mcrae, just psuedocode though.
struct IntArray 
{
	int length;
	int *dataPtr;
};

enum EXIT_CODES
{
	INVALID_POINTER = -1,
	BAD_DATA = -2
};

struct IntArray* IntArray_Malloc(int size) 
{
//copied from lab3
	struct IntArray *returnValue = NULL;
	returnValue = (struct IntArray *)malloc(sizeof(struct IntArray));
	returnValue->length = size;
	returnValue->dataPtr = (int *) malloc (sizeof(int) * size);
	if(returnValue->dataPtr == NULL)
	{
		fprintf(stderr, "Malloc Failed\n");
		exit(BAD_DATA);
	}
	for(int i=0; i<size; i++) 
	{
		returnValue->dataPtr[i] = 0;
	}
	return returnValue;
}

void IntArray_Free(struct IntArray **ptr) 
{
//copied from lab3
	if((ptr != NULL) && ((*ptr) != NULL) && ((*ptr)->dataPtr != NULL))
	{
		for(int i=0; i< (*ptr)->length; i++)
		{
			(*ptr)->dataPtr[i] = 0;
		}
		free((*ptr) -> dataPtr);
		(*ptr)->dataPtr = 0;
		(*ptr)->length = 0;
		free((*ptr));
		(*ptr) = 0;
	}
	else 
	{
		fprintf(stderr, "Error in IntArray_Free, BadPointer found.\n");
		exit(INVALID_POINTER);
	}
} 

void readIntArray(struct IntArray *array)
{
//scanf reads in the int and atoi parses it into the appropriate int and saves it in the correct index 
	for(int i=0; i<array->length; i++)
	{
		char buff[BUFFER_SIZE];
		printf("Enter int: ");
		scanf("%s", buff);
		int num = atoi(buff); 
		array->dataPtr[i]=num;
	}		
}

void swap(int *xp, int *yp)
{
//copied from lecture slides
	int t0 = *xp;
	int t1 = *yp;
	*xp = t1;
	*yp = t0;
}

void sortIntArray(struct IntArray *array)
{ // weirdly enough I actually got this algorithm of bubble sort from my CIS313 textbook
	int l = array->length;
	for (int i = 0; i<l-1; i++)
	{
		for(int j = i+1; j<l; j++)
		{
			if(array->dataPtr[i] > array->dataPtr[j])
			{
				swap(&array->dataPtr[i], &array->dataPtr[j]);
			}
		}
	}
}

void printIntArray(struct IntArray *array)
{
//not sure if it really matters just a quick and dirty way of printing this out.
	printf("[");
	for(int i =0; i<array->length;i++)
	{
		printf("%d ", array->dataPtr[i]);
	}
	printf("]\n");
}

int main(void) 
{
	char buff[BUFFER_SIZE];
	int count;
	printf("Enter Array length: ");
	scanf("%s", buff);
	count = atoi(buff);
	struct IntArray *array = IntArray_Malloc(count);
	readIntArray(array);
	sortIntArray(array);
	printIntArray(array);
	IntArray_Free(&array);

}	
