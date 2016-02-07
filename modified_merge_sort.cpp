class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end){
        int i=start, j=mid+1;
        while(nums[i]!=0){
            i++;
            if(i==mid+1)            // there are no zeroes
                return;
        }
        while(nums[j]!=0){
            nums[i] = nums[j];
            nums[j] = 0;
            j++;
            i++;
            if(j==end+1)
                break;
        }
    }
    
    void modified_merge_sort(vector<int>& nums, int start, int end){
        if(start==end){
            return;
        }
        int mid = (start+end)/2;
        modified_merge_sort(nums,start,mid);
        modified_merge_sort(nums,mid+1,end);
        merge(nums, start, mid, end);
    }
    
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int start=0, end=n-1;
        modified_merge_sort(nums, start, end);
    }
};