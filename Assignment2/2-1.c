#include <stdio.h>

int mask(int n){
	int i = n - 1; // cant shift by 32 so if the input is 32 you just slice one off so its a 31 bit shift which is defined
	int r = (-1 << i);
	r = ~(r << 1); // follow the 31 bit shift by another shift to complete the shift so that it is defined and not value to get the results we are looking for
	printf("0x%X\n", r);
	return r;
}

int main(void){	
	mask(1);
	mask(2);
	mask(3);
	mask(5);
	mask(8);
	mask(16);
	mask(32);
}
