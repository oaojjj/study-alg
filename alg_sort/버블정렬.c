#include <stdio.h>

int swap(int *num1, int *num2){
	int temp,i;
	
	temp=*num1;
	*num1=*num2;
	*num2=temp;
}
int main(void){
	
	int i,j,k;
	int array[10]={2,10,8,6,7,9,4,3,5,1};
	
	for(i=0;i<9;i++){
		for(j=0;j<9-i;j++){
			if(array[j]>array[j+1]){
				for(k=0;k<10;k++)
				printf("%d ", array[k]);
				printf("-> ");
				
				swap(&array[j],&array[j+1]);
				
				for(k=0;k<10;k++)
				printf("%d ", array[k]);
				printf("swap // %d %d\n",array[j+1],array[j]);	
				printf("\n");
				
			}
		}
	}
	printf("result = ");
	for(i=0;i<10;i++){
	printf("%d ",array[i]);	
	}
	
	return 0;
}
