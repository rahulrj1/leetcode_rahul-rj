class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0; for(int &r: rolls) sum += r;
        
        int m = rolls.size();
        int restSum = (m+n)*mean - sum;
        if(restSum < n || restSum > 6*n) return {};
        
        int quo = restSum/n;
        int rem = restSum%n;
        vector<int> res(n);
        for(int i=0; i<rem; i++) res[i] = (quo+1);
        for(int i=0; i<n-rem; i++) res[i+rem] = (quo);
        return res;
    }
};