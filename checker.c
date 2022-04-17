#include <stdlib.h>
#include <stdio.h>
#include "checker.h"

int how_many_slots(int pick, int *arr, int rows, int col){
		int i, j, tot;
			tot=0;
				for (i=0; i<rows; i++){
					               for (j=0; j<col; j++){
							                      if ( arr[i*col +j]==pick){
										      	       	   tot=tot+1;
												   	       	   printf("col %d:row %d ", j, i);}}}
					printf("\n");
						return tot;}
