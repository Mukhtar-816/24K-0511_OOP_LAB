#include <iostream>
#include <cstdlib>
using namespace std;

void* addtoelement(void* arr,int size){
    int* arr1=(int*)arr;
    for(int i = 0; i<size; i++){
        arr1[i] = arr1[i] + 4; 
    }
    return (void*)arr1;
}


int main(int argc,char* argv[])
{
    if(argc<2){
        cout<<"Enter the value for the array size.....";
        return 0;
    }
    int size = argc - 1,num;
    int arr1[size];
    for(int i = 1; i<size+1 ;i++){
        arr1[i-1] = atoi(argv[i]);
    }
    (int*)addtoelement((void*)arr1,size);
    for(int i = 0; i<size;i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}