#include <stdio.h>

int Biynary_Search(int ar[],int len,int target){
	int first = 0;
	int last = len;
	int mid;
	
	while(first<=last){
		mid=(first+last)/2;
		if(ar[mid]==target)
			return mid;
		else{
			if(target<mid)
				last=mid-1;
			else
				first=mid+1;	
		}
	}
	return -1;
}

int main(void){
	int data[]={1,3,5,7,9,13,15,17,19,30};
	int num, flag;
	
	scanf("%d",&num);
	flag = Biynary_Search(&data,sizeof(data)/sizeof(int),num);
	
	if(flag!=-1)
		printf("ã�°��� �迭 %d��°�� �ֽ��ϴ�.",flag+1);
	else
		printf("ã�°��� ���� �迭�� �������� �ʽ��ϴ�.");
	
} 
