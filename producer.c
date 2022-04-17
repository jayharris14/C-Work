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

void CleanUp();
int flags;
int SHM_creator_status;
size_t size;
int fd;
	
struct total *mytotal;
int main(){
	flags= O_RDWR | O_CREAT | O_EXCL;
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
				printf("failed to open shared memory\n");
				CleanUp();									exit(1);
			}
		}
		else
		{
			printf("something's wrong\n");
			CleanUp();
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
	

	signal(SIGINT, CleanUp);	
	int count;
	int i, j;
	char entry[32];
/*	struct total total1;
	struct item item1;*/
	mytotal->loaded=0;
	count=0;
	while (1){
		mytotal->loaded=mytotal->loaded;
		if (mytotal->loaded<10){
		printf("enter a product ");
		scanf("%s", entry);
		strcpy(mytotal->array[mytotal->loaded].product, entry);
		mytotal->loaded=(mytotal->loaded)+1;
		}
		else{
		mytotal->loaded=mytotal->loaded;}}
	
	return 0;

	}
	void CleanUp(){
		int status=munmap(mytotal, size);
		if (status!=0)
		{	
			printf("couldn't unmap shared memory\n");
		}

		status=close(fd);
		if (status!=0)
		{
			printf("couldn't close the shared memory\n");
		}

		status=shm_unlink(SHARED_MEMORY_NAME);
		if (status!=0)
		{
			printf("couldn't delete the shared memory\n");
		}

		printf("finished\n");
		exit(1);

	}
	
	

	