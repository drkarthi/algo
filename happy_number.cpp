class Solution {
public:
    int sum_of_square_of_digits(int n) {
        int digit,sum = 0;
        while(n!=0) {
            digit = n%10;
            n = n/10;
            sum += digit*digit;
        }
        return sum;
    }

    bool isHappy(int n) {
        // initialization
        int sum,i;
        vector<int> nums;
        // check for happy number
        while(true) {
            nums.push_back(n);
            sum = sum_of_square_of_digits(n);
            if(sum==1)
                return true;
            for(i=0;i<nums.size();i++) {
                if(nums[i]==sum)
                    return false;
            }
            n = sum;
        }
    }
};