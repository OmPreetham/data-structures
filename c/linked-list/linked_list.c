#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* head = NULL;

void Insert(int x) {
	struct Node* temp = malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = head;
	head = temp;
}

void Print() {
	struct Node* temp = head;

	printf("List: ");
	
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("\n");
}

int main() {
	printf("How Many Numbers Do You Want To Insert\n");
	
	int n, i, x;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		printf("Enter The Number \n");
		scanf("%d", &x);
		Insert(x);
		Print();
	}
	return 0;
}
