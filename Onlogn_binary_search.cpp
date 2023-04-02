#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;
int mid,key;
int bi_s(int a[],int beg,int end,int mid,int el){
    if(a[mid] == el){
        cout<<"Element found at position "<<mid+1<<"\n";
        return mid+1;}
    else if(beg > end){
        cout<<"Element Not found\n";
        return 0;}
    else{
        mid=(beg+end)/2;
        if(a[mid]>el){return bi_s(a,beg,mid-1,mid,el);}
        else{return bi_s(a,mid+1,end,mid,el);}
    }
}
void sort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main(){
    int *a;
    int n;
    cout<<"Enter the size of array: "; cin>>n;
    a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        a[i]=rand()%n ;
    sort(a,a+n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout << "\nEnter the element to search: ";
    cin >> key;
    int beg = 0;
    int en = n-1;
    mid = (beg + en) / 2;
    clock_t start = clock();
    bi_s(a,beg,en,mid,key);
    clock_t ends = clock();
    double elapsed = double(ends - start)/CLOCKS_PER_SEC;
    cout<<"Time is: "<<elapsed;
    return 0;
}
