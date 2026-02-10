// prog_3.c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* push_front(Node* head, int x){
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=x; n->next=head;
    return n;
}

void print_list(Node* head){
    for(Node* p=head; p; p=p->next) printf("%d ", p->data);
    printf("\n");
}

void print_reverse(Node* head){
    if(!head) return;
    print_reverse(head->next);
    printf("%d ", head->data);
}

void free_list(Node* head){
    while(head){
        Node* t=head;
        head=head->next;
        free(t);
    }
}

int main(){
    Node* head=NULL;
    head=push_front(head, 5);
    head=push_front(head, 4);
    head=push_front(head, 3);
    head=push_front(head, 2);
    head=push_front(head, 1);

    printf("Normal:  ");
    print_list(head);

    printf("Reverse: ");
    print_reverse(head);
    printf("\n");

    free_list(head);
    return 0;
}
