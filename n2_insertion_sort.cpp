#include<iostream>
#include<time.h>
using namespace std;
//INSERTION
void display(int n, int a[]){
    for (int i = 0; i < n; i++){
        cout<<a[i]<<" ";}
    cout<<endl;
}
void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
void insertion_sort(int n,int a[])  {  
    int i, j, temp;  
    for (i = 1; i < n; i++) {  
        temp = a[i];  
        j = i - 1;  
        while(j>=0 && temp <= a[j]){    
            a[j+1] = a[j];     
            j = j-1;    }    
        a[j+1] = temp;    
    }  
} 
int main(){
    int *a; int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        a[i]=rand()%100 ;
    cout<<"Before sorting array is: ";
    display(n,a);
    clock_t start = clock();
    insertion_sort(n,a);
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<"After sorting array is: ";
    display(n,a);
    cout<<"Time is: "<<elapsed;
    return 0;
}
