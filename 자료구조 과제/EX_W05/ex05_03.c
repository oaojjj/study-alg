#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

typedef struct { /* �ϳ��� �ܾ�� �� �ܾ��� �󵵼��� �����ϱ� ���� ����ü */
	char *word;
	int freq;
} Item;

struct node { /* ���Ḯ��Ʈ�� ����� ������ �����ϴ� ����ü */
	Item *data;
	struct node *next;
};
typedef struct node Node;

void insert(Node **ptr_head, char buf[]);

int main()
{
	char buf[MAXLEN];
	Node *head = NULL; /* head�� ���������̴�. */
	while (1) {
		scanf("%s", buf);
		if (strcmp(buf, "EOF") == 0) break; /* ���ڿ� ��EOF���� �Է��ϸ� ���� */
	    insert(&head, buf); /* �Էµ� ���ڿ��� ���Ḯ��Ʈ�� �ݿ� */
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
		if (strcmp(node->data->word, buf) == 0) { // �Ȱ��� ���ڰ� �ִٸ�
			node->data->freq++;
			return;
		}
		node = node->next;
	}
	
	// �Ȱ��� ���ڰ� ���ٸ� ��� ����


	tmp = (Node*)malloc(sizeof(Node));
	tmp->data = (Item*)malloc(sizeof(Item));
	tmp->data->word = strdup(buf);
	tmp->data->freq = 1;
	tmp->next = NULL;

	// sort
	node = *ptr_head;
	while (node != NULL) {
		if (strcmp(node->data->word, tmp->data->word) > 0 && flag) { // ����
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

	/* �Էµ� ���ڿ��� ���Ḯ��Ʈ�� �ݿ��ϰ� head����� �ּҸ� ��ȯ�Ѵ�. �̹� �����ϴ�.  */
	/* ���ڿ��̸� ī��Ʈ�� ���� �ϰ�, �ƴ϶�� ���ĵ� ������ ���Ḯ��Ʈ�� �߰��Ѵ�.  */

}
