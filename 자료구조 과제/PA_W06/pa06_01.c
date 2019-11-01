#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

#define MAX_POLYS 100
#define BUFFER_LENGTH 100

struct term {
	int coef;
	int exp_x, exp_y;
	struct term *next;
};
typedef struct term Term;

typedef struct polynomial {
	char name;
	Term *first;
	int size;
} Polynomial;

Polynomial *polys[MAX_POLYS];
int n = 0;

Term* create_term_instance();
Polynomial* create_polynomial_instance(char name);
void erase_blanks(char *expression);
int read_line(char * buffer);
void handle_print(char name);
void print_term(Term* term,int flag);
void handle_definition(char *expression);
Polynomial* create_by_parse_poly(char name, char*body);
void handle_list();
int eval_poly(Polynomial * poly, int x, int y);
void add_term(int c, int e_x, int e_y, Polynomial* poly);
Polynomial * create_by_add_two_poly(char name, char ex1, char ex2);
void destroy_poly(Polynomial*poly);
void insert_poly(Polynomial*poly);
int eval_term(Term * term, int x, int y);
void handle_calc(char name, int x, int y);


int main() {
	char command_line[BUFFER_LENGTH];
	char *command, *arg1; //arg1 == func_name
	char *arg2, *arg3; // x and y

	while (1) {
		printf("$ \n");
		if (read_line(command_line) <= 0) {
			continue;
		}

		command = strtok(command_line," ");

		if (strcmp(command, "print") == 0) {
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			handle_print(arg1[0]);
		}
		else if (strcmp(command, "calc") == 0) {
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			arg2 = strtok(NULL, " ");
			if (arg2 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			arg3 = strtok(NULL, " ");
			if (arg3 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			handle_calc(arg1[0],atoi(arg2),atoi(arg3));
		}
		else if (strcmp(command, "def") == 0 || strcmp(command, "add") == 0) {
			command = strtok(NULL, "");
			handle_definition(command);
		}
		else if (strcmp(command, "list") == 0) {
			handle_list();
		}
		else if (strcmp(command, "exit") == 0) {
			return 0;
		}
	} // while

	return 0;
}

void add_term(int c, int e_x, int e_y, Polynomial* poly) {
	if (c == 0)
		return;
	Term *p = poly->first, *q = NULL;

	while (p != NULL && p->exp_x >= e_x) {
		if (p->exp_x == e_x) {
			if (p->exp_y == e_y) {
				p->coef += c;
				if (p->coef == 0) {
					if (q == NULL) // 첫 번째 노드 삭제
						poly->first = p->next;
					else // 사이 노드 삭제
						q->next = p->next;
					poly->size--;
					free(p);
				}
				return;
			}
			else if(p->exp_y>e_y){
				q = p;
				p = p->next;
			}
			else {
				break;
			}
		}
		else {
			q = p;
			p = p->next;
		}
	}

	Term*term = create_term_instance(); // 새로운텀 생성
	term->coef = c;
	term->exp_x = e_x;
	term->exp_y = e_y;

	if (q == NULL) { // 새로 들어온 텀이 제일 큰 차수 또는 맨 앞에 삽입 
		term->next = poly->first;
		poly->first = term;
	}
	else { // 사이에 들어가는 경우
		term->next = p;
		q->next = term;
	}
	poly->size++;
}

Polynomial* create_by_add_two_poly(char name, char ex1, char ex2) {
	Polynomial *poly = create_polynomial_instance(name);
	Polynomial *a=NULL, *b=NULL;

	for (int i = 0; i < n; i++) {
		if (polys[i]->name == ex1)
			a = polys[i];
		if (polys[i]->name == ex2)
			b = polys[i];
	}
	if (a == NULL || b == NULL) {
		return NULL;
	}

	Term*t1 = a->first;
	Term*t2 = b->first;
	for (int i = 0; i < a->size; i++) {
		add_term(t1->coef, t1->exp_x, t1->exp_y, poly);
		t1 = t1->next;
	}
	for (int i = 0; i < b->size; i++) {
		add_term(t2->coef, t2->exp_x, t2->exp_y, poly);
		t2 = t2->next;
	}
	
	return poly;
}

int parse_and_add_term(char* body, int begin, int end,Polynomial *ptr_poly) {
	int sign_coef = 1, coef = 0, expo_x = 0, expo_y = 0;

	if (body[begin] == '+')
		begin++;
	else if (body[begin] == '-') {
		sign_coef = -1;
		begin++;
	}

	while (begin < end && isdigit(body[begin])) {
		coef = coef * 10 + (int)(body[begin] - '0');
		begin++;
	}

	if (coef == 0) { // 계수가 1 혹은 -1인 경우
		coef = sign_coef;
	}
	else {
		coef *= sign_coef;
	}

	if (begin >= end) { // 상수항
		add_term(coef, 0, 0, ptr_poly);
		return 1;
	}

	if (body[begin] != 'x' && body[begin] != 'y') // 상수항이 아닌데 x,y가 없을 경우
		return 0;
	//if (body[begin] == 'x' && body[begin + 1] != '^' && body[begin + 1] != 'y' && body[begin+1]!='\0'&&body[begin+1]=='-'&&body[begin + 1] == '+')
	//	return 0;
	//if (body[begin] == 'y' && body[begin + 1] != '^') // y일때 뒤에 ^가 아닐 때
	//	return 0;

	if (body[begin] == 'x' && body[begin + 1] == '^') {
		begin += 2;
		while (begin < end && isdigit(body[begin])) {
			expo_x = expo_x * 10 + (int)(body[begin] - '0');
			begin++;
		}
	}
	else if (body[begin] == 'x' &&body[begin + 1] != '^') {
		expo_x = 1;
		begin++;
	}

	if (body[begin] == 'y'&& body[begin + 1] == '^') {
		begin += 2;
		while (begin < end && isdigit(body[begin])) {
			expo_y = expo_y * 10 + (int)(body[begin] - '0');
			begin++;
		}
	}
	else if (body[begin] == 'y' &&body[begin + 1] != '^') {
		expo_y = 1;
		begin++;
	}

	add_term(coef, expo_x, expo_y, ptr_poly);
	return 1;
}

void destroy_poly(Polynomial*poly) {
	if (poly == NULL) {
		return;
	}
	else {
		Term*t = poly->first, *tmp;
		while (t != NULL) {
			tmp = t;
			t = t->next;
			free(tmp);
		}
		free(poly);
	}
}

void insert_poly(Polynomial*poly) {
	for (int i = 0; i < n; i++) {
		if (polys[i]->name == poly->name) { // 기존 다항식 덮어쓰기
			destroy_poly(polys[i]);
			polys[i] = poly;
			return;
		}
	}
	polys[n++] = poly;
}

Polynomial* create_by_parse_poly(char name, char*body) {
	Polynomial* ptr_poly = create_polynomial_instance(name); // 객체 생성
	int i = 0, begin_term = 0;

	while (i < strlen(body)) {
		
		if (body[i] == '+' || body[i] == '-') // 몸체의 첫 번째 계수의 기호를 넘어간다.
			i++;
		while (i<strlen(body) && body[i] != '+' && body[i] != '-') // 첫 번째 텀의 끝까지 읽는다.
			i++;
		
		int result = parse_and_add_term(body, begin_term, i, ptr_poly);

		if (result == 0) {
			destroy_poly(ptr_poly);
			return NULL;
		}
		begin_term = i;
	}
	return ptr_poly;
}

void handle_list() {
	for (int i = 0; i < n; i++) {
		handle_print(polys[i]->name);
	}
}

int eval_poly(Polynomial*poly, int x, int y) {
	int result = 0;
	Term*t = poly->first;
	while (t != NULL) {
		result += eval_term(t, x, y);
		t = t->next;
	}
	return result;
}

int eval_term(Term* term, int x, int y) {
	int i, result = term->coef;
	for (i = 0; i < term->exp_x; i++) {
		result *= x;
	}
	for (i = 0; i < term->exp_y; i++) {
		result *= y;
	}
	return result;
}

void handle_calc(char name, int x, int y) {
	for (int i = 0; i < n; i++) {
		if (polys[i]->name == name) {
			printf("%d\n",eval_poly(polys[i], x, y));
		}
	}
}

void handle_definition(char *expression) {
	Polynomial * poly;

	erase_blanks(expression);

	char*f_name = strtok(expression,"=");
	if (f_name == NULL || strlen(f_name) != 1) {
		printf("error func_name\n");
		return;
	}

	char *body = strtok(NULL, "=");
	if (body == NULL || strlen(body) <= 0) {
		printf("Invalid expression format\n");
		return;
	}

	if (body[0] >= 'a' && body[0] <= 'z' && body[0] != 'x' && body[0]!='y') { // 두개의 다항식을 합친다.
		char *former = strtok(body, "+");
		if (former == NULL || strlen(former) != 1) {
			printf("Invalid expression formet");
			return;
		}
		char *later = strtok(NULL, "");
		if (later == NULL || strlen(later) != 1) {
			printf("Invalid expression formet");
			return;
		}

		poly = create_by_add_two_poly(f_name[0], former[0], later[0]);
	}
	else
		poly = create_by_parse_poly(f_name[0], body);

		if (poly == NULL) {
			printf("Invalid expression format\n");
			return;
		}
		else {
			insert_poly(poly);
		}
	
}

void print_term(Term* term,int flag) {
	if (term->coef != 0 && flag) {
		if (term->coef ==-1) {
			if (term->exp_x == 0 || term->exp_y == 0)
				printf("-");
		}
		if(term->coef!=1 && term->coef!=-1){
			printf("%d", term->coef);
		}
	}
	if (term->coef != 0 && !flag) {
		if (term->coef == 1) {
			if (term->exp_x == 0 && term->exp_y == 0)
				printf("%+d", term->coef);
			else
				printf("+");
		}
		else if(term->coef == -1){
			if (term->exp_x == 0 && term->exp_y == 0)
				printf("%+d",term->coef);
			else
				printf("-");
		}
		else {
			printf("%+d", term->coef);
		}
	}

	if (term->exp_x > 1) {
		printf("x^%d", term->exp_x);
	}
	else if (term->exp_x == 1) {
		printf("x");
	}

	if (term->exp_y > 1) {
		printf("y^%d", term->exp_y);
	}
	else if (term->exp_y == 1) {
		printf("y");
	}
}

void handle_print(char name) {
	int i, j, flag = 1;
	Term* term;

	for(i=0;i<n;i++){
		if (polys[i]->name==name) {
			printf("%c=", polys[i]->name);
			term = polys[i]->first;
			for (j = 0; j < polys[i]->size; j++) {
				print_term(term,flag);
				term = term->next;
				flag = 0;
			}
			break;
		}
	}

	if (i == n) {
		printf("error print\n");
	}
	else {
		printf("\n");
	}
}

void erase_blanks(char *expression) {
	int len = strlen(expression);
	int index = 0, i = 0;

	for (i = 0; i < len; i++) {
		if (expression[i] != ' ') {
			expression[index++] = expression[i];
		}
	}
	expression[index] = '\0';
}

int read_line(char* buffer) {
	int len = 0;

	fgets(buffer, BUFFER_LENGTH, stdin);
	len = strlen(buffer);
	buffer[strlen(buffer) - 1] = '\0';
	return len;
}

Polynomial* create_polynomial_instance(char name) {
	Polynomial *p = (Polynomial*)malloc(sizeof(Polynomial));
	p->first = NULL;
	p->name = name;
	p->size = 0;
	return p;
}

Term* create_term_instance() {
	Term *t = (Term*)malloc(sizeof(Term));
	t->coef = 0;
	t->exp_x = 0;
	t->exp_y = 0;
	t->next = NULL;
	return t;
}

