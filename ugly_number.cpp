class Solution {
public:
    bool isUgly(int num) {
        int i, prev_num=0;
        while(num!=prev_num) {
            prev_num = num;
            for(i=2;i<6;i++) {
                if(num%i==0)
                    num /= i;
            }
        }
        return(num==1);
    }
};