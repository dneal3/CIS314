#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Worked with Daniel Loyd and Mariah McRae.
struct c_block 
{
    unsigned int valid;
    unsigned int tag; // should we just save the address here and then use our operations to find the offset, set, and tag from this?
    unsigned char value[4];
};

unsigned int getOffset(unsigned int address)
{
    unsigned int offset = 0x00000003 & address;
    return offset; 
}

unsigned int getSet(unsigned int address)
{
    unsigned int set = (0x0000003c & address) >> 2;
    return set;
}

unsigned int getTag(unsigned int address)
{
    unsigned int tag = (0xFFFFFFc0 & address) >> 6; // do i need to shift this by 6?
    return tag;
}
void printBytes(unsigned char *start, int len) {
	for(int i=0;i<len; ++i){
		printf("%.2x ", start[i]);
	}
	printf("\n");
}

void printInt(int x, int offset){ // the modification to this was irrelevant but ima just leave it
	printBytes((unsigned char *) &x, offset+1);
}
void write_helper(struct c_block *cache)
{
	char address[16]; // so we can just use the buffer as an address
	char value[16]; // value to be set to member value
	printf("Enter 32-bit unsigned hex address: ");
	fgets(address, 16, stdin);
	printf("Enter 32-bit unsigned hex value: ");
	fgets(value, 16, stdin);
	int adr = (int)strtol(address, NULL, 16);
	int val = (int)strtol(value, NULL, 16);
	unsigned int setadr = getSet(adr);
	unsigned int settag = getTag(adr);
	if(strlen(cache[setadr].value) != 0)
	{
		unsigned int val1 = (int)strtol(cache[setadr].value, NULL, 0);
		printf("evicted set: %d - tag: %d valid: 1 - value: ", setadr, settag);
		printInt(val1, 3); 
	}
	// got strcpy idea from stackoverflow
	strcpy(cache[setadr].value, value);	
	cache[setadr].valid = 1;
	cache[setadr].tag = settag;
	unsigned int set = setadr;
	printf("wrote set: %d - tag: %d - valid: 1 - value: ", setadr, settag);
	printInt(val, 3);
}

void read_helper(struct c_block *cache) 
{
	char address[16]; // so we can just use the buffer as an address
	printf("Enter 32-bit unsigned hex address: ");
	fgets(address, 16, stdin);
	int adr = (int)strtol(address, NULL, 16);
	unsigned int setadr = getSet(adr);
	unsigned int settag = getTag(adr);
	unsigned int offset = getOffset(adr);
	printf("looking for set: %d - tag: %d\n", setadr, settag);
	if(strlen(cache[setadr].value) != 0)
	{
		unsigned int val1 = (int)strtol(cache[setadr].value, NULL, 16);
		printf("found set: %d - tag: %d - offset %d - valid: 1 - value: ", setadr,settag , offset);
		switch(offset)
		{
			case 0:
				printInt(val1, 0);
				break;
			case 1:
				val1 = val1 & 0x0000ff00;
				val1 = val1 >> 8;
				printf("%x\n", val1);
				break;
			case 2:
				val1 = val1 & 0x00ff0000;
				val1 = val1 >> 16;
				printf("%x\n", val1);
				break;
			case 3:
				val1 = val1 & 0xff000000;
				val1 = val1 >> 24;
				printf("%x\n", val1);	
				break;	
		} 
		if(cache[setadr].tag != settag)
		{
			printf("tags don't match - miss!\n");
		}
		else{
		printf("hit!\n");
		}
	}
	else
	{
		printf("no valid set found - miss!\n");
	}

}

void print_helper(struct c_block *cache)
{
	int n = sizeof(cache);
	for( int i=0;i<n; i++)
	{
		if(cache[i].valid == 1)
		{
			
			printf("set: %d - tag: %d - valid: 1 - value: ", i, cache[i].tag);
		unsigned int val = (int)strtol(cache[i].value, NULL, 16);
		printInt(val, 3);
		}	
	}
}
int main(void) 
{
    char buffer[256];
    char c;
    struct c_block *cache = (struct c_block*) malloc(16*sizeof(struct c_block));
    do {
        printf("Enter 'r' for read, 'w' for write, 'p' for print, 'q'to quit: ");
        fgets(buffer, 256, stdin);
        c = buffer[0];
        if (c == 'w'){
			write_helper(cache);  
        }else if (c == 'r'){
            read_helper(cache);   
        }else if (c == 'p'){
            print_helper(cache);
        }
    }while(c != 'q');
}


