#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        bool flag=false;
        int pos;
        int head;
       
        for (int i=0;i<n;i++)
        {
            int mid=INT_MAX;
            for (int j=i+1;j<n;j++)
            {
                if (nums[i]<nums[j]&&nums[j]<mid)
                {
                    head=i;
                    pos=j;
                    mid=nums[j];
                    flag=true;
                }
            }
        }
        if (!flag)
           {
               sort(nums.begin(),nums.end());
               return;
           }
        int temp=nums[head];
        nums[head]=nums[pos];
        nums[pos]=temp;
        sort(nums.begin()+head+1,nums.end());
        return;
        
        

    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    Solution s;
    s.nextPermutation(nums);
    for (int i=0;i<n;i++)
    cout<<nums[i]<<endl;
    return 0;
}