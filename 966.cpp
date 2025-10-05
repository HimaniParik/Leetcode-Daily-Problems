class Solution {
public:
    unordered_set<string>exactSet;
    unordered_map<string,string>vowelmp;
    unordered_map<string,string>casemp;
    string toLower(string &s)
    {
        string result=s;
        for(char&ch:result)
        {
            ch=tolower(ch);
        }
        return result;
    }
    string replaceVowel(string&s)
    {
        string result=s;
        for(char&ch:result)
        {
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            {
                ch='*';
            }
        }
        return result;
    }
    string checkForMatch(string &query)
    {
        if(exactSet.count(query))
        {
            return query;
        }
        // case error check
        string lowercase=toLower(query);
        if(casemp.count(lowercase))
        {
            return casemp[lowercase];
        }
        // vowel error check
        string vowelcase=replaceVowel(lowercase);
        if(vowelmp.count(vowelcase))
        {
            return vowelmp[vowelcase];
        }
        return"";
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactSet.clear();
        vowelmp.clear();
        casemp.clear();
            
        for(string word:wordlist)
        {
            exactSet.insert(word);
            string lowercase=toLower(word);
            if(casemp.find(lowercase)==casemp.end())
            {
                casemp[lowercase]=word;
            }
            string vowelcase=replaceVowel(lowercase);
            
                if(vowelmp.find(vowelcase)==vowelmp.end())
                {
                    vowelmp[vowelcase]=word;
                }
             
           
        }
         vector<string>result;
         for(string& query:queries)
            {
                result.push_back(checkForMatch(query));
            }
        return result;
    }
};