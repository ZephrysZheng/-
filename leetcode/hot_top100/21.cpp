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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head;
        ListNode *temp=&head;
        while (l1!=nullptr&&l2!=nullptr)
    {
        if (l1->val<l2->val)
        {
            temp->next=l1;
            temp=temp->next;
            l1=l1->next;
        }
        else
        {
            temp->next=l2;
            temp=temp->next;
            l2=l2->next;
        }
    }
    if (l1!=nullptr)
    temp->next=l1;
    if (l2!=nullptr)
    temp->next=l2;
        return (&head)->next;

    }
};
int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;
    ListNode head1;
    ListNode head2;
    ListNode *temp1=&head1;
    ListNode *temp2=&head2;
    for (int i=0;i<n;i++)
    {
        ListNode *midnode=new ListNode();
        cin>>midnode->val;
        temp1->next=midnode;
        temp1=temp1->next;
    }
    for (int i=0;i<m;i++)
    {
        ListNode *midnode=new ListNode();
        cin>>midnode->val;
        temp2->next=midnode;
        temp2=temp2->next;
    }
    ListNode *ans=s.mergeTwoLists((&head1)->next,(&head2)->next);
    while (ans!=nullptr)
    {
        cout<<ans->val<<endl;
        ans=ans->next;
    }
    return 0;
}