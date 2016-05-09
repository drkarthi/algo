class Solution {
public:
    int max(int a, int b) {
        if(a>=b)
            return a;
        return b;
    }

    int rob(vector<int>& nums) {
        int i, n=nums.size();
        if(n==0)
            return 0;
        int* d = (int*)malloc(sizeof(int)*n);
        d[0] = nums[0];
        d[1] = max(nums[0],nums[1]);
        for(i=2;i<n;i++) {
            d[i] = max(d[i-2]+nums[i], d[i-1]);
        }
        return d[n-1];
    }
};