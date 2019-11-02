#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct {
  	int coef; // 계수
  	int expo; // 지수
} Term;

Term* recognize(char* str);

int main(int argc, char *argv[]) {
	char expr[30];
  	scanf("%s", expr);
  	Term *t = recognize(expr);
	printf("%d %d\n", t->coef, t->expo);
  	return 0;
  	
}

Term* recognize(char* body){
	Term *term = (Term*)malloc(sizeof(Term));
	int i=0,j=0;
	int sign_coef=1, coef=0, expo=1, end=0;
	
	i=0;
	
	if((int)body[i]==45){
		sign_coef *= -1;
		i++;
		j=i;
	}
		
	
	while(isdigit(body[i])){ // 계수 
		i++;
	}
		
	end=i;
	
	while(j<end && body[j] >='0' && body[j]<='9'){ // 계수 문자열을 숫자로 변환 
		coef = coef*10+(int)(body[j]-'0');
		j++;
	}
	
	if(coef==0){
		coef = sign_coef;
	}else{
		coef *= sign_coef;
	}
	
	while(!isdigit(body[i]) && i<strlen(body)){
		i++;
	}
	
	if(j==i){
		expo=0;
	}
	j=i;
	
	
	//=============================
	
	while(isdigit(body[i]) && i<strlen(body)){ // 지수 
		i++;
		expo=0;
	}
	
	end=i;
	
	while(j<end && body[j]>='0' && body[j]<='9'){ // 지수 문자열을 숫자로 변환 
		expo=expo*10+(int)(body[j]-'0');
		j++;
	}

	term->coef=coef;
	term->expo=expo;
	return term;
	
}
