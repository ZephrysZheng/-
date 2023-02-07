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
        if (nums[pos1]!=target&&nums[pos2]!=target) return ans;
        ans[0]=pos1;
        ans[1]=pos2;
        return ans;
