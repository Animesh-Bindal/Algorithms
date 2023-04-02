#include<iostream>
#include<time.h>
using namespace std;
int li_s(int a[],int item,int n){
    for(int i=0;i<n;i++)
        if(a[i]==item)
            return i+1;
    return -1;
}
int main(){
    int *a;
    int n,key;
    cout<<"Enter the size of array: ";
    cin>>n;
    a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        a[i]=rand()%n ;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\nEnter the element to search: "; cin>>key;
    clock_t start = clock();
    int r=li_s(a,key,1000);
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    (r==-1)?cout<<"Element not found \n": cout<<"Element found at position "<<r<<"\n";
    cout<<"Time is: "<<elapsed;
    return 0;
}