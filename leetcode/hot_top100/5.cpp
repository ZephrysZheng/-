#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int max1=-1;
        int max2=-1;
        int pos1=0;
        int pos2=0;
        int length=s.size();
        int n=(s.size()-1)/2;
        
            for (int j=0;j<length;j++)
            {
                for (int i=0;i<=n;i++)
            {
                if (j-i>=0&&j+i<length&&s[j-i]==s[j+i])
                {
                     if (i>max1)
                    {
                        max1=i;
                        pos1=j;
                        
                    }
                    continue;
                }
                else{
                   
                    break;
                }
            }
        }
      
            for (int j=0;j<length;j++)
            {
                      for (int i=0;i<=n;i++)
        {
                if (j-i>=0&&j+i+1<length&&s[j-i]==s[j+i+1])
                {
                     if (i>max2)
                    {
                        max2=i;
                        pos2=j;
                        
                    }
                    continue;
                }
                else{
                   
                    break;
                }
            }
        }
        string ans;
        if (2*(max2+1)>2*max1+1)
        ans=s.substr(pos2-max2,2*(max2+1));
        
        else  ans=s.substr(pos1-max1,2*max1+1);

        return ans;
    }
};
int main()
{
    string ans;
    string str;
    cin>>str;
    Solution s;
    ans=s.longestPalindrome(str);
    cout<<ans;
    return 0;
}