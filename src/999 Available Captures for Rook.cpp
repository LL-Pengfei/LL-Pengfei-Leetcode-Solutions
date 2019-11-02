//999. Available Captures for Rook
//https://leetcode.com/problems/available-captures-for-rook/

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ii,jj,res=0,A[8][8]={{0}}; //0 empty; 1 white; 2 black
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j]>='A' && board[i][j]<='Z') {
                    A[i][j] = 1;
                } else if (board[i][j]>='a' && board[i][j]<='z') {
                    A[i][j] = 2;
                }
                if (board[i][j] == 'R') ii=i, jj=j, A[i][j]=0;
                //to aid the looping later on
            }
        }
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        for (int i = 0; i < 4; ++i) {
            int iii=ii, jjj=jj; bool flag = false;
            while (iii>=0 && iii<8 && jjj>=0 && jjj<8) {
                if (A[iii][jjj] != 0) {flag = true; break;}
                iii += dr[i];
                jjj += dc[i];
            }
            if (flag && (A[iii][jjj]==2)) ++res;
        }
        return res;
    }
};
