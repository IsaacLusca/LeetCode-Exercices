/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = malloc(sizeof(ListNode));
    dummy->next = NULL;
    ListNode* atual = dummy; 

    while (list1 != NULL || list2 != NULL) {
        ListNode* novoNo = malloc(sizeof(ListNode));
        if (list1 != NULL && (list2 == NULL || list1->val <= list2->val)) {
            novoNo->val = list1->val;
            list1 = list1->next;
        } else {
            novoNo->val = list2->val;
            list2 = list2->next;
        }
        atual->next = novoNo; 
        atual = atual->next;  
    }

    atual->next = NULL; 
    ListNode* mergedHead = dummy->next; 
    free(dummy); 
    return mergedHead; 
}

    

