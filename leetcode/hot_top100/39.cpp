#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(ans,0,path,target,candidates,0);
        return ans;
    }
    void dfs( vector<vector<int>> &ans,int sum,vector<int> &path,int target,vector<int>& candidates,int j)
    {
        if (sum>target)
        {
            return;
        }
        if (sum==target)
        {
            ans.push_back(path);
            return;
        }
        for (int i=j;i<candidates.size();i++)
        {
            path.push_back(candidates[i]);
            dfs(ans,sum+candidates[i],path,target,candidates,i);
            path.pop_back();
        }
        return;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    for (int i=0;i<n;i++)
    cin>>nums[i];
    Solution s;
    vector<vector<int>> ans=s.combinationSum(nums,m);
    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[i].size();j++)
          cout<< ans[i][j]<<" ";
    
     cout<<endl;


    }
    return 0;
}