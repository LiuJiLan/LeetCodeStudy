//2020.10.11_#0_BestVotes

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), less<int>());
        sort(s.begin(), s.end(), less<int>());
        
        int i = 0;
        for (int j = 0; i < g.size() && j < s.size(); j++) {
            if (g[i] <= s[j]) {
                i++;
            }
        }
        
        return i;
    }
};

//BestVotes_Java
/*
Arrays.sort(g);
Arrays.sort(s);
int i = 0;
for(int j=0;i<g.length && j<s.length;j++) {
    if(g[i]<=s[j]) i++;
}
return i;
*/
