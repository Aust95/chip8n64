#include <stdio.h>

void load_rom(void)
{
	printf("LOAD ROM: TODO IMPLEMENTATION\n");

	FILE *fp;
	int MAX_FILESIZE = 512;
	char data[MAX_FILESIZE];
	fp = fopen("rom.ch8", "r");
	if(fp != NULL){
		fgets(data, MAX_FILESIZE, fp);
		printf("%s\n",data);
	}	
}