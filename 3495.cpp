class Solution {
public:
    long long solve(long long l,long long r)
    {
        long long  left=1;
       
        long long  step=1;
        long long count=0;
        while(left<=r)
        {
            long long right=(left*4)-1;
            long long start=max(left,l);
            long long end=min(right,r);
            if(start<=end)
            {
                count +=(end-start+1)*step;


            }
            step++;
            left=left*4;
            
        }
        return count;
    }
    long long minOperations(vector<vector<int>>& queries) 
    {
         long long result=0;
         for(auto&query:queries)
         {
            long long l=query[0];
            long long r=query[1];
            long long steps=solve(l,r);
            result+=(steps+1)/2;
         }
         return result;
    }
};__

