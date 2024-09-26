#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}


void insertatend(struct node** head, int data) {
    struct node* newnode = createnode(data);
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}


void displaylist(struct node* head) {
    if (head == NULL) {
        printf("List is empty..\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int countnodes(struct node* head) {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


void deletenode(struct node** head, int key) {
    struct node* temp = *head;
    struct node* prev = NULL;

    
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    
    prev->next = temp->next;
    free(temp);
}


void searchnode(struct node* head, int key) {
    struct node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Node with value %d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Node with value %d not found\n", key);
}

int main() {
    struct node* head = NULL;
    int choice, data, key;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Display list\n");
        printf("3. Count nodes\n");
        printf("4. Delete node\n");
        printf("5. Search node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                insertatend(&head, data);
                break;
            case 2:
                displaylist(head);
                break;
            case 3:
                printf("Number of nodes: %d\n", countnodes(head));
                break;
            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &key);
                deletenode(&head, key);
                break;
            case 5:
                printf("Enter the value to search: ");
                scanf("%d", &key);
                searchnode(head, key);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.. try again..\n");
        }
    }

    return 0;
}
