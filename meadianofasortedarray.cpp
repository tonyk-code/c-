/********************************************************************************
-This question is a leeet code problem.https://leetcode.com/problems/median-of-two-sorted-arrays/description/ 
-The question is: 
    Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
-Down below is the solution to the answer
*********************************************************************************/


#include <iostream>
#include <vector>


using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //Declare a variable for storing both the vectors into one vector 
    vector<int> merged_array;

    //Get the size of each vectors
    int sizenums1=nums1.size();
    int sizenums2=nums2.size();

    //Add the two size and assign it to sum
    int sum=sizenums1+sizenums2;

    //push back the elements of the two vectors into the merged_array vector
    for(int i=0;i<sizenums1;i++){
       merged_array.push_back(nums1[i]) ; 
    }
    for(int i=0;i<sizenums2;i++){
        merged_array.push_back(nums2[i]); 
    }

    //Sort the vector in increasing order
    for(int i=0;i<sum;i++){
        for(int j=0;j<sum;j++){
            if(merged_array[j]>merged_array[j+1]){
                int temp=merged_array[j];
                merged_array[j]=merged_array[j+1];
                merged_array[j+1]=temp;
            }
        }

    }

    //If the elements are even find the median of the elements and divide by two
    if(merged_array.size()%2==0){
        int element=(merged_array.size()/2);
        float median=(merged_array[element]+merged_array[element-1]);
        cout<<"median is = "<<median/2;
    }

    //If odd just display the middle one of the whole elements
    else{
        int element=(merged_array.size()/2);
        cout<<"median is = "<<merged_array[element];
    }
    
    return 0;
    
}

int main(){
    vector<int> num1={1,3,5,7};
    vector<int> num2={2,4,6,8};
    findMedianSortedArrays(num1,num2);

    
    return 0;
}