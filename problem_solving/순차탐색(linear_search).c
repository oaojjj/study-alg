#include <stdio.h>

int linear_Search(int ar[],int len,int target){
	int i;
	for(i=0;i<len;i++){
		if(ar[i]==target)
			return i;
			
	}
	return -1;
}

int main(void){
	int data[] = {1,3,5,7,9,2,4,6,8,10};
	int flag;
	int num;
	
	scanf("%d",&num);
	
	flag = linear_Search(&data,sizeof(data)/sizeof(int),num);
	if(flag!=-1){
		printf("ã�°��� %d��° �迭�� �ֽ��ϴ�.\n",flag+1);
	}
	else
		printf("ã�°��� �����ϴ�");
}
