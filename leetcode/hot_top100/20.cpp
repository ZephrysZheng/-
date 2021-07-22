#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        int n=s.size();
        int i=0;
        while(i<n)
        {
            if (s[i]=='}'||s[i]==']'||s[i]==')')
            {
             if (stack.empty())
               {
                return false;
                    }
                else
                {
                    char c=stack.top();
                    if ((c=='('&&s[i]==')')||(c=='['&&s[i]==']')||(c=='{'&&s[i]=='}'))
                    {
                        stack.pop();
                    }
                  else return false;
                 }
            }
            else 
            {
                stack.push(s[i]);
            }
           
            i++;

        }
        if (!stack.empty()) return false;
        return true;
    }
};

int main()
{
    string str;
    cin>>str;
    Solution s;
    bool ans=s.isValid(str);
    cout<<ans;
    return 0;
}