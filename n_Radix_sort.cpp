#include<iostream>
#include<time.h>
using namespace std;
//RADIX SORT
void display(int n, int a[]){
    for (int i = 0; i < n; i++){
        cout<<a[i]<<" ";}
    cout<<endl;
}
void count_sort(int a[],int n,int pos){
    // cout<<"\n"<<pos<<"\n";
    int *b=(int *)malloc(n*sizeof(int));
    int k=10;
    int *c=(int *)malloc((k)*sizeof(int));
    for(int i=0;i<k;i++)
        c[i]=0;
    for(int j=0;j<n;j++)
        c[(a[j]/pos)%10]++;
    // display(k,c);
    for(int i=1;i<k;i++)
        c[i]+=c[i-1];
    // display(k,c);
    for(int j=n-1;j>=0;j--){
        b[c[(a[j]/pos)%10]-1]=a[j];
        c[(a[j]/pos)%10]--;}
    // display(n,b);
    for(int i=0;i<n;i++)
        a[i]=b[i];
    // display(n,a);
    // cout<<"\n\n";
}
void radix_sort(int n,int a[]){
    int max=a[n-1];
    for(int i=0;i<n;i++){
        if(a[i]>max)
            max=a[i];
    }
    for(int pos=1;(max/pos)>0;pos*=10)
        count_sort(a,n,pos);
}
int main(){
    int *a; int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        a[i]=rand()%n;
    cout<<"Before sorting array is: ";
    display(n,a);
    clock_t start = clock();
    radix_sort(n,a);
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<"After sorting array is: ";
    display(n,a);
    cout<<"Time is: "<<elapsed;
    return 0;
}
