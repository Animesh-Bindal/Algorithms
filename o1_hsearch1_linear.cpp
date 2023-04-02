#include<iostream>
#include<time.h>
using namespace std;
//LINEAR PROBE
void insert_hashtable(int a[],int n,int loc,int data){
    int i=0;
    int ptr=loc;
    if(a[loc]==-1){a[loc]=data;}
    else{
        i++;
        while(a[ptr]!=-1 && i<n){
            ptr=(loc+i)%n;
            i++;}
        a[ptr]=data;}
}
int direct_search(int a[],int n,int data){
    int ptr=data%n;
    int i=0;
    if(a[ptr]==data){return ptr;}
    else{
        i++;
        while(i<n){
            if(a[(ptr+i)%n]==data)
                return (ptr+i)%n;
            else
                i++;}}
    return -1;
}

int main()
{
    int *a;
    int data,loc;
    int n,key,pos;
    cout<<"Enter the size of array: ";
    cin>>n;
    a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        a[i]=-1;
    cout<<"Data items are: ";
    for(int i=0;i<n;i++){
        data=rand()%n;
        cout<<data<<" ";
        loc=data%n;
        insert_hashtable(a,n,loc,data);}
    cout<<endl;
    cout<<"Hash table: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\nEnter an element to be searched between 1 to "<<n<<": ";
    cin>>key;
    clock_t start = clock();
    pos=direct_search(a,n,key);
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    if(pos==-1){cout<<"Element not found"<<endl;}
    else{cout<<"Element found at position "<<pos+1<<endl;}
    cout<<"Time is: "<<elapsed;
    return 0;
}