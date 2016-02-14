

// Exclusion Inclusion principle TLE
/*
class NumMatrix {
    vector<vector<int>> sumMatrix;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        this->sumMatrix = matrix;
        for(int i = 0, n = matrix.size(); i < n; ++i) {
            for(int j = 0, m = matrix[0].size(); j < m; ++j) {
                int top = (i > 0) ? sumMatrix[i - 1][j] : 0;
                int left = (j > 0) ? sumMatrix[i][j - 1]: 0;
                int corner = (i > 0 and j > 0) ? sumMatrix[i - 1][j - 1] : 0;
                sumMatrix[i][j] += (top + left - corner);
            }
        }
    }

    void update(int row, int col, int val) {
        int dx = val - sumMatrix[row][col];
        for(int i = row, n = sumMatrix.size(); i < n; ++i) {
            for(int j = col, m = sumMatrix[0].size(); j < m; ++j) {
                sumMatrix[i][j] += dx;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int top = (row1 > 0) ? sumMatrix[row1 - 1][col1] : 0;
        int left = (col1 > 0) ? sumMatrix[row1][col1 - 1]: 0;
        int corner = (row1 > 0 and col1 > 0) ? sumMatrix[row1 - 1][col1 - 1] : 0;
        int result = sumMatrix[row2][col2] - top - left + corner;
        
        return result;
    }
};
*/

// Quad tree RE (don't know why)
/*
class NumMatrix {
    vector<int> segmentSum;
    int n, m;
    int build(int node, int top, int left, int bottom, int right, vector<vector<int>> const& matrix) {
        if(top > bottom or left > right) {
            return 0;
        }
        if(top == bottom and left == right) {
            return segmentSum[node] = matrix[top][left];
        }
        segmentSum[node] += build(4 * node - 2, top, left, (top + bottom) / 2, (left + right) / 2, matrix);
        segmentSum[node] += build(4 * node - 1, (top + bottom) / 2 + 1, left, bottom, (left + right) / 2, matrix);
        segmentSum[node] += build(4 * node + 0, top, (left + right) / 2 + 1, (top + bottom) / 2, right, matrix);
        segmentSum[node] += build(4 * node + 1, (top + bottom) / 2 + 1, (left + right) / 2 + 1, bottom, right, matrix);
        
        return segmentSum[node];
    }
    
    int query(int node, int top, int left, int bottom, int right, int row1, int col1, int row2, int col2) {
        if(row1 > bottom or row2 < top or col1 > right or col2 < left or top > bottom or left > right) {
            return 0;
        }
        if(top >= row1 and bottom <= row2 and left >= col1 and right <= col2) {
            return segmentSum[node];
        }
        int result = 0;
        result += query(4 * node - 2, top, left, (top + bottom) / 2, (left + right) / 2, row1, col1, row2, col2);
        result += query(4 * node - 1, (top + bottom) / 2 + 1, left, bottom, (left + right) / 2, row1, col1, row2, col2);
        result += query(4 * node + 0, top, (left + right) / 2 + 1, (top + bottom) / 2, right, row1, col1, row2, col2);
        result += query(4 * node + 1, (top + bottom) / 2 + 1, (left + right) / 2 + 1, bottom, right, row1, col1, row2, col2);
        
        return result;
    }
    
    int update(int node, int top, int left, int bottom, int right, int row, int col, int val) {
        if(top > bottom or left > right) {
            return 0;
        }
        if(row > bottom or row < top or col > right or col < left) {
            return segmentSum[node];
        }
        if(row == top and row == bottom and col == left and col == right) {
            return segmentSum[node] = val;
        }
        
        int result = 0;
        result += update(4 * node - 2, top, left, (top + bottom) / 2, (left + right) / 2, row, col, val);
        result += update(4 * node - 1, (top + bottom) / 2 + 1, left, bottom, (left + right) / 2, row, col, val);
        result += update(4 * node + 0, top, (left + right) / 2 + 1, (top + bottom) / 2, right, row, col, val);
        result += update(4 * node + 1, (top + bottom) / 2 + 1, (left + right) / 2 + 1, bottom, right, row, col, val);
        
        return segmentSum[node] = result;
    }
    
public:
    NumMatrix(vector<vector<int>> &matrix) {
        n = matrix.size();
        if(n == 0) return;
        m = matrix[0].size();
        segmentSum.resize(2 * n * m, 0);
        build(1, 0, 0, n - 1, m - 1, matrix);
    }

    void update(int row, int col, int val) {
        update(1, 0, 0, n - 1, m - 1, row, col, val);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(1, 0, 0, n - 1, m - 1, row1, col1, row2, col2);
    }
};
*/