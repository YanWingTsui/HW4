#include <iostream>

#include "node.h"
#include "llist.h"

void n_queens(size_t n){
        if(n == 2 || n == 3){
                std::cout<<"No solution!"<<std::endl;
                return;
        }
        nodespace::stacks queens;
        size_t row = 1;
        size_t column = 1;
        for(;row<=n;){
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
        //node* tail = new node(1.0);
        //node* second = new node(2.0, tail);
        //node* third = new node(3.0, second);
        //nodespace::node A(2);
        //A = 5;
        //std::cout<<A.data()<<std::endl;
        /*
        nodespace::LList mylist;
        mylist.append(47);
        mylist.append(20);
        mylist.append(45);
        mylist.append(47);
        mylist.append(416);
        mylist.append(47);
        frequency(mylist);
        */
        //mylist.insert(3,7);
        //std::cout<<mylist.search(7)->data()<<std::endl;
        //std::cout<<mylist.locate(5)->data()<<std::endl;
        //std::cout<<mylist.remove(4)<<std::endl;
        //mylist.clear();
        //nodespace::LList newlist;
        //newlist = mylist.copy();
        //mylist.clear();
        // Frequency left to implement
        return 0;
}
