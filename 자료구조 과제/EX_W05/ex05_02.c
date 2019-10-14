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

Node *insert(Node *, char buf[]);

int main()
{
	char buf[MAXLEN];
	Node *head = NULL; /* head�� ���������̴�. */
	while (1) {
		scanf("%s", buf);
		if (strcmp(buf, "EOF") == 0) break; /* ���ڿ� ��EOF���� �Է��ϸ� ���� */
		head = insert(head, buf); /* �Էµ� ���ڿ��� ���Ḯ��Ʈ�� �ݿ� */
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
		if (strcmp(node->data->word, buf) == 0) { // �Ȱ��� ���ڰ� �ִٸ�
			node->data->freq++;
			return head;
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
	node = head;
	while (node != NULL) {
		if (strcmp(node->data->word, tmp->data->word) > 0 && flag) { // ����
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

	/* �Էµ� ���ڿ��� ���Ḯ��Ʈ�� �ݿ��ϰ� head����� �ּҸ� ��ȯ�Ѵ�. �̹� �����ϴ�.  */
	/* ���ڿ��̸� ī��Ʈ�� ���� �ϰ�, �ƴ϶�� ���ĵ� ������ ���Ḯ��Ʈ�� �߰��Ѵ�.  */

}
