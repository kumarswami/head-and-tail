/*************************************************************************
*   <Implement head command>
*   Copyright (C) 2017  Kumar Mahadayya Swami swamikm16.comp@coep.ac.in
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>
**************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc , char *argv[]) {
	
	FILE *fp;
	int count = 0, j = 1, len = 0;	
	char c, c1[1000]; 
	int n;
	
	/*********************************************************Option--help **************************************************************/
	
	if(argc == 2 && strcmp(argv[1],"--help") == 0) {
		
		FILE *fp;
		char c, *s="help.txt";
		fp = fopen(s,"r");
		
		if(fp == NULL) {
			
			printf("cann't open file");
			exit(0);
		}
		c=fgetc(fp);
		while(c != EOF) {
			
			printf("%c",c);
			c=fgetc(fp);
		}
		fclose(fp);
		return 0;	
	}
	
	/******************************************./project [filename] print by default first 10 lines ***************************************/
	
	if(argc == 2) {
		n= 10;
		fp=fopen(argv[1], "r");
			if(!fp) {
				
				printf("./head: cannot open '%s' for reading: No such file or directory\n", argv[3]);
			}
			// to find size of file.
			fseek(fp, 0L, SEEK_END);
			len = ftell(fp);
			fseek(fp, 0L, SEEK_SET);
			
			while((c=fgetc(fp)) != len) {
				
				printf("%c",c);
				count++;
				if(c =='\n') {
					
					if(j == n) {
						
						break;
					}
					count = 1;
					j++;
					continue;
				}
			
			}
		
	}
	
	/**************************************************** Option -n, --lines=[-]NUM *******************************************************/
	
	if(argc == 4) {
		
		if(strcmp(argv[1],"-n") == 0) {
			
			fp=fopen(argv[3], "r");
			if(!fp) {
				
				printf("./head: cannot open '%s' for reading: No such file or directory\n", argv[3]);
			}
			
			n= atoi(argv[2]);
			// to find size of file.
			fseek(fp, 0L, SEEK_END);
			len = ftell(fp);
			fseek(fp, 0L, SEEK_SET);
			
			while((c=fgetc(fp)) != len) {
				
				printf("%c",c);
				count++;
				if(c =='\n') {
					
					if(j == n) {
						
						break;
					}
					count = 1;
					j++;
					continue;
				}
			
			}
		}
		
		/********************************************** Option -c, --bytes=[-]NUM  ***************************************************/
		
		else if(strcmp(argv[1], "-c") == 0) {
			
			fp=fopen(argv[3], "r");
			if(!fp) {
				printf("./head: cannot open '%s' for reading: No such file or directory\n", argv[3]);
			}
			n= atoi(argv[2]);
			
			// to find size of file.
			
			fseek(fp, 0L, SEEK_END);
			len = ftell(fp);
			
			//printf("%d\n", len);
			
			fseek(fp, 0L, SEEK_SET);
			if(n>0) {
				
				while(count < n) {
					
					fseek(fp,count,SEEK_SET);
					printf("%c",fgetc(fp));
					count++;
				}
				printf("\n");
			}
		}
	}
	
	/*********************************************************** Option -q *****************************************************************/
		
	if(argc == 3 && strcmp(argv[1],"-q") == 0) {
			
		len = 10;
		fp=fopen(argv[2],"r"); 
			
		if(fp == NULL) {
				printf("./head: cannot open '%s' for reading: No such file or directory\n", argv[2]);
		}
			
		while(fgets(c1,sizeof(c1),fp) != NULL && count < len) {
			
			printf("%s", c1);
			count++;
		}
			//fclose(fp);
	}
		
	/*************************************************************** Option -v,*************************************************************/
		
	if(argc == 3 && strcmp(argv[1],"-v") == 0) {
	
		len = 10;
		fp=fopen(argv[2],"r"); 
			
		if(!fp) {
			printf("./head: cannot open '%s' for reading: No such file or directory\n", argv[3]);
		}
		printf("==> %s <==\n",argv[2]);
		
		while(fgets(c1,sizeof(c1),fp) != NULL && count < len) {
		    printf("%s", c1);
		    count++;
		}
	}	
	return 0;	
}

