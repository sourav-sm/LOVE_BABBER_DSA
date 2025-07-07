#include<bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


//LEETCODE 2. Add Two Numbers
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(-1);
        int carry=0;
        ListNode* it=ans;
        while(l1 || l2 || carry){
            int a=l1?l1->val:0;
            int b=l2?l2->val:0;
            int sum=a+b+carry;
            int digit=sum%10;
            carry=sum/10;

            it->next=new ListNode(digit);
            it=it->next;
            l1=l1?l1->next:0;
            l2=l2?l2->next:0;
        }
        return ans->next;
    }
};

/**---------------------------------------------------------------------------------------*****/
//LEETCODE 86. Partition List
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      ListNode* firstPart=new  ListNode(-1);
      ListNode* secondPart=new  ListNode(-1);  

      ListNode* firstPartTail=firstPart;
      ListNode* secondPartTail=secondPart;

      ListNode* it=head;
      while(it){
        if(it->val<x){
            firstPartTail->next=it;
            firstPartTail=firstPartTail->next;
        }else{
            secondPartTail->next=it;
            secondPartTail=secondPartTail->next;
        }
        it=it->next;
      }
      firstPartTail->next=secondPart->next;
      secondPartTail->next=nullptr;

      return firstPart->next;
    }
};

/************************************************************************************** */
// LEETCODE 725. Split Linked List in Parts
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }

       vector<ListNode*>ans(k,nullptr);
       ListNode* it=head;
       int idealPartSize=n/k;
       int extraNodes=n%k;   
       
       for(int i=0;i<k && it;i++){
        ans[i]=it;
        int actualCurrentPartSize=idealPartSize+(extraNodes-- >0 ?1:0);
        for(int j=0;j<actualCurrentPartSize-1;j++){
            it=it->next;
        }
        auto nextPartStarting=it->next;
        it->next=nullptr;
        it=nextPartStarting;
       }
        return ans;
    }
};