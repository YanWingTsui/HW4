#include <stack>
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

#include "node.h"
#include "llist.h"

void n_queens(size_t n){
        if(n == 3 || n == 2){
                std::cout<<"there is not solution!"<<std::endl;
                return;
        }
        nodespace::stacks queens;
        size_t R = 1;
        size_t C = 1;
             for(size_t j = 1; j<row;j++){
                        for(size_t i = 0; i+1<row ;){
                                if(queens[i]->data() == column ||queens[i]->data() == column+row-i-1 ||queens[i]->data() == column-row+i+1){
                                        if(column <= n){
                                                column++;
                                        }
                                        if(column > n){
                                                break;
                                        }
                                }
                                else{
                                        i++;
                                }
                        }
                        if(column>n){
                                break;
                        }
                }
                if(column <= n){
                        row++;
                        queens.append(column);
                        column = 1;
                }
                else if(column>n){
                        row--;
                        column = queens.stacks_top()->data()+1;
                        if(row == 1){
                                queens.stacks_pop();
                                queens.append(column);
                                column = 1;
                                row++;
                        }
                        else{
                                queens.stacks_pop();
                        }
                }
        }
        if(row > n){
                std::cout<<"[";
                for(size_t k = 0;k<n;k++){
                        std::cout<<"("<<k+1<<","<<queens[k]->data()<<")";
                }
                std::cout<<"]"<<std::endl;
        }
        
}

int main(){
       
        return 0;
}
