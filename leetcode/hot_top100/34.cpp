#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0;
        int n=nums.size();
        int right=n-1;
        int pos1;
        int pos2;
        vector<int> ans={-1,-1};
        if (n==0) return ans;
        if (n==1) {
            if (nums[0]==target)
            {
                ans={0,0};
            return ans;
            }
            else {
                return ans;

            }
        }
        
        while (left<=right)
        {
            int mid=left+(right-left)/2;
            if (nums[mid]<target)
            {
                left=mid+1;

            }
            else
            {
                right=mid-1;
            }
        }
        pos1=left;
        left=0;
        right=n-1;
            while (left<=right)
        {
           int mid=left+(right-left)/2;
            if (nums[mid]>target)
            {
                right=mid-1;

            }
            else
            {
                left=mid+1;
            }
        }
        pos2=left-1;
        if ((pos2<0)||(pos1==n)||(nums[pos1]!=target&&nums[pos2]!=target)) return ans;
        ans[0]=pos1;
        ans[1]=pos2;
        return ans;

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
    vector<int> ans=s.searchRange(nums,m);
    cout<<ans[0]<<' '<<ans[1]<<endl; 
    return 0;
}