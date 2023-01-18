#include <bits/stdc++.h>

int getPivot(vector<int>& arr, int n ){

    int s= 0;
    int e = n-1;
    int mid = s+ ( e-s )/2 ;

    while(s<e){
        if(arr[mid] >= arr[0] ) //here 0 is index 
        {
            s = mid + 1 ; 
        }
        else 
        {
            // if we dow mid - 1 then it will go to another line 
            e = mid;
        }
        mid = s+ ( e-s )/2 ;
    }
    return s; 
}
int binarysearch(vector<int>& arr, int s, int e, int key) 
{
    
    int start = s;
    int end = e;

    // int mid = (start + end )/2 ; 
    // agar yeh integer ki range se bahar na nikle islie pahle hi start ko hatadia aur add krlia 
    int mid = ( start + (end- start/2));
    

    while(start<=end) {

        if(arr[mid] == key){
            return mid;
        }
        if(key> arr[mid]){
            start = mid+1;
        }
        else{
            end = mid - 1;
        }

        // mid = ( start + end )/2;
        int mid = ( start + (end- start/2));

    }
    return -1;
}

int findPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int pivot = getPivot(arr , n);
    if( k >= arr[pivot] && k<= arr[n-1] ) 
    {
        return binarysearch(arr , pivot , n-1 , k);
    }
    else 
    {
        return binarysearch(arr, 0 , pivot -1 , k);
    }
}