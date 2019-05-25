#include "stack_llist.h"
#include <vector>

bool conflict(int x, int y, int n, std::vector<std::vector<int>> z)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(z[i][j] == 1)
            {
                if(x == i || y == j)
                    return true;
                if(x-i)/(y-j) == -1 || (x-i)/(y-j) == 1)
                    return true;
            }
        }
    }
    return false;
}

void Q(int n){
    std::vector<std::vector<int>> BT;
    for(int a = 0; a < n; a++)
    {
        std::vector<int> x(n, 0);
        BT.push_back(x);
    }
    
    BT[0][0] = 1;
    
    nodespace::SList stakx;
    nodespace::SList staky;
    
    stakx.push(0);
    staky.push(0);
    
    bool success = false;
    while(!success && !stakx.empty())
    {
        bool gotThru = false;
        for(int c = 0; c < n; c++)
        {
            if(conflict(stakx.size(), c, n, BT) == false)
            {
               BT[stakx.size()][c] = 1;
                stakx.push(stakx.size());
                staky.push(c);
                gotThru = true;
                break;
            }
        }
    
        if(!gotThru){
            bool try = true;
            while(try && !stakx.empty())
            {
                int lastx = stakx.top();
                int lasty = staky.top();
                
                BT[lastx][lasty] = 0;
                stakx.pop();
                staky.pop();
               
                if(lasty < n-1)
                {
                    for(int d = lasty+1; d < n; d++)
                    {
                        if(conflict(stakx.size(), d, n, BT) == false)
                        {
                            BT[stakx.size()][d] = 1;
                            stakx.push(stakx.size());
                            staky.push(d);
                            try = false;
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
