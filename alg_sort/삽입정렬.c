#include <stdio.h>

int main(void){
	
	int i,j,key;
	int arr[10] = {2,10,6,8,9,7,5,4,1,3};
	
	for(i=1;i<10;i++){
		key = arr[i];
		j = i - 1;
		
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		
		arr[j+1] = key;
	}
	
	for(i=0;i<10;i++){
	printf("%d ",arr[i]);
	}
	return 0;
}
