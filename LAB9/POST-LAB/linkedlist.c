/* 
 * Name: Eza Rasheed
 * id: er6qt
 * date: 04-11-19
 * filename: linkedlist.c
*/

#include <stdio.h>
#include <stdlib.h> 

/* taken from tutorial */
struct list_item {
    struct list_item *prev, *next;
    int length;
};

struct list {
    struct list_item *head;
};


int main(){
    int n;
    printf("Enter how many values to input: ");
    scanf("%d", &n);
    
    /* allocate list and node*/
    struct list *makeList = (struct list*) malloc(sizeof(struct list));
    makeList->head = (struct list_item*) malloc(sizeof(struct list_item)); //seg fault if not allocated
    
    /* set value of head node to 0 */
    makeList->head->length = 0; 
    
    struct list_item *tempNode;
    tempNode = makeList->head;
    
    int i;
    for(int i = 0; i < n; i++) {
        int temp2;
        printf("Enter value %d: ", i+1); 
        scanf("%d", &temp2);
        tempNode->next = (struct list_item*) malloc(sizeof(struct list_item));
        tempNode->length = temp2;
        tempNode = tempNode->next;
    }
    
    struct list_item *tempNode1;
    tempNode1 = makeList->head;
    
    int j;
    for(int j = 0; j < n; j++){
        printf("%d\n", tempNode1->length);
        tempNode1 = tempNode1->next;
    }
    
    /* deallocate linked list */
    free(makeList);
    return 0;
}
        
        
    
    
    
    
    
