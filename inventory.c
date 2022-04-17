#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define SHARED_MEMORY_NAME "SHM_PRODUCER"
#define FALSE 0
#define TRUE 1


struct item{
        char  product[32];
};

struct total{
        int loaded;
        struct item array[10];
};




int flags;
int SHM_creator_status;
size_t size;
int fd;

struct total *mytotal;
int main(){
        flags= O_RDWR;
        mode_t permissions= S_IRUSR | S_IWUSR;
        size =sizeof(struct total);

        SHM_creator_status=TRUE;
        fd= shm_open(SHARED_MEMORY_NAME, flags, permissions);
        mytotal=(struct total*)mmap(NULL, size, PROT_READ | PROT_WRITE,  MAP_SHARED, fd, 0);

        if (fd==-1)
        {
                printf("shm_open failed\n");
                if (errno==EEXIST)
 {
                        SHM_creator_status=FALSE;
                        printf("SHM already exists... trying to connect to it now\n");

                        flags= O_RDWR;
                        fd=shm_open(SHARED_MEMORY_NAME, flags, permissions);
                        if (fd==-1)
                        {
                                printf("failed to open shared memory\n");                                       exit(1);
                        }
                }
                else
                {
                        printf("something's wrong\n");
                        exit(1);
                }
        }
        if (ftruncate(fd, size)!=0)
        {
                printf("ftruncate failed\n");
                exit(1);
        }

        if (mytotal==MAP_FAILED)
        {
                printf("mmap failed\n");
                exit(1);
        }


    
	        
        int i, j, k;
        char choice[32];
	j=0;
	while (j==0){
		printf("enter an option: display or exit \n");
		scanf("%s", choice);
		j=strcmp(choice, "display");
		if (j==0){
        		for (k=0; k<(9); k++)
			{
                	if(strcmp(mytotal->array[k].product, "")!=0){
			printf("%s\n", mytotal->array[k].product);
        		}	
		}}
		else{
			exit(1);
		}
	}
        return 0;

        }
        

                                                                                                                                                   