#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t read_file(FILE *fp){
	uint32_t buf[10];
	int k = fread(buf, 1, 4, fp);
	if(k!=4){
		printf("error");
		exit(1);
	}
	uint32_t n = ntohl(*buf);
	fclose(fp);
	return n;
}

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;

	if(argc < 3)
	{
        	printf("error");
        	exit(1);
    	}	
    	if(!(fp1 = fopen(argv[1], "r")))
    	{
        	printf("file1 open error\n");
        	exit(1);
    	}
    	if(!(fp2 = fopen(argv[2], "r")))
    	{
        	printf("file2 open error\n");
        	exit(1);
    	}
    	uint32_t n1 = read_file(fp1);
	uint32_t n2 = read_file(fp2);
	uint32_t sum = n1 + n2;
	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", n1, n1, n2, n2, sum, sum);
}
