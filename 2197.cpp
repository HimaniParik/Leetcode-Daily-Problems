class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>result;
        for(int x:nums)
        {
            result.push_back(x);
            while(result.size()>1)
            {
                int a=result.back();
                int b=result[result.size()-2];
                int g=gcd(a,b);
                if(g>1)
                {
                    int l=(1ll*a*b)/g;
                    result.pop_back();
                    result.pop_back();
                    result.push_back((int)l);
                }
                else
                {
                    break;
                }
            }
        }
        return result;
    }
};