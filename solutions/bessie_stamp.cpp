#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> rotate(vector<vector<char>>& stamp, int rotations) {
    rotations %= 4;
    if (rotations == 0) return stamp;
    
    int k = (int) stamp.size();
    vector<vector<char>> ans = stamp;

    for (int r = 0; r < rotations; ++r) {
        vector<vector<char>> temp = ans;
        for (int i = 0; i < k; i ++) {
            for (int j = 0; j < k; j ++) {
                ans[j][k-1-i] = temp[i][j];
            }
        }
    }
    return ans;
}

bool check(vector<vector<char>>& stamp ,vector<vector<char>>& desire, int i, int j) {
    int k = (int) stamp.size();
    for (int a = 0; a < k; a ++) {
        for (int b = 0; b < k; b ++) {
            if (stamp[a][b] == '*' && desire[i+a][j+b] == '.') return false;
        }
    }
    return true;
}

vector<vector<char>> stamping( int i, int j, vector<vector<char>>& ans,vector<vector<char>>& stamp) {
    int k = (int) stamp.size();
    for (int a = 0; a < k; a ++) {
        for (int b = 0; b < k; b ++) {
            if (stamp[a][b] == '*') ans[i+a][j+b] = '*';
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        vector<vector<char>> d(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> d[i][j];
            }
        }
        cin >> k;
        vector<vector<char>> s(k, vector<char>(k));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                cin >> s[i][j];
            }
        }

        vector<vector<char>> canvas(n, vector<char>(n, '.'));

        for (int r = 0; r < 4; r++) {
            // loop through every (i, j)
            // rotate the stamp
            vector<vector<char>> rstamp = rotate(s,r);

            for(int i = 0; i <= n-k; i++){
                for(int j = 0; j <= n-k; j++){
                    // check if the stamp is within the bounds of the desired painting (does the ink overlap the white spots on desired?)
                    // if it is, stamp and continue
                    if(check(rstamp,d,i,j)) {
                        canvas = stamping(i,j,canvas,rstamp);
                    }
                    // if it isn't, dont do anything
                }
            }
        }

        // check if the desired painting is equal to the resultant painting
        bool p = true;
        for (int i = 0; i < n; i ++) {
            if (!p) break;
            for (int j = 0; j < n; j ++) {
                //cout << canvas[i][j] << " ";
                if (d[i][j] != canvas[i][j]) {
                    p = false;
                }
            }
            //cout << endl;
        }
        if (p) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        //cout << endl; // Add an extra line break for clarity
    }
}


