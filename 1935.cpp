class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char, int> mp;
        int count = 0;
        mp.clear();
        for (char& ch : brokenLetters) {

            mp[ch]++;
        }
        string word;
        stringstream ss(text);
        while (ss >> word) {
            bool canPlace = true;
            for (char& ch : word) {

                if (mp.find(ch) != mp.end()) {
                    canPlace = false;
                }
            }
            if (canPlace)
                count++;
        }

        return count;
    }
};