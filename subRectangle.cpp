#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maximalRectangleArea(vector<vector<int>>& matrix) {
    if(matrix.empty()) return 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> heights(m, 0);
    int maxArea = 0;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(matrix[i][j] == 0) {
                heights[j] = 0;
            } else {
                heights[j]++;
            }
        }
        stack<int> stk;
        for(int j = 0; j <= m; ++j) {
            int h = (j == m ? 0 : heights[j]);
            if(stk.empty() || h >= heights[stk.top()]) {
                stk.push(j);
            } else {
                int tp = stk.top();
                stk.pop();
                maxArea = max(maxArea, heights[tp] * (stk.empty() ? j : j - stk.top() - 1));
                --j;
            }
        }
    }
    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << maximalRectangleArea(matrix) << endl;
    return 0;
}
