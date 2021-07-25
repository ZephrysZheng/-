#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
char l[2]={'(',')'};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string strtemp="";
        vector<string> ans;
        int count1=0;
        int count2=0;
        if (n==0) return ans;
        dfs(0,ans,strtemp,2*n,0,0);
        return ans;
    }
    void dfs(int k, vector<string> &ans,string &strtemp,int n,int count1,int count2)
    {
        if (count2>count1)
        return ;
        if (k==n)
        {
            if (check(strtemp))
            {
            ans.push_back(strtemp);
            }
            return;
        
        }
     
        for (int i=0;i<2;i++)
        {
            if (i==0&&count1<n/2)
            {
            strtemp=strtemp+l[0];
            dfs(k+1,ans,strtemp,n,count1+1,count2);
            strtemp=strtemp.substr(0,strtemp.size()-1);
            }
            else if(i==1&&count2<n/2)
            {
                 strtemp=strtemp+l[1];
            dfs(k+1,ans,strtemp,n,count1,count2+1);
            strtemp=strtemp.substr(0,strtemp.size()-1);

            }
        }
        return;
    }
    bool check(string s)
    {
        int n=s.size();
        stack<char> ss;
        int i=0;
        while (i<n)
        {
            if (s[i]=='(')
            {
                ss.push(s[i]);
            }
            else 
            {
                if (ss.empty())
                return false;
                else 
                {
                    ss.pop();
                }
            }
            i++;
        }
        if (ss.empty())
        return true;
        else return false;
    }
};
int main()
{
    int n=0;
    cin>>n;
    Solution s;
    vector<string> ans=s.generateParenthesis(n);
    for (int i=0;i<ans.size();i++)
    cout<<ans[i]<<endl;
    return 0;
}