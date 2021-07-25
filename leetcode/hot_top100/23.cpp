#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode * next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
    
        ListNode *ans=nullptr;
        for (int i=0;i<n;i++)
        {
            ans=mergeKLists(ans,lists[i]);
        }
        return ans;

    }
    ListNode *mergeKLists(ListNode* l1,ListNode* l2)
    {
        ListNode temphead;
        ListNode *ptemphead=&temphead;
        while (l1!=nullptr&&l2!=nullptr)
        {
            if (l1->val<l2->val)
            {
                ptemphead->next=l1;
                l1=l1->next;
                ptemphead=ptemphead->next;
            }
            else{
                  ptemphead->next=l2;
                l2=l2->next;
                ptemphead=ptemphead->next;
            }
        }
        if (l1!=nullptr)
        ptemphead->next=l1;
        if (l2!=nullptr)
        ptemphead->next=l2;
        return (&temphead)->next;
    }
};
int main()
{
    vector<ListNode*> l;
    int n;
    cin>>n;
    ListNode headcommon;
    for (int i=0;i<n;i++)
    {
        int m;
        cin>>m;
       
        ListNode *phead=&headcommon;
        for (int j=0;j<m;j++)
        {
            ListNode *temp=new ListNode();
            cin>>temp->val;
            phead->next=temp;
            phead=phead->next;
        }
        l.push_back((&headcommon)->next);
    }
    Solution s;
    ListNode* ans=s.mergeKLists(l);
    while (ans!=nullptr)
    {
    cout<<ans->val<<endl;
    ans=ans->next;
    }
    return 0;
}
