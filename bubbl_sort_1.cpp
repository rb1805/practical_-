#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
int main()
{
int size;
cout<<"ENter array size"<<endl;
cin>>size;
int arr[size];
cout<<"Enter Array elements"<<endl;
for(int i=0;i<size;i++)
{
cin>>arr[i];
}
for(int i=0;i<size;i++)
{
cout<<arr[i]<<"  ";
}
cout<<endl<<"after sortimg"<<endl;

#pragma omp parallel
for(int i=0;i<size;i++)
{
int tno=omp_get_thread_num();
cout<<i <<" is running on "<<tno<<endl;

for(int j=0;j<size-i-1;j++)
{
if(arr[j]>arr[j+1])
{
swap(arr[j],arr[j+1]);
}
}
}
for(int i=0;i<size;i++)
{
cout<<arr[i]<<"  ";
}
return 0;
}
