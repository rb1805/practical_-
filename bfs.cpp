//bfs
#include<omp.h>
#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int> a[],int n,int source,vector<int> &visited){
	queue<int> q;
	q.push(source);
	visited[source]=true;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		cout<<top<<"==> ";
		for(auto neighbour:a[top]){
			if(!visited[neighbour]){
				q.push(neighbour);
				visited[neighbour]=true;
			}
		}
	}
	return;


}
int main(){
	int n;
	char ch;
	cout<<"Enter the total nodes in the graph"<<endl;
	cin>>n;
	vector<int> arr[n];
	cout<<"do you want to add more edges"<<endl;
		cout<<"enter y to add other to exit"<<endl;
		
		cin>>ch;
	while(ch=='y'){
		
		cout<<"eneter the pair of nodes"<<endl;
		int u,v;
		cin>>u>>v;
		arr[u].push_back(v);
		cout<<"do you want to add more edges"<<endl;
		cout<<"enter y to add other to exit"<<endl;
		
		cin>>ch;
	}
	vector<int> visited(n,0);
	bfs(arr,n,0,visited);
	return 0;
}
