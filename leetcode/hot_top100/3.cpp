#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if (n==0) return 0;
        if (n==1) return 1;
        int max=1;
        int left=0;
        int right=1;
        map<char,bool> mark;
        mark[s[0]]=true;
        while (right<n)
        {
            if (mark[s[right]]==true)
            {
                if (right-left>max)
                max=right-left;
                while(s[right]!= s[left])
                {
                    mark[s[left]]=false;
                    left++;
                }
                left++;
                right++;
            }
            else{
                mark[s[right]]=true;
                right++;
            }

        }
        if (right-left>max)
                max=right-left;
        return max;

    }
};
int main()
{
    string str;
    cin>>str;
    Solution s;
    int ans;
    ans=s.lengthOfLongestSubstring(str);
    cout<<ans;
    return 0;
}