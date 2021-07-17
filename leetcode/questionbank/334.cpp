#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
         if (len < 3) return false;
         int small = INT_MAX, mid = INT_MAX;
         for (auto num : nums) {
          if (num <= small) {
              small = num;
             } else if (num <= mid) {
           mid = num;
         } 
      else if (num > mid) {
        return true;
      }
    }
    return false;  
    }
};
int main()
{
    int count;
    cin>>count;
    vector<int> nums(count,0);
    for (int i=0;i<count;i++)
    cin>>nums[i];
    bool answer;
    Solution s;
    answer=s.increasingTriplet(nums);
    cout<<answer<<endl;
    return 0;

}