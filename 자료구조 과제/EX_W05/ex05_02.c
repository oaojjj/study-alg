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

Node *insert(Node *, char buf[]);

int main()
{
	char buf[MAXLEN];
	Node *head = NULL; /* head는 지역변수이다. */
	while (1) {
		scanf("%s", buf);
		if (strcmp(buf, "EOF") == 0) break; /* 문자열 “EOF”를 입력하면 종료 */
		head = insert(head, buf); /* 입력된 문자열을 연결리스트에 반영 */
	}

	Node *p = head;
	while (p != NULL) {
		printf("%s:%d\n", p->data->word, p->data->freq);
		p = p->next;
	}
	return 0;
}

Node *insert(Node *head, char buf[]) {
	Node* node = head;
	Node* p = node;
	Node* tmp;
	int flag = 1;

	if (head == NULL) {
		head= (Node*)malloc(sizeof(Node));
		head->data = (Item*)malloc(sizeof(Item));
		head->data->word = strdup(buf);
		head->data->freq = 1;
		head->next = NULL;
		return head;
	}

	while (node!= NULL) {
		if (strcmp(node->data->word, buf) == 0) { // 똑같은 문자가 있다면
			node->data->freq++;
			return head;
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
	node = head;
	while (node != NULL) {
		if (strcmp(node->data->word, tmp->data->word) > 0 && flag) { // 음수
			tmp->next = node;
			return tmp;
		}
		else if (strcmp(node->data->word, tmp->data->word) > 0) {
			p->next = tmp;
			tmp->next = node;
			return head;
		}
		flag = 0;
		p = node;
		node = node->next;
	}
	p->next = tmp;
	return head;

	/* 입력된 문자열을 연결리스트에 반영하고 head노드의 주소를 반환한다. 이미 존재하는.  */
	/* 문자열이면 카운트만 증가 하고, 아니라면 정렬된 순서로 연결리스트에 추가한다.  */

}
