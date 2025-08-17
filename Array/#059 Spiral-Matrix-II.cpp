class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        int left =0;
    int right = matrix[0].size() -1;
    int top = 0;
    int bottom = matrix[0].size()-1;
    int direction =0;
    int number=1;
    while (top<=bottom && left <=right){
        if (direction ==0){
            for (int col=left;col<=right;col++){
                matrix[top][col] =number;
                number ++;
            }
            top ++;
        }else if(direction==1){
            for (int row=top;row<=bottom;row++){
                matrix[row][right] =number;
                number ++;
            }
            right --;
        }else if (direction==2){
            for (int col =right;col>=left;col--){
                matrix[bottom][col] = number;
                number ++;
            }
            bottom--;
        }else {
            for (int row=bottom;row>=top;row--){
                matrix[row][left] = number;
                number ++;
            }left ++;
        }
        direction = (direction+1)%4;
    }
    return matrix;
        
    }
};