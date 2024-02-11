class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int up=1;

        int rows=mat.size();
        int cols=mat[0].size();
        int r=0;
        int c=0;
        while(ans.size()!=rows*cols)
        
        if(up){
        while(r>=0 && c<cols){
        ans.push_back(mat[r][c]);
        r=r-1;
        c=c+1;
        }
        up=0;
        if(c==cols) {r=r+2;c=c-1;}
        else r=r+1;

        }
        else{
            while(r<rows && c>=0){
                ans.push_back(mat[r][c]);
                r=r+1;
                c=c-1;

            }
            up=1;
            if(r==rows){
                r=r-1;
                c=c+2;
            }
            else c=c+1;
        }

        return ans;
    }
};