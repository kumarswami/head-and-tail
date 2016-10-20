#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc , char *argv[]) {
	FILE *fp;
	int count=1, j=1;
	
	char c;
	int n;
	
	/*if(fp == NULL) {
		
		printf("\n%s File can not open\n",argv[1]);
		return 1;
	}*/
	/*option n */
	if(argc == 3) {
	fp=fopen(argv[2], "r");
	if(strcmp(argv[1],"n") == 0) {
		while((c=fgetc(fp)) !=EOF){
			printf("%c",c);
			count++;
			if(c =='\n') {
				if(j == 10){
					break;
				}
			count = 1;
			j++;
			continue;
			}
			
		}
	}
	}
	/* option -n*/
	/* head -n 8 filename.txt */
	if(argc==4) {
	if(strcmp(argv[1],"-n") == 0) {
		fp=fopen(argv[3], "r");
		n= atoi(argv[2]);
		while((c=fgetc(fp)) !=EOF){
			printf("%c",c);
			count++;
			if(c =='\n') {
				if(j == n){
					break;
				}
			count = 1;
			j++;
			continue;
			}
			
		}
	}
        }
	fclose(fp);
	return 0;	
}

