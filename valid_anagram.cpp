class Solution {
public:
    vector<int>& updateHashTable(string a, vector<int>& hash){
        int i=0, index;
        while(a[i]!='\0'){
            index = int(a[i]) - 97;
            hash[index] += 1;
            i++;
        }
        return hash;
    }

    bool isAnagram(string s, string t) {
        vector<int> hash_s (26,0);
        vector<int> hash_t (26,0);
        hash_s = updateHashTable(s, hash_s);
        hash_t = updateHashTable(t, hash_t);
        int i;
        for(i=0;i<26;i++){
            if(hash_s[i]!=hash_t[i])
                return false;
        }
        return true;
    }
};