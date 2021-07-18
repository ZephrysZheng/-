/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}
};
class Solution
{
    public:
    ListNode * addTwoNumbers(ListNode * l1,ListNode *l2)
    {
        ListNode ans;
        ListNode *anshead=&ans;
        int flag=0;
        while (l1!=nullptr&&l2!=nullptr)
        {
            ListNode *temp=new ListNode();
            temp->val=l1->val+l2->val+flag;
            flag=0;
            if (temp->val>=10)
            {
                temp->val=temp->val%10;
                flag=1;
            }
            anshead->next=temp;
            anshead=anshead->next;
            l1=l1->next;
            l2=l2->next;
        }
        if (l1!=nullptr)
        {
            while (l1!=nullptr)
            {
            ListNode *temp=new ListNode();
            temp->val=l1->val+flag;
            flag=0;
            if (temp->val>=10)
            {
                temp->val=temp->val%10;
                flag=1;
            }
            anshead->next=temp;
             anshead=anshead->next;
            l1=l1->next;
            }
            
        }
        if (l2!=nullptr)
        {
             while (l2!=nullptr)
            {
            ListNode *temp=new ListNode();
            temp->val=l2->val+flag;
            flag=0;
            if (temp->val>=10)
            {
                temp->val=temp->val%10;
                flag=1;
            }
            anshead->next=temp;
             anshead=anshead->next;
            l2=l2->next;
            }
            
        }
        if (flag==1)
        {
        ListNode *temp=new ListNode();
            temp->val=flag;
            anshead->next=temp;
            flag=0;
        }
    return (&ans)->next;

    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    ListNode l1(-1);
    ListNode l2(-1);
    ListNode *l1head=&l1;
    ListNode *l2head=&l2;
    for (int i=0;i<n;i++)
    {
         if (l1head->val==-1)
         {
             cin>>l1head->val;
         }
         else
         {
             ListNode *temp=new ListNode();
             cin>>temp->val;
             l1head->next=temp;
             l1head=l1head->next;
         }
    }
        for (int i=0;i<m;i++)
    {
         if (l2head->val==-1)
         {
             cin>>l2head->val;
         }
         else
         {
             ListNode *temp=new ListNode();
             cin>>temp->val;
             l2head->next=temp;
             l2head=l2head->next;
         }
    }
    Solution s;
    ListNode *ans=s.addTwoNumbers(&l1,&l2);
    while (ans!=nullptr)
    {
        cout<<ans->val;
        ans=ans->next;
    }
    return 0;
}