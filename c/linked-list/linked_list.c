#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void InsertAtHead(int x) {
    struct Node* temp = malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = x;
    temp->next = head;
    head = temp;
}

void InsertAtNth(int x, int n) {
    if (n < 1) {
        printf("Invalid position! Must be 1 or greater.\n");
        return;
    }

    struct Node* temp = malloc(sizeof(struct Node));
    if (temp == NULL) {
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
    for (int i = 0; i < n - 2 && traverse != NULL; i++) {
        traverse = traverse->next;
    }

    if (traverse == NULL) {
        printf("Invalid position! List is shorter than expected.\n");
        free(temp);
        return;
    }

    temp->next = traverse->next;
    traverse->next = temp;
}

void DeleteAtHead() {
    if (head == NULL) {  // Fixed condition
        printf("No elements to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void Print() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
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
}

int main() {
    int choice, x, n;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Nth Position\n");
        printf("3. Delete at Head\n");
        printf("4. Print List\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &x) != 1) {
                    printf("Invalid input!\n");
                    break;
                }
                InsertAtHead(x);
                Print();
                break;
            case 2:
                printf("Enter value and position: ");
                if (scanf("%d %d", &x, &n) != 2) {
                    printf("Invalid input!\n");
                    break;
                }
                InsertAtNth(x, n);
                Print();
                break;
            case 3:
                DeleteAtHead();
                Print();
                break;
            case 4:
                Print();
                break;
            case 5:
                FreeList();
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    FreeList(); // Cleanup before exiting
    return 0;
}
