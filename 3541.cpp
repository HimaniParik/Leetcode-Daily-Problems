class Solution {
public:
    bool isVowel(char c)
    {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    int maxFreqSum(string s) {
        unordered_map<int,int>mp;
        int maxVowel=0;
        int maxCon=0;
        for(char c:s)
        {
            if(isVowel(c))
            {
                mp[c]++;
                 maxVowel=max(maxVowel,mp[c]);
            }
           
            else 
            {
                mp[c]++;
                maxCon=max(maxCon,mp[c]);
            }

        }
        return maxVowel+maxCon;

    }
};