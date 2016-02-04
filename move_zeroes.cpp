class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i,j;
        for(i=0;i<n;i++){
            for(j=0;j<n-i-1;j++){
                if(nums[j]==0){
                    nums[j] = nums[j+1];
                    nums[j+1] = 0;
                }
            }
        }
    }
};