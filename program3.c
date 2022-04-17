#include <stdio.h>
#include <stdlib.h>
#include "checker.h"

void fill_array(int *arr, int rows, int col){
	int i, j, t, v, tot;
	t=0;
	v=0;
	for (i=0; i<rows; i++){
	       for (j=0; j<col; j++){
	       	arr[i*col +j]=(i+j);}}}
			
	       
	       

void print_array(int *arr, int rows, int col){
	int i, j, r_n, c_n;
	char w;
	w=' ';
	r_n=rows*2;
	for (i=0; i<rows; i++){
		printf("\n");
		for (j=0; j<col; j++){
		printf("%d%c", arr[i*col +j], w); }}
	printf("\n");}



int main(){
	int col;
	int rows;
	int *i_array;
	int pick, slots;
	printf("enter number of rows: ");
	scanf("%d", &rows);
	printf("enter number of columns: ");
	scanf("%d", &col);
	i_array=malloc(sizeof(int) * (rows*col));
	if (i_array!=NULL){
		fill_array(i_array, rows,  col);}
	print_array(i_array, rows, col);
	printf("enter an int: ");
	scanf("%d", &pick);
	slots=how_many_slots(pick, i_array, rows, col);
	printf("%d appeared %d times", pick,  slots);
	free(i_array);
	i_array=NULL;

	
	return 0;
}


