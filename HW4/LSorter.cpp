//referenced http://stackoverflow.com/questions/7685/merge-sort-a-linked-list
//collaborator: Allison Durkan

#include "LSorter.hpp"
#include "LNode.hpp"
#include <iostream>

LNode* LSorter::sortList(LNode* head)
{
    int size=1;//size of list
    int count = 0;//number of mergeSorts executed
    int first_size;//size of first half
    int second_size;//size of second half
    
    LNode *end;
    
    LNode *left;
    LNode *right;
    
    LNode *next;
    
    //if the list has 0 or 1 elements, return the list
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    while (count == 0 || count > 2)//if program doesn't enter second loop-- list sorted
    {
        count=1;
        left=head;
        end=0;
        head=0;
        
        
        
        //loop through array until end
        while (left != NULL)
        {
            right=left;
            
            second_size=size;
            first_size=0;
            
            count++;//keep track of number of Merge Sorts
            
            //change right LNode and size of first half of list to split list
            while (right != NULL && first_size < size)
            {
                first_size++;
                right=right->next;
            }
            
            //move through both first list and second list, changing next LNode based on sorting conditions
            while ((second_size > 0 && right != NULL) || first_size > 0)
            {
                //if first half empty, use next right value
                if (first_size == 0)
                {
                    next=right;
                    right=right->next;
                    second_size--;
                }
                //if second half empty, use next left value
                else if (second_size == 0 || right == NULL)
                {
                    next=left;
                    left=left->next;
                    first_size--;
                }
                //compare actual values of the LNodes
                else if (right->val > left->val)
                {
                    next=left;
                    left=left->next;
                    first_size--;
                }
                //move through
                else
                {
                    next=right;
                    right=right->next;
                    second_size--;
                }
                
                //update class variables of end
                if (end != NULL)
                {
                    end->next=next;
                }
                
                else
                {
                    head=next;
                }
                
                //keep track of end of list by setting to next value
                end=next;
            }
            
            //set values for next iteration of mergesort
            left=right;
        }
        
        //when finished,set pointer to next value to NULL and update size of list
        end->next=0;
        size = size * 2;
    }
    return head;
}



