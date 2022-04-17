#include <stdio.h>
#include <stdlib.h>


int read_data(int i_arr[], int x){
        FILE *infile;
        int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, j=0, k=0, i, dh, first, ch;
        infile=fopen("data.txt", "r");
        if (infile==NULL){
                printf("Error: unable to open file %s\n","data.txt");
                exit(1);}
        char nl;
	fscanf(infile, "%d%c", &ch, &nl);
	first=ch;
        for (i=0; i<x; i++){
                if (dh==0){
                        a=a+1;}
                if (dh==1){
                        b=b+1;}
                if (dh==2){
                        c=c+1;}
                if (dh==3){
                        d=d+1;}
                if (dh==4){
                        e=e+1;}
                if (dh==5){
                        f=f+1;}
                if (dh==6){
                        g=g+1;}
                if (dh==7){
                        h=h+1;}
                if (dh==8){
                        j=j+1;}
                if (dh==9){
                        k=k+1;}
		fscanf(infile, "%d%c", &dh, &nl);
        }
		i_arr[0]=a;
		i_arr[1]=b;
		i_arr[2]=c;
		i_arr[3]=d;
		i_arr[4]=e;
		i_arr[5]=f;
		i_arr[6]=g;
		i_arr[7]=h;
		i_arr[8]=j;
		i_arr[9]=k;

                fclose(infile);
                return first;}
void print_data(int i_arr[], int size){
	int i;
	for (i=0; i<10; i++){
		printf("%d:%d\n", i, i_arr[i]);
	}}

void print_favorites(int i_arr[], int num1, int num2){
	printf("%d was read in %d times from the data file\n", num1, i_arr[num1]);
	printf("%d was read in %d times from the data file", num2, i_arr[num2]);
}
int main(int argc, char* argv[]){
	int size;
	size=10;
        int i_arr[size];
        int  y;
        int x, num1, num2;
	x=atoi( argv[1]);
        y=read_data(i_arr, x);
	printf("%d\n", y);
	print_data(i_arr, size);
	printf("enter your two favorite single digit numbers \n");
	scanf("%d%d", &num1, &num2);
	print_favorites(i_arr, num1, num2);
        return 0;
        }
