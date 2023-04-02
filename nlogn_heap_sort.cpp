#include<iostream>
#include<time.h>
using namespace std;
//HEAP SORT
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
void heap_sort(int n,int a[]){
    int temp,temp2;
    int i,j,k;
    k=n-1;
    while(k>0){
        for(i=k;i>0;i--){
            j=i;
            while(j>0){
                if(a[(j-1)/2]<a[j]){
                    swap(&a[j],&a[(j-1)/2]);
                    j=(j-1)/2;}
                else{break;}
            }
        }
        swap(&a[0],&a[k]);
        k--;
    }
    return;
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
    heap_sort(n,a);
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<"After sorting array is: ";
    display(n,a);
    cout<<"Time is: "<<elapsed;
    return 0;
}
