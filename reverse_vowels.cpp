class Solution {
public:
    bool isVowel(char c) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') {
            return true;
        }
        return false;
    }

    string reverseVowels(string s) {
        int i=0, j=s.length()-1;
        char temp;
        while(i<=j) {
            while(isVowel(s[i]) == false && i<s.length())
                i++;
            while(isVowel(s[j]) == false && j>=0)
                j--;
            if(i>j)
                break;
            else {    
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
        }
        return s;
    }
};