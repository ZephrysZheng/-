#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,vector<char>> dict;
        vector<char> temp={'a','b','c'};
        dict['2']=temp;
          temp={'d','e','f'};
        dict['3']=temp;
          temp={'g','h','i'};
        dict['4']=temp;
         temp={'j','k','l'};
        dict['5']=temp;
         temp={'m','n','o'};
        dict['6']=temp;
        temp={'p','q','r','s'};
        dict['7']=temp;
         temp={'t','u','v'};
        dict['8']=temp;
         temp={'w','x','y','z'};
        dict['9']=temp;
        int n=digits.size();
        vector<string> ans;
        if (n==0) return ans;
        string strtemp="";
        dfs(dict,0,digits,strtemp,ans);
        return ans;
    }
    void dfs(map<char,vector<char>> dict,int pos, string digits,string &strtemp, vector<string> &ans)
    {
        if (pos==digits.size())
        {
            ans.push_back(strtemp);
            return;
        }
        for (int i=0;i<dict[digits[pos]].size();i++)
        {
            strtemp+=dict[digits[pos]][i];
            dfs(dict,pos+1,digits,strtemp,ans);
            strtemp=strtemp.substr(0,strtemp.size()-1);
        }
        return;



    }
};
int main()
{
    string digits;
    cin>>digits;
    Solution s;
    vector<string> ans=s.letterCombinations(digits);
    for (int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}