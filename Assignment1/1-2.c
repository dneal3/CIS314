#include <stdio.h>

unsigned int combine(unsigned int x, unsigned int y){
	unsigned int a = x >> 24;
	a = a << 24;
	// format x to OxAA000000
	unsigned int c = y << 8;
	c = c >> 8;
	// format y to 0x00AABBCC
	unsigned int remix = a | c;
	// Should essentially combine the two in order to create the new hex number
	printf("0x%X\n", remix);
	return remix;
}
int main(void){
	combine(0x12345678, 0xABCDEF00);
	combine(0xABCDEF00, 0x12345678);
}
	
