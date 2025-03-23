#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void InsertAtHead(int x) {
    struct Node* temp = malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = x;
    temp->next = head;
    head = temp;
}

void InsertAtNth(int x, int n) {
    if (n < 1) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* temp = malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    temp->data = x;
    temp->next = NULL;

    if (n == 1) {
        temp->next = head;
        head = temp;
        return;
    }

    struct Node* traverse = head;
    for (int i = 1; traverse && i < n - 1; i++) {
        traverse = traverse->next;
    }

    if (!traverse) {
        printf("Invalid position! List is shorter than expected.\n");
        free(temp);
        return;
    }

    temp->next = traverse->next;
    traverse->next = temp;
}

void DeleteAtHead() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void DeleteAtNth(int n) {
    if (n < 1 || !head) {
        printf("Invalid position or empty list.\n");
        return;
    }

    if (n == 1) {
        DeleteAtHead();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; temp && i < n - 1; i++) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

void ReverseList() {
    if (!head) {
	printf("List is empty, Not reversed.\n");
	return;
    }

    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("Linked list reversed.\n");
}

void Print() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void FreeList() {
    struct Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice, x, n;

    while (1) {
        printf("\n1. Insert at Head\n");
        printf("2. Insert at Nth Position\n");
        printf("3. Delete at Head\n");
        printf("4. Delete at Nth Position\n");
        printf("5. Print List\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &x) != 1) break;
                InsertAtHead(x);
                Print();
                break;
            case 2:
                printf("Enter value and position: ");
                if (scanf("%d %d", &x, &n) != 2) break;
                InsertAtNth(x, n);
                Print();
                break;
            case 3:
                DeleteAtHead();
                Print();
                break;
            case 4:
                printf("Enter position: ");
                if (scanf("%d", &n) != 1) break;
                DeleteAtNth(n);
                Print();
                break;
            case 5:
                Print();
                break;
            case 6:
                ReverseList();
                Print();
                break;
            case 7:
                FreeList();
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    FreeList();
    return 0;
}

