/*************************************************************************
*   <Implement tail command>
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
		
	FILE *fp;
	int n, count, len, j = 1;
	char c=' ', a[128];
	
	/*************************************************** Option --help **************************************************************/
	
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
			
	/********************************************** ./project file.txt print last 10 lines***************************************/
		
	if(argc == 2) {
		n= 10;
		fp=fopen(argv[1], "r");
		if(!fp) {
				
			printf("./head: cannot open '%s' for reading: No such file or directory\n", argv[3]);
		}
		fseek(fp, 0L, SEEK_END);
		len = ftell(fp);
		fseek(fp, 0L, SEEK_SET);
		while((c = fgetc(fp)) != EOF) {
			if(c =='\n') {
				j++;
				continue;
			}
		}
		fseek(fp, 0L, SEEK_SET);
		int lines = j - 1;
		n = j - n - 1;
		j = 1;
		if(n > j) { 
			while((c=fgetc(fp)) != len) {
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
			while((c=fgetc(fp)) != len) {
				printf("%c",c);
				count++;
				if(c =='\n') {
					if(j == lines - 1) {
						break;
					}
					count = 1;
					j++;
				}
			}
		}
		
	}
		
	/**********************************************Option -n --lines=[-]NUM*********************************************************/
		
	if(argc == 4 && strcmp(argv[1],"-n") == 0) {
		n= atoi(argv[2]);
		fp=fopen(argv[3], "r");
		if(!fp) {		
			printf("./head: cannot open '%s' for reading: No such file or directory\n", argv[3]);
		}
		fseek(fp, 0L, SEEK_END);
		len = ftell(fp);
		fseek(fp, 0L, SEEK_SET);
		while((c = fgetc(fp)) != EOF) {
			if(c =='\n') {
				j++;
				continue;
			}
		}
		fseek(fp, 0L, SEEK_SET);
		int lines = j - 1;
		n = j - n - 1;
		j = 1;
		if(n > j) { 
			while((c=fgetc(fp)) != len) {
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
			while((c=fgetc(fp)) != len) {
				printf("%c",c);
				count++;
				if(c =='\n') {
					if(j == lines - 1) {
						break;
					}
					count = 1;
					j++;
				}
			}
		}
		
	}
		
	/*************************************************************Option -v ********************************************************/
		
	if(argc == 3 && strcmp(argv[1],"-v") == 0) {
		n= 10;
		fp=fopen(argv[2], "r");
		if(!fp) {
			
			printf("./head: cannot open '%s' for reading: No such file or directory\n", argv[3]);
		}
		printf("==> %s <==\n", argv[2]);
		fseek(fp, 0L, SEEK_END);
		len = ftell(fp);
		fseek(fp, 0L, SEEK_SET);
		while((c = fgetc(fp)) != EOF) {
			if(c =='\n') {
				j++;
				continue;
			}
		}
		fseek(fp, 0L, SEEK_SET);
		int lines = j - 1;
		n = j - n - 1;
		j = 1;
		if(n > j) { 
			while((c=fgetc(fp)) != len) {
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
			while((c=fgetc(fp)) != len) {
				printf("%c",c);
				count++;
				if(c =='\n') {
					if(j == lines - 1) {
						break;
					}
					count = 1;
					j++;
				}
			}
		}
		
	}
		
	/*****************************************************Option -f append file****************************************************/
		
	if(argc == 3 && strcmp(argv[1],"-f") == 0) {
		n= 10;
		fp=fopen(argv[2], "r");
		if(!fp) {
				
			printf("./head: cannot open '%s' for reading: No such file or directory\n", argv[3]);
		}
		fseek(fp, 0L, SEEK_END);
		len = ftell(fp);
		fseek(fp, 0L, SEEK_SET);
		while((c = fgetc(fp)) != EOF) {
			if(c =='\n') {
				j++;
				continue;
			}
		}
		fseek(fp, 0L, SEEK_SET);
		int lines = j - 1;
		n = j - n - 1;
		j = 1;
		if(n > j) { 
			while((c=fgetc(fp)) != len) {
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
			while((c=fgetc(fp)) != len) {
				printf("%c",c);
				count++;
				if(c =='\n') {
					if(j == lines - 1) {
						break;
					}
					count = 1;
					j++;
				}
			}
		}
		fp=fopen(argv[2],"a");
		if(fp) {
			while(scanf("%s",a) != -1) {
				fprintf(fp,"%s\n",a);
			}
			fclose(fp);
		}
		
	}
		
	/*********************************************************** Option -q *********************************************************/
		
	if(argc == 3 && (strcmp(argv[1], "-q") == 0)) {
		n= 10;
		fp=fopen(argv[2], "r");
		if(!fp) {
			printf("./head: cannot open '%s' for reading: No such file or directory\n", argv[3]);
		}
		fseek(fp, 0L, SEEK_END);
		len = ftell(fp);
		fseek(fp, 0L, SEEK_SET);
		while((c = fgetc(fp)) != EOF) {
			if(c =='\n') {
				j++;
				continue;
			}
		}
		fseek(fp, 0L, SEEK_SET);
		int lines = j - 1;
		n = j - n - 1;
		j = 1;
		if(n > j) { 
			while((c=fgetc(fp)) != len) {
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
			while((c=fgetc(fp)) != len) {
				printf("%c",c);
				count++;
				if(c =='\n') {
					if(j == lines - 1) {
						break;
					}
					count = 1;
					j++;
				}
			}
		}
	}
		
	/************************************************************Option -c ******************************************************/
		
	if(argc == 4 && strcmp(argv[1],"-c")==0) {	
		fp=fopen(argv[3], "r");
		if(!fp) {
			printf("./head: cannot open '%s' for reading: No such file or directory\n", argv[3]);
		}
		n= atoi(argv[2]);
		fseek(fp, 0L, SEEK_END);
		len = ftell(fp);
		n = len - n; 
		fseek(fp, 0L, SEEK_SET);
		if(n>0) {
			count = 0;
			while(count < n) {
				fseek(fp,count,SEEK_SET);
				count++;
			}
			while(count < len) {
			fseek(fp,count,SEEK_SET);
			printf("%c",fgetc(fp));
			count++;
			}
		}
		
	}
	return 0;
}
