#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int j=height.size()-1;
        int i=0;
        int left=height[i];
        int right=height[j];
        int max=0;
        while (i<j)
        {
            left=height[i];
            right=height[j];
            if  (left<right)
            {
                if (left*(j-i)>max)
                max=left*(j-i);
                i++;
            }
            else{
                 if (right*(j-i)>max)
                max=right*(j-i);
                j--;
            }
        }
        return max;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> height(n);
    for (int i=0;i<n;i++)
    cin>>height[i];
    Solution s;
    int ans=s.maxArea(height);
    cout<<ans;
    return 0;
}