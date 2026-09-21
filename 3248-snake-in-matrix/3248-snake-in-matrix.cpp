class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i=0;
        int j=0;
        int row=0;
        int col=0;
        for(auto &cmd : commands){
            if(cmd=="RIGHT"){
                col++;
            }
            else if(cmd=="LEFT" ){
                col--;
            }else if(cmd=="UP" ){
               row--;
            }else{
                row++;
            }

        }
        return (row*n)+col;
    }
};