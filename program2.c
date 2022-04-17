#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	char band_name[64];
	char song_title[32];
	int year;
};

void fill_in_structs(struct data *array){
	char str1[64];
	char str2[32];
	char t, p;
	int year, i;
	for (i=0; i<3; i++){
		printf("enter band name: ");
		scanf("%[^\n]", str1);
	        strcpy(array[i].band_name, str1);
                printf("enter song title: ");
		scanf("%c",&t);
              	scanf("%[^\n]", str2);
		strcpy(array[i].song_title, str2);
	       	printf("enter year: ");
                scanf("%d", &year);
                array[i].year=year;
		scanf("%c", &t);

		
	}}

int find_band(struct data *array, char band[], int *lowyear){
	int found;
	found=0;
	int num, a, i, year, year2, check;
	a=0;
	num=0;
	while (num<3 && found!=1){
		check=strcmp(array[num].band_name,band);
		if (check==0){
			found=1;
			}
		else{
			num=num+1;}}

	*lowyear=array[0].year;
        for (i=1; i<3; i++){
                year2=array[i].year;
                if (year2<*lowyear){
                        *lowyear=year2;}}
	if (found==1){
		return 1;}
	else{
		return-1;}}


void dump_data(struct data *array){
	int i;
	for (i=0; i<3; i++){
		printf("%s\n", array[i].band_name);
		printf("%s\n", array[i].song_title);
		printf("%d\n", array[i].year);
		printf("=====\n");}
}

int main(){
	int lowyear;
	int x;
	char t;
	struct data array[3];
	fill_in_structs(array);
	char band[64];
        printf("enter a band to check: ");
        scanf("%[^\n]", band);
	scanf("%c", &t);
	x=find_band(array, band, &lowyear);
	printf("lowest year is %d\n",lowyear);
	if (x==1){
		printf("band is in array\n\n");}
	else{
		printf("band is not in array\n\n");}
	dump_data(array);
	return 0;
}
