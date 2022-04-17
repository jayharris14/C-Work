#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (){
     int pid, pid2, pid3, choice, ret, ret2, ret3;

     int status;

         choice=0;
		while (choice!=4){
			printf("1- working directory\n");
			printf("2- cd to new directory\n");
			printf("3- ls directory\n");
			printf("4- exit\n");
			scanf("%d", &choice);
         		if (choice==1){
         			pid2=fork();
         			if (pid2==-1){
					printf("fork failed\n");
					exit(status);}
				if (pid2==0){
					char *arg[2];
					arg[0]="pwd";
					arg[1]=NULL;
					ret=execvp("pwd", arg);
				}
				if (pid2>0){
					wait(&status);
				}
			}
			if (choice==2){
				printf("where would you like to go ");
				char place[32];
				scanf("%s", place);
				ret3=chdir(place);
			}
	 		if (choice==3){
        			pid3=fork();
                		if (pid3==-1){
                        		printf("fork failed\n");
                        		exit(status);
				}
                		if (pid3==0){
                       			char *arg2[2];
					arg2[0]="ls";
					arg2[1]=NULL;
                        		ret2=execvp("ls", arg2);
				}
                		if (pid3>0){
                        		wait(&status);
				}
			}
		}
		return 0;
	
 } 