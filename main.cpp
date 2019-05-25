#include "stack_llist.h"
#include <vector>

bool conflict(int a, int b, int n, std::vector<std::vector<int>> z){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(z[i][j] == 1){
                //check if (a,b) are in horizontal/vertical/diagnol of (i,j)
                if(a == i || b == j)
                    return true;
                //if slope is 1 or -1 they are diagnol
                if((a-i)/(b-j) == 1 || (a-i)/(b-j) == -1)
                    return true;
            }
        }
    }
    return false;
}

void nQueens(int n){
    std::vector<std::vector<int>> board;
    for(int i = 0; i < n; i++){
        std::vector<int> a(n, 0);
        board.push_back(a);
    }
    //created the board and put in first queen at (0,0)
    board[0][0] = 1;
    nodespace::SList stakx;
    nodespace::SList staky;
    stakx.push(0);
    staky.push(0);
    bool success = false;
    //program will run until n queens are placed or until stack is empty which means n queens is not possible like in a 2x2 board
    while(!success && !stakx.empty()){
        bool gotThru = false;
        //places a queen at the stack.size row at column i
        for(int i = 0; i < n; i++){
            //checks to see if any of the spots in that column cause conflict, if not then it places down a queen and skips back to start of while
            if(conflict(stakx.size(), i, n, board) == false){
                board[stakx.size()][i] = 1;
                stakx.push(stakx.size());
                staky.push(i);
                gotThru = true;
                break;
            }
        }
        //if all positions in the column cause conflict then we go back to the position of the last queen
        if(!gotThru){
            bool retry = true;
            while(retry && !stakx.empty()){
                //i take out the last position from the stack
                int lastx = stakx.top();
                int lasty = staky.top();
                board[lastx][lasty] = 0;
                stakx.pop();
                staky.pop();
                //i check to see if we can shift right, if not i go back to the beginning of this while loop and repeat until a place is found or stack is empty
                if(lasty < n-1){
                    for(int i = lasty+1; i < n; i++){
                        if(conflict(stakx.size(), i, n, board) == false){
                            board[stakx.size()][i] = 1;
                            stakx.push(stakx.size());
                            staky.push(i);
                            retry = false;
                            break;
                        }
                    }
                }
            }
        }
        if(stakx.size() >= n)
            success = true;
    }
    if(success){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                std::cout << board[i][j] << " ";
            }
            std::cout <<  "\n";
        }
    }
    else if(!success)
        std::cout << "N queens is not possible with the entered board size" << std::endl;
 }

int main(){
    
}
