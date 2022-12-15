#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> hash(128);
        
        for(char i : s) {
            hash[(int)i] = {hash[(int)i].first+1, i};
        }

        sort(hash.begin(), hash.end());
        
        string returnstring = " ";
        for(int i = hash.size()-1; i >= 0; i--) {
            cout << hash[i].first << " " << hash[i].second << endl;
            for(int i2 = 0; i2 < hash[i].first; i2++) {
                returnstring.insert(returnstring.length()-1, 1, hash[i].second);
            }
        }

        return returnstring.erase(returnstring.length()-1);
    }
};