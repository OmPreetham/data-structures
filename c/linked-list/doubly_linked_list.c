#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void InsertAtHead(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    temp->prev = NULL;
    if (head != NULL) {
        head->prev = temp;
    } else {
        tail = temp;
    }
    head = temp;
}

void InsertAtTail(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = tail;
    if (tail != NULL) {
        tail->next = temp;
    } else {
        head = temp;
    }
    tail = temp;
}

void Print() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void FreeList() {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    tail = NULL;
}

int main() {
    int choice, value;
    while (1) {
	printf("\nDOUBLY LINKED LIST\n");
	
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Print List\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert at head: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input! Please enter an integer.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                InsertAtHead(value);
                Print();
                break;
            case 2:
                printf("Enter value to insert at tail: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input! Please enter an integer.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                InsertAtTail(value);
                Print();
                break;
            case 3:
                Print();
                break;
            case 4:
                FreeList();
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

