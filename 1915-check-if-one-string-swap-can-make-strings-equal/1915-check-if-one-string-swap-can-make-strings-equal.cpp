class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diffI;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            diffI.push_back(i);
        }
        if (diffI.size() > 2) return false; 
    }
    if (diffI.size() == 0) return true;  
    if (diffI.size() == 1) return false;
    int i = diffI[0];
    int j = diffI[1];
    return (s1[i] == s2[j] && s1[j] == s2[i]);
    }
};