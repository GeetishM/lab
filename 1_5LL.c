/* Write a c program to build a singly LinkedList and perform following operation.
1. Display the list
2. Search an element
3. Insert at beginning
4. Insert at end
5. Insert after a given node
6. Insert before a given node
7. Delete from beginning
8. Delete from end
9. Delete after a given node
10. Delete before a given node
11. Delete an element
 */

#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int value);
void displayList(struct Node* head);
struct Node* searchElement(struct Node* head, int key);
struct Node* insertAtBeginning(struct Node* head, int value);
struct Node* insertAtEnd(struct Node* head, int value);
struct Node* insertAfterNode(struct Node* head, int key, int value);
struct Node* insertBeforeNode(struct Node* head, int key, int value);
struct Node* deleteFromBeginning(struct Node* head);
struct Node* deleteFromEnd(struct Node* head);
struct Node* deleteAfterNode(struct Node* head, int key);
struct Node* deleteBeforeNode(struct Node* head, int key);
struct Node* deleteElement(struct Node* head, int key);

int main() {
    struct Node* head = NULL;
    int choice, value, key;

    do {
        printf("\n1. Display the list\n");
        printf("2. Search an element\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at end\n");
        printf("5. Insert after a given node\n");
        printf("6. Insert before a given node\n");
        printf("7. Delete from beginning\n");
        printf("8. Delete from end\n");
        printf("9. Delete after a given node\n");
        printf("10. Delete before a given node\n");
        printf("11. Delete an element\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList(head);
                break;
            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                if (searchElement(head, key) != NULL) {
                    printf("Element found in the list.\n");
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 3:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 4:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 5:
                printf("Enter the node value after which to insert: ");
                scanf("%d", &key);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAfterNode(head, key, value);
                break;
            case 6:
                printf("Enter the node value before which to insert: ");
                scanf("%d", &key);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertBeforeNode(head, key, value);
                break;
            case 7:
                head = deleteFromBeginning(head);
                break;
            case 8:
                head = deleteFromEnd(head);
                break;
            case 9:
                printf("Enter the node value after which to delete: ");
                scanf("%d", &key);
                head = deleteAfterNode(head, key);
                break;
            case 10:
                printf("Enter the node value before which to delete: ");
                scanf("%d", &key);
                head = deleteBeforeNode(head, key);
                break;
            case 11:
                printf("Enter the element to delete: ");
                scanf("%d", &key);
                head = deleteElement(head, key);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("Linked List: ");
        while (head != NULL) {
            printf("%d -> ", head->data);
            head = head->next;
        }
        printf("NULL\n");
    }
}

// Function to search for an element in the linked list
struct Node* searchElement(struct Node* head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            return head; // Element found
        }
        head = head->next;
    }
    return NULL; // Element not found
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Function to insert a node after a given node with a specific value
struct Node* insertAfterNode(struct Node* head, int key, int value) {
    struct Node* newNode = createNode(value);
    struct Node* temp = searchElement(head, key);

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        free(newNode); // Free the memory allocated for the new node
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to insert a node before a given node with a specific value
struct Node* insertBeforeNode(struct Node* head, int key, int value) {
    struct Node* newNode = createNode(value);

    // If the key is the first element, insert at the beginning
    if (head != NULL && head->data == key) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    while (temp != NULL && temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        free(newNode); // Free the memory allocated for the new node
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to delete a node from the beginning of the linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp); // Free the memory of the deleted node
    return head;
}

// Function to delete a node from the end of the linked list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head); // Free the memory of the deleted node
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next); // Free the memory of the deleted node
    temp->next = NULL;
    return head;
}

// Function to delete a node after a given node with a specific value
struct Node* deleteAfterNode(struct Node* head, int key) {
    struct Node* temp = searchElement(head, key);

    if (temp == NULL || temp->next == NULL) {
        printf("Node with value %d not found or it is the last node.\n", key);
        return head;
    }

    struct Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    free(deleteNode); // Free the memory of the deleted node
    return head;
}

// Function to delete a node before a given node with a specific value
struct Node* deleteBeforeNode(struct Node* head, int key) {
    if (head == NULL || head->next == NULL || head->next->data == key) {
        printf("Cannot delete node before value %d.\n", key);
        return head;
    }

    if (head->data == key) {
        struct Node* temp = head->next;
        free(head); // Free the memory of the deleted node
        return temp;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL && temp->next->next->data != key) {
        temp = temp->next;
    }

    if (temp->next->next == NULL) {
        printf("Node with value %d not found.\n", key);
        return head;
    }

    struct Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    free(deleteNode); // Free the memory of the deleted node
    return head;
}

// Function to delete a node with a specific value from the linked list
struct Node* deleteElement(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp); // Free the memory of the deleted node
        return head;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Node with value %d not found.\n", key);
        return head;
    }

    struct Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    free(deleteNode); // Free the memory of the deleted node
    return head;
}

