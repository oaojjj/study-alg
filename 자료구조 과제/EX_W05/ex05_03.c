#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

typedef struct { /* 하나의 단어와 그 단어의 빈도수를 저장하기 위한 구조체 */
	char *word;
	int freq;
} Item;

struct node { /* 연결리스트의 노드의 구조를 정의하는 구조체 */
	Item *data;
	struct node *next;
};
typedef struct node Node;

void insert(Node **ptr_head, char buf[]);

int main()
{
	char buf[MAXLEN];
	Node *head = NULL; /* head는 지역변수이다. */
	while (1) {
		scanf("%s", buf);
		if (strcmp(buf, "EOF") == 0) break; /* 문자열 “EOF”를 입력하면 종료 */
	    insert(&head, buf); /* 입력된 문자열을 연결리스트에 반영 */
	}

	Node *p = head;
	while (p != NULL) {
		printf("%s:%d\n", p->data->word, p->data->freq);
		p = p->next;
	}
	return 0;
}

void insert(Node **ptr_head, char buf[]) {
	Node* node = *ptr_head;
	Node* nodee;
	Node* p;
	Node* tmp;
	int flag = 1;

	if (*ptr_head == NULL) {
		nodee = (Node*)malloc(sizeof(Node));
		nodee->data = (Item*)malloc(sizeof(Item));
		nodee->data->word = strdup(buf);
		nodee->data->freq = 1;
		nodee->next = NULL;
		*ptr_head = nodee;
		return;
	}

	while (node!= NULL) {
		if (strcmp(node->data->word, buf) == 0) { // 똑같은 문자가 있다면
			node->data->freq++;
			return;
		}
		node = node->next;
	}
	
	// 똑같은 문자가 없다면 노드 생성


	tmp = (Node*)malloc(sizeof(Node));
	tmp->data = (Item*)malloc(sizeof(Item));
	tmp->data->word = strdup(buf);
	tmp->data->freq = 1;
	tmp->next = NULL;

	// sort
	node = *ptr_head;
	while (node != NULL) {
		if (strcmp(node->data->word, tmp->data->word) > 0 && flag) { // 음수
			tmp->next = node;
			*ptr_head = tmp;
			return;
		}
		else if (strcmp(node->data->word, tmp->data->word) > 0) {
			p->next = tmp;
			tmp->next = node;
			return;
		}
		flag = 0;
		p = node;
		node = node->next;
	}
	p->next = tmp;
	return;

	/* 입력된 문자열을 연결리스트에 반영하고 head노드의 주소를 반환한다. 이미 존재하는.  */
	/* 문자열이면 카운트만 증가 하고, 아니라면 정렬된 순서로 연결리스트에 추가한다.  */

}
