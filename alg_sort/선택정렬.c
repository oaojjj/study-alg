#include <stdio.h>

int swap(int *num1,int *num2){ //포인터를 이용한 swap 함수 
	int temp;
	
	temp=*num1;
	*num1=*num2;
	*num2=temp;	
}
int main(void)
{
	int i,j,min,num[10];
		
	printf("숫자를 입력하세요 : ");
	for(i=0;i<10;i++){
		scanf("%d",&num[i]);
	}

	for(i=0;i<10;i++){
		min=i;
		for(j=i+1;j<10;j++){
			if(num[min]>num[j]){
				min=j;
			}
		}
		swap(&num[i],&num[min]);
	}
	
	for(i=0;i<10;i++){
		printf("%d ",num[i]);
	}
	return 0;
}
