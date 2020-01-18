// Eza Rasheed
// er6qt
// 04-28-19
// linkedlist.m

#import <Foundation/NSObject.h>
#import <math.h>
#import <stdio.h>

@interface ListNode : NSObject
{
@public //two seperate setter methods (the value, and the next fields of the ListNode)
    int val;
    ListNode* next;
}
// Tutorial point interface implementation
- (id) val: (int) val_value; //setter
- (int) val; //getter
- (id) next: (ListNode*) next_value; //setter
- (ListNode*) next; //getter
@end

@implementation ListNode

- (id) val: (int) val_value
{
    val = val_value;
    return self;
}

- (int) val
{
    return val;
}

- (id) next: (ListNode*) next_value
{
    next = next_value;
    return self;
}

- (ListNode*) next
{
    return next;
}

@end

int main(void)
{
    // Dynamically allocate list
    ListNode *ln = [ListNode new]; //head
    ListNode *tempNode = ln;
    
    // Take in input (1. Read in an integer, which we'll call values)
    int values;
    printf("Enter how many values to input: ");
    scanf("%d", &values); // read in int input
    
    // 2. Read in n(values) more ints, and put those into a linked list
    int i;
    for (i = 0; i < values; i++) {
        int input;
        printf("Enter value %d: ", i + 1); // print out what it is doing (int chronological order of inputs) 
        scanf("%d", &input);
        
        // Create List
        ListNode *list = [ListNode new];
        // list->val = input;
        [list val:input];
        // tempNode->next = list;
        [tempNode next:list];
        tempNode = list;
    }
    
    // 3. Print out singly linked list
    ListNode *itr = [ln next];
    //ListNode *delete;
    for (int i= 0; i < values; i++) {
        printf("%d\n", [itr val]);
        //delete = [itr next]
        itr = [itr next];
        //[itr release];
        // itr = delete;
    }
    
    // 4. Properly deallocate the linked list (TA Help)
    ListNode *delete = ln;
    while(delete != nil) {
        ListNode* deallo = [delete next];
        [delete release]; //deallocate object by calling "release" on that object
        delete = deallo;
    }
}
