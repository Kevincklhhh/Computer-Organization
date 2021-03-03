#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node{
    char* data;
    struct node* next;
};
struct Linkedlist{
    struct node* head;
};
void insertAtBeginning(struct Linkedlist* LL, char ele[]){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));//pointer points to new node
    char* nodeData = malloc(strlen(ele));
    strcpy(nodeData,ele);
    newNode->data = nodeData;//initialize the new node
    newNode->next = NULL;
    if (LL->head->next == NULL){
        LL->head->next = newNode;
    }else{newNode->next = LL->head->next;
        LL->head->next = newNode;}

}
void insertAtTheEnd(struct Linkedlist* LL, char ele[]){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));//pointer points to new node
    char* nodeData = malloc(strlen(ele));
    strcpy(nodeData,ele);
    newNode->data = nodeData;//initialize the new node
    newNode->next = NULL;
    struct node *cur_node = LL->head;
    while(cur_node->next != NULL){//goes to the end of linked list
        cur_node = cur_node->next;
        //printf("%s","fuck");
    }
    cur_node->next = newNode;

}
void deleteNode(struct Linkedlist* LL, char ele[]){
    struct node *cur_node = LL->head;
    while(cur_node->next != NULL){//iterates through linked list
        if(cur_node->next->data==ele){//search for the element with given value
            if (cur_node->next->next != NULL) {//if the node to delete is the last node
                struct node *temp = cur_node->next->next;//use a temp pointer to point to the next node of node to delete
                free(cur_node->next->data);
                free(cur_node->next);
                cur_node->next = temp;
            }else{
                free(cur_node->next->data);
                free(cur_node->next);}
        }
        cur_node = cur_node->next;

    }
}
int findNode(struct Linkedlist LL, char ele[]){
    struct node *cur_node = LL.head;
    while(cur_node->next != NULL){//iterates through linked list
        cur_node = cur_node->next;
        if(cur_node->data==ele){
            return 1;//returns 1 if ele exist
        }
    }
    return 0;//returns 0 otherwise
}
void displayLinkedList(struct Linkedlist LL){
    struct node *cur_node = LL.head;
    printf("%s","The list:- ");
    while(cur_node->next != NULL){//iterates through the linked list
        cur_node = cur_node->next;
        fprintf( stderr, "%s", cur_node->data );//print node data
        if (cur_node->next != NULL){
            printf("%s",", ");//print a comma and space between each node's value
        }
    }
}
int main(int argc, char** argv) {
    struct Linkedlist *Linked_list= (struct Linkedlist*)malloc(sizeof(struct Linkedlist));//initialize the linked list
    Linked_list->head = (struct node*)malloc(sizeof(struct node));//creates head node
    Linked_list->head->next = NULL;
    Linked_list->head->data = NULL;
    for (int i = 1; i < argc; i++) {//iterates through program argument

        if (isupper(argv[i][0]) != 0){//if letter is uppercase
            if(findNode(*Linked_list,argv[i]) != 0){//delete if it the word exists
                deleteNode(Linked_list,argv[i]);
            }
            insertAtBeginning(Linked_list,argv[i]);
        }else{//if letter is lowercase
            if(findNode(*Linked_list,argv[i]) != 0){
                deleteNode(Linked_list,argv[i]);//delete if it the word exists
            }
            insertAtTheEnd(Linked_list,argv[i]);
        }
    }
    displayLinkedList(*Linked_list);
    return 0;
}
