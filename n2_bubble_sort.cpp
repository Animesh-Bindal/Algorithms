#include<iostream>
#include<time.h>
using namespace std;
//BUBBLE
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
void bubble_sort(int n,int a[]){
    bool flag;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                flag=true;}
        }
        if(flag==false){break;}
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
    bubble_sort(n,a);
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<"After sorting array is: ";
    display(n,a);
    cout<<"Time is: "<<elapsed;
    return 0;
}
