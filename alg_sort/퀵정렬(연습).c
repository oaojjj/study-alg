#include <stdio.h>
#include <stdlib.h>
#define max 10

void QuickSort(int data[],int start,int end){
	
	int index,i;
	
	if(start<=end){
		index = Partition(data,start,end);
		
		for(i=0;i<max;i++)
			printf("%d ",data[i]);
		printf("\n");
	
		QuickSort(data,start,index-1);
		QuickSort(data,index+1,end);
	}
	else
		return;
}

int Partition(int data[],int start,int end){
	int pivot = data[end];
	int index = start;
	int c , i, tmp;
	
	for(i=start; i<end; i++){
		if(data[i] <= pivot){
			printf("swap ! %d %d\n",data[i],data[index]);
			tmp = data[i];
			data[i] = data[index];
			data[index]=tmp;
			index++;
			
		}
	}
	
	tmp = data[index];
	data[index] = data[end];
	data[end] = tmp;
	
	printf("swap !! %d %d\n",data[index],data[end]);
	
	return index;
}

int main(void){
	
	int data[10] = {4, 3, 10, 6, 8, 7, 9, 1, 2, 5};
	int i;
	
	QuickSort(data,0,max-1);
	
	printf("\n-------Result--------\n\n");
	for(i=0;i<max;i++){
	printf("%d ",data[i]);
	}
	
	return 0;
}
