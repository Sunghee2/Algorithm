class Solution {
public:
    int map[101][101];
    
    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1) return 1;
        
        for(int i = 1; i < m; i++) map[0][i] = 1;
        for(int i = 1; i < n; i++) map[i][0] = 1;
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                map[j][i] = map[j - 1][i] + map[j][i - 1];
            }
        }
        
        return map[n - 1][m - 1];
    }
};

// dp문제