
//** ***** Definition for singly-linked list.///
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//*******************MERGE TWO SORTED LINKED LIST

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Placeholder logic for merging two sorted lists
        // return nullptr; // User will implement merging logic
       ListNode* newNode=new ListNode();
       ListNode* tail=newNode;
       while(list1 && list2){
        if(list1->val<list2->val){
            tail->next=list1;
            list1=list1->next;
        }else{
            tail->next=list2;
            list2=list2->next;
        }
        tail=tail->next;
       }
       if(list1)tail->next=list1;
       if(list2)tail->next=list2;

       return newNode->next;
    }
};


//GIVEN A LINKEDLIST , SORT IT **************************

class Solution {
private:
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode();
        ListNode* tail=dummy;

        while(l1 && l2){
            if(l1->val<l2->val){
                tail->next=l1;
                l1=l1->next;
            }else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        //if l1 is finish and l2 is still there or vice-versa
        tail=tail->next=l1?l1:l2;
        return dummy->next;
    }

    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        // step1 find middle node
        ListNode* middleNode=findMiddle(head);
        
        //step2 create left and right
        ListNode* left=head;
        ListNode* right=middleNode->next;
        middleNode->next=nullptr;//end

        //now recursively sort left and right part
        left=sortList(left);
        right=sortList(right);

        //merge left and right
        return merge(left,right);
    }
};



