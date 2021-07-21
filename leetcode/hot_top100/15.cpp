#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        if (n<3) return ans;
        sort(nums.begin(),nums.end());
        int count=0;
        int mid=1;
        int right=n-1;
        for (int i=0;i<n-2;i++)
        {
            if (i>=1&&nums[i]==nums[i-1])
            {
                continue;
            }
            else 
            {
                mid=i+1;
                right=n-1;
              
                while (mid<right)
                {
                    if (nums[mid]+nums[right]==-nums[i])
                    {
                        if (count>0&&nums[mid]==ans[count-1][1]&&nums[i]==ans[count-1][0])
                        {
                           mid++;
                           continue;
                        }
                        else {
                             vector<int> temp;
                            temp.push_back(nums[i]);
                            temp.push_back(nums[mid]);
                            temp.push_back(nums[right]);
                            ans.push_back(temp);
                            count++;


                        }  
                        mid++;
                        right--;  

                    }
                    else if (nums[mid]+nums[right]<-nums[i])
                    {
                        mid++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }
        return ans;
        
        
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
 
    for (int i=0;i<n;i++)
    cin>>nums[i];
    Solution s;
    vector<vector<int>> ans=s.threeSum(nums);
    if (ans.size()==0) cout<<"[]";
    for (int i=0;i<ans.size();i++)
    {
    for (int j=0;j<ans[0].size();j++)
    cout<<ans[i][j]<<" ";
    cout<<endl;
    }
    return 0;
}