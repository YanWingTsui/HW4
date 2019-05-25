#include "stack.h"

namespace nodespace{
	
    void SList::push(const node::value_type& entry){
		if(list_length == 0){
			node* temp = new node(entry, NULL);
			head_ptr = temp;
			tail_ptr = temp;
			list_length ++;
		}
		else if(list_length == 1){
			node* temp = new node(entry, NULL);
			head_ptr->set_link(temp);
			tail_ptr = temp;
			list_length ++;
		}
		else{
			node* temp = new node(entry, NULL);
			tail_ptr->set_link(temp);
			tail_ptr = temp;
			list_length ++;
		}
	};

        int SList::top()
        {
                if(list_length ==0)
                        ewturn 0;
                else
                        return tail_ptr->data();
        };         
        
        void SList::pop
        {
                if(list_length <= 0)
                        return;
                else if(list_length ==1)
                {
                        node*temp = head_ptr;
                        head_ptr = NULL;
                        tail_ptr = NULL;
                        delete temp;
                        list length--;
         }
         else
         {
                node* pointer;
                node* temp;
                for(pointer = head_ptr; pointer != NULL; pointer = pointer -> link())
                {
                        temp = pointer->link();
                        if(temp->link() == NULL)
                        {
                                pointer->set_link(NULL);
                                tail_ptr = pointer;
                                delete temp;
                                list_length--;
                                break;
                         }
                 }
           }
};
        
        const std::size_t SList::size()
        {      
               return list_length;
        };
        
        void SList::Printing()
        {
                if(list_length == 0)
                        std::cout<<"empty"<<std::endl;
                else
                {
                        node* pointer;
                        for(pointer = head_ptr; pointer != NULL; ponter->link())
                        {
                                std::cout<<pointer->data()<<std::endl;
                        }
                }
        };
        
        bool SList::EMPTY()
        {
                if(list_length == 0)
                        return true;
                else
                        return false;
        }
}
        
        
             
