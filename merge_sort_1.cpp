#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

void merge(vector<int>&v,int s,int mid,int e)
{
vector<int>temp;
int l=s;
int r=mid+1;
while(l<=mid&&r<=e)
{
if(v[l]<v[r])
{
temp.push_back(v[l]);
l++;
}
else
{
temp.push_back(v[r]);
r++;
}
}

while(l<=mid)
{
temp.push_back(v[l]);
l++;
}

while(r<=e)
{
temp.push_back(v[r]);
r++;
}


for(int i=0;i<temp.size();i++)
{
v[s]=temp[i];
s++;
}
return ;
}
void mergesort(vector<int>&v,int s,int e)
{
int mid=(s+e)/2;
if(s<e)
{
mergesort(v,s,mid);
mergesort(v,mid+1,e);
merge(v,s,mid,e);
}
return;

}
int main()
{
vector<int>v{2,5,1,7,4};
mergesort(v,0,v.size()-1);
for(auto it:v)
{
cout<<it<<"  ";
}
return 0;
}
