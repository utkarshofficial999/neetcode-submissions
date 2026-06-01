class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()|| matrix[0].empty())
        return;
        int m=matrix.size();
        int n=matrix[0].size();
        pref.assign(m+1,vector<int>(n+1,0));
        for(int r=1;r<=m;r++){
            for(int c=1;c<=n;c++){
                pref[r][c]=matrix[r-1][c-1]+pref[r-1][c]+pref[r][c-1]-pref[r-1][c-1];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pref[row2+1][col2+1]-pref[row1][col2+1]-pref[row2+1][col1]+pref[row1][col1];
    }
    private:
vector<vector<int>>pref;
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */