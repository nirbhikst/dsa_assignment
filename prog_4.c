// prog_4.c
#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev, *next;
} DNode;

DNode* create(int x){
    DNode* n=(DNode*)malloc(sizeof(DNode));
    n->data=x; n->prev=n->next=NULL;
    return n;
}

void print_forward(DNode* head){
    for(DNode* p=head; p; p=p->next) printf("%d ", p->data);
    printf("\n");
}

DNode* append(DNode* head, int x){
    DNode* n=create(x);
    if(!head) return n;
    DNode* p=head;
    while(p->next) p=p->next;
    p->next=n; n->prev=p;
    return head;
}

DNode* find(DNode* head, int key){
    for(DNode* p=head; p; p=p->next) if(p->data==key) return p;
    return NULL;
}

// insert new value after given node pointer
DNode* insert_after(DNode* head, DNode* pos, int x){
    if(!pos) return head;
    DNode* n=create(x);
    n->next=pos->next;
    n->prev=pos;
    if(pos->next) pos->next->prev=n;
    pos->next=n;
    return head;
}

// delete given node pointer
DNode* delete_node(DNode* head, DNode* target){
    if(!target) return head;
    if(target->prev) target->prev->next = target->next;
    else head = target->next; // deleting head

    if(target->next) target->next->prev = target->prev;
    free(target);
    return head;
}

void free_all(DNode* head){
    while(head){
        DNode* t=head;
        head=head->next;
        free(t);
    }
}

int main(){
    DNode* head=NULL;
    head=append(head,10);
    head=append(head,20);
    head=append(head,30);
    head=append(head,40);

    printf("Initial: ");
    print_forward(head);

    int after=20, val=25;
    DNode* p=find(head, after);
    head=insert_after(head, p, val);
    printf("After inserting %d after %d: ", val, after);
    print_forward(head);

    int del=30;
    DNode* d=find(head, del);
    head=delete_node(head, d);
    printf("After deleting %d: ", del);
    print_forward(head);

    free_all(head);
    return 0;
}
