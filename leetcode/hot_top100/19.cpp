#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tempnode=new ListNode(0,head);
  
        ListNode *fast=tempnode;
        ListNode *slow=tempnode;
        ListNode *ori=tempnode;
        int count=n;
        while (count>0&&slow->next!=nullptr)
        {
            count--;
            slow=slow->next;
        }
        if (count!=0)
        return nullptr;
        while (slow!=nullptr)
        {
            slow=slow->next;
            fast=fast->next;
        }
        while (ori->next!=fast)
        {
            ori=ori->next;
        }
        ori->next=fast->next;

        return tempnode->next;


    }
};
int main()
{
    ListNode start;
    ListNode *temp=&start;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        ListNode *tempnode=new ListNode();
        cin>>tempnode->val;
        temp->next=tempnode;
        temp=temp->next;
    }
    Solution s;
    int m;
    cin>>m;
    ListNode *ans=s.removeNthFromEnd((&start)->next,m);
    while (ans!=nullptr)
    {
    cout<<ans->val<<endl;
    ans=ans->next;
    }
    return 0;
}