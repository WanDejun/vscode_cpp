#include<bits/stdc++.h>
using namespace std;    

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        auto check = [&](int i)->bool {
            if (veganFriendly && !restaurants[i][2]) return false;
            if (maxPrice < restaurants[i][3]) return false;
            if (maxDistance < restaurants[i][4]) return false;
            return true;
        };
        vector<int> ret;
        int n = restaurants.size();
        for (int i = 0; i < n; i++) {
            if (check(i)) ret.push_back(i);
        }
        sort(ret.begin(), ret.end(), [&](int& a, int& b) {
            return restaurants[a][1] == restaurants[b][1] ? restaurants[a][0] < restaurants[b][0] : restaurants[a][1] > restaurants[b][1];
        });
        for (int& n : ret) n = restaurants[n][0];
        return ret;
    }
};
signed main() {
    Solution S;
    
    system("pause");

    return 0;
}