#include<iostream>
#include<vector>
using namespace std;


void merge(int arr1[], int n, int arr2[], int m ,int arr3[]){

    int i = 0; //i is index of first array
    int j = 0; //j is index of second array 
    int k = 0; // k is index of third array

    while (i< n && j< m ){

        if(arr1[i]< arr2[j]){
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else{ //arr1 < arr2

            arr3[k] = arr2[j];
            k++;
            j++;
        }

    }

    //copy first array k element ko 
    while(i< n ){
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    //copy second array k element ko 
    while(j < m ){
        arr3[k]= arr1[i];
        k++;
        j++;
    }

}

void print(int ans[], int n){
    for(int i = 0 ; i < n ; i++)
    {
        cout<< ans [ i ]<< " ";

    }
    cout<<endl;

}

int main()
{
    int arr1[5] = {1,3,5,7,9};
    int arr2[3] = {2,4,6};

    int arr3[8] = {0};

    merge(arr1, 5 , arr2 , 3, arr3);
    
    cout<<"MERGED ARRAY IS : ";
    
    print(arr3, 8); 
    
    return 0;
}