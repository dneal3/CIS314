#include <stdio.h>

int ge(float x, float y) {
	unsigned ux = *((unsigned*) &x); // convert x raw bits
	unsigned uy = *((unsigned*) &y); // convert y raw bits
	//printf("ux1: 0x%08X\n", ux);
	//printf("uy1: 0x%08X\n", uy);
	unsigned sx = ux >> 31; // extract sign bit of ux	
	unsigned sy = uy >> 31; // extract sign bit of uy 
	//printf("sx: 0x%08X\n", sx);
	//printf("sy: 0x%08X\n", sy);   
	ux <<= 1; // drop sign bit of ux
	uy <<= 1; // drop sign bit of uy
	//printf("ux2: 0x%08X\n", ux);
	//printf("uy2: 0x%08X\n", uy);	
	// TODO: return using sx, sy, ux, uy

	int pvn = (sx < sy); // if sx < sy then its always greater than the other because sx is pos and sy is neg
	//printf("pvn: %d\n", pvn);
	int pos = ((sx == 0) & (sy == 0)) & (ux >= uy); // in the case that this is two positive numbers take the bigger one
	//printf("pos: %d\n", pos);
	int neg = ((sx==1) & (sy==1)) & (ux <= uy); // in the case that there are two negatives take the smaller one
	//printf("neg: %d\n", neg);
	int zero = (ux | uy) == 0; // cancels differentiation between 0.0 and -0.0
	//printf("zero: %d\n", zero);
	int end = pos | neg | zero | pvn ; // really only one or two of these should ever be true because this problem can be broken down to 4 questions which I have outlined by explaining my reasoning behind each of the 4 variable checks.
	printf("%d\n", end);
	return end;

	
}

int main(void) {
	ge(0.0f, 0.0f);
	ge(-0.0f, 0.0f);
	ge(-1.0f, 0.0f);
	ge(0.0f, 1.0f);
	ge(1.0f, 0.0f);
	ge(0.0f, -1.0f);
}
