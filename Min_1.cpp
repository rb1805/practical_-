#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
int minimum(vector<int>&v)
{
int temp=INT_MAX;
#pragma omp parallel

for(int i=0;i<v.size();i++)
{
int tno=omp_get_thread_num();
cout<<i <<"runs on "<<tno<<endl;
if(temp>v[i])
{
temp=v[i];
}
}
return temp;
}
int maximum(vector<int>&v)
{
int temp=INT_MIN;
#pragma omp parallel
for(int i=0;i<v.size();i++)
{
if(temp<v[i])
{
temp=v[i];
}
}
return temp;
}

int sum(vector<int>&v)

{
int summ=0;
for(int i=0;i<v.size();i++)
{
summ=summ+v[i];
}
return summ;
}
int average(vector<int>&v)
{
int suma=0;
for(int i=0;i<v.size();i++)
{
suma=suma+v[i];
}
double avg=suma/v.size();
return avg;
}
int main()
{
int size;
cout<<"ENter size of array"<<endl;
cin>>size;
vector<int>v(size);
for(int i=0;i<size;i++)
{
cin>>v[i];
}
cout<<"min ele is "<<endl;
cout<<minimum(v);
cout<<endl;
cout<<"max ele is  "<<endl;
cout<<maximum(v);
cout<<endl;
cout<<"sum is  "<<endl;
cout<<sum(v);
cout<<"average is  "<<endl;
cout<<average(v);
cout<<endl;
return 0;
}
