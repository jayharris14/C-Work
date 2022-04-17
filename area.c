#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double area=0;
struct t_arg{
	int numthreads;
	long id;
};
pthread_mutex_t my_lock;

void *calcarea(void* args){
	struct t_arg *myargs= (struct t_arg *) args;

	long myid= myargs->id;
	long nthreads=myargs->numthreads;

	double x, y, c, a, t, rectarea, total;
	a=160/nthreads;
	t=(myid+1)*a;
	x=t-a;
        c=(32/nthreads)*myid;

	for (x; x<t; x++){
		y=(2*c)+3;
		rectarea=.2*y;
		c=c+.2;
		total=total+rectarea;
	}
	pthread_mutex_lock(&my_lock);
	area=area+total;
	pthread_mutex_unlock(&my_lock);
	}

int main(int argc, char **argv){
	long *thread_ids;
	int nthreads;
	int i;
	pthread_mutex_init(&my_lock, NULL);

	if(argc!=2){
		fprintf(stderr, "usage: %s <n>\n", argv[0]);
		fprintf(stderr, "where <n> is the number of threads\n");

			return 1;
	}

	nthreads=strtol(argv[1], NULL, 10);

	pthread_t *thread_array=malloc(nthreads * sizeof(pthread_t));
	struct t_arg *thread_args= malloc(nthreads *sizeof(struct t_arg));
	
	for (i=0; i<nthreads; i++){
	thread_args[i].numthreads= nthreads;
	thread_args[i].id=i;
	}

	for (i=0; i<nthreads; i++){
	pthread_create(&thread_array[i], NULL, calcarea, &thread_args[i]);}

	for(i=0; i<nthreads; i++){
	pthread_join(thread_array[i], NULL);
	}

	free(thread_array);
	free(thread_args);
	printf("%f", area);
	pthread_mutex_destroy(&my_lock);
	pthread_exit(NULL);

	return 0;
	}






