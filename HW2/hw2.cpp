//Hannah Hebert-- EC330 HW2 Funciton

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;


//function to be used by qsort: comparing two elements and then is used as
//argument to change what is pointed to in array nums from cplusplus.com
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int Sum(int *nums, int len)
{
    int nearSum=INT_MAX; //variable to store closest sum to 330
    int diff=INT_MAX; //variable to find how far sum is away from 330 +/-
    
    
    //if an array is only 1 element, return that element
    if(len==1)
    {
        return nums[0];
    }
    
    //if array has 2 elements check to see if their sum is greater than individual elements
    if(len==2)
    {
        diff = abs(nums[0]+nums[1]-330);//set diff
        
        if((330-nums[0] <= diff) && (330-nums[1] >= diff)) //if the first element is closer than the sum and further than the second element, return first
        {
            return nums[0];
        }
        else if((330-nums[0] >= diff) && (330-nums[1] <= diff))//if the second element is closer than the sum and further than the first element, return second
            
        {
            return nums[1];
        }
        else
            return nums[0]+nums[1]; //otherwise return sum of 2 numbers
    }
    
    //sort array in ascending order using function qsort of cstdlib
    qsort(nums,len,sizeof(int),compare);
    
    for(int i=0; i<(len-1);i++)
    {
        int j=i+1;//one element after i
        int k=len-1;//last element in array
        
        while(k >= j)//so no repeating comparisons
        {
            //conditions for a 3-int sum
            if(abs(nums[k] + nums[j] +nums[i]- 330) <= diff) //if the current comparison is closer to 330 than past comparison, replace nearSum with new closer sum and update diff
            {
                nearSum=nums[k]+nums[j]+nums[i];
                diff=abs(nums[k] + nums[j] +nums[i]- 330);
            }
            
            if(nums[j]+nums[k]+nums[i]>=330)//move k towards the right of the array
                k--;
            
            else
                j++; //move j towards the left of the array
            
            
            //conditions for if a 2-int sum is a better match than the 3-int sum
            //check and make sure that no additions of only 2 array values are closer than the 3-sum values
            if(abs(nums[k]+nums[j]-330) <= diff)
            {
                nearSum=nums[k]+nums[j];
                diff=abs(nums[k] + nums[j]- 330);
            }
            else if(abs(nums[k]-nums[i]-330) <= diff)
            {
                nearSum=nums[k]+nums[i];
                diff=abs(nums[k] + nums[i]- 330);
            }
            else if(abs(nums[i]+nums[j]-330) <= diff)
            {
                nearSum=nums[i]+nums[j];
                diff=abs(nums[j] +nums[i]- 330);
            }
        }
    }
    
    return nearSum; //return updated nearSum when loop is completed.
}

int main()
{
    int nums[4]= {10, 100, 200, 2};
    int length=4;
    int sum=Sum(nums,length);
    
    cout<<sum<<endl;
    
    return 0;
}

