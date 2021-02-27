#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
    char* data;
    struct node* next;
};
struct Linkedlist{
    struct node* head;
};
void insertAtBeginning(struct Linkedlist* LL, char ele[]){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));//pointer points to new node
    char nodeData[strlen(ele)];
    strcpy(nodeData,ele);
    newNode->data = nodeData;
    if (LL->head->next == NULL){
        LL->head->next = newNode;
    }else{newNode->next = LL->head->next;
        LL->head->next = newNode;}

}
void insertAtTheEnd(struct Linkedlist* LL, char ele[]){

}
void deleteNode(struct Linkedlist* LL, char ele[]){

}
int findNode(struct Linkedlist LL, char ele[]){

}
void displayLinkedList(struct Linkedlist LL){
    struct node *cur_node;
    cur_node = LL.head;
    while(cur_node->next != NULL){
        cur_node = cur_node->next;
        printf("%s, ",cur_node->data);
    }
}
int main() {

    struct Linkedlist *Linked_list= (struct Linkedlist*)malloc(sizeof(struct Linkedlist));

    Linked_list->head = (struct node*)malloc(sizeof(struct node));

    char to_insert[] = {'h','a','h'};

    insertAtBeginning(Linked_list,to_insert);

    printf("%s",Linked_list->head->next->data);
    if(Linked_list->head->next != NULL){printf("hahha\n");}

    displayLinkedList(*Linked_list);
    return 0;
}
