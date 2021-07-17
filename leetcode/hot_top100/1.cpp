/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int i=0;
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        int left=0;
        int right=temp.size()-1;
        
        while (left<right)
        {
            if (temp[left]+temp[right]<target)
            {
                left++;
            }
            else if (temp[left]+temp[right]>target)
            {
                right--;
            }
            else break;
        }
        for (i=0;i<nums.size();i++)
        {
            if ((ans.size()==0&&nums[i]==temp[left])||(nums[i]==temp[left]&&i!=ans[ans.size()-1]))
            ans.push_back(i);
            if ((ans.size()==0&&nums[i]==temp[right])||(nums[i]==temp[right]&&i!=ans[ans.size()-1]))
            ans.push_back(i);
            if (ans.size()==2)
            break;
        }
        return ans;

    }
};
int main()
{
    Solution s;
    int n;
    int target;
    cin>>n>>target;
    vector<int> nums(n);
    for (int i=0;i<n;i++)
    cin>>nums[i];
    vector<int> ans=s.twoSum(nums,target);
    cout<<ans[0]<<' '<<ans[1];
    return 0;
}