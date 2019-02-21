#include <stdio.h>

struct Node {
	char data;
	Node* prev;
	Node* next;

	Node() {
		prev = next = NULL;
	}
};

Node* cursor;
Node* head;

char input[100001];
int N;

void insert(char c) {
	Node *node = new Node();
	node->data = c;
	if (cursor->next == NULL) {
		node->prev = cursor;
		node->next = cursor->next;
		cursor->next = node;
		cursor = node;
		return;
	}
	node->prev = cursor;
	node->next = cursor->next;
	cursor->next->prev = node;
	cursor->next = node;
	cursor = node;
}

void init(char s[]) {
	head = new Node();
	cursor = head;
	for (int i = 0; s[i]; i++) insert(s[i]);
}

void move_to_left() {
	if (cursor->prev == NULL) return;
	cursor = cursor->prev;
}

void move_to_right() {
	if (cursor->next == NULL) return;
	cursor = cursor->next;
}

void remove_left() {
	if (cursor->prev == NULL) return;
	if (cursor->next == NULL) {
		cursor->prev->next = NULL;
		cursor = cursor->prev;
		return;
	}
	cursor->prev->next = cursor->next;
	cursor->next->prev = cursor->prev;
	cursor = cursor->prev;
}

void printString() {
	Node *cur = head->next;
	while (cur != NULL) {
		printf("%c", cur->data);
		cur = cur->next;
	}
}

int main() {
	scanf("%s", input); scanf("%d", &N);
	init(input);
	for (int i = 0; i < N; i++) {
		char command;
		scanf(" %c", &command);
		if (command == 'P') {
			char word; scanf(" %c", &word);
			insert(word);
		}
		else if (command == 'L') move_to_left();
		else if (command == 'D') move_to_right();
		else if (command == 'B') remove_left();	
	}
	printString();
	return 0;
}

//linked list 직접 구현하기 