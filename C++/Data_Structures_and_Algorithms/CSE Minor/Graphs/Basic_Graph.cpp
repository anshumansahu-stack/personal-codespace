#include<iostream>
using namespace std;
class graph{
	private:
		int max_vertices;
		int adjacency_matrix[20][20];
		int value_array[20];
	public:
		graph(int n){
			max_vertices=n;
			for(int i=0;i<max_vertices;i++){
				for(int j=0;j<max_vertices;j++){
					adjacency_matrix[i][j]=0;
				}
			}
		}
		void getvalues(){
			cout<<"Enter the corresponding values of "<<max_vertices<<" vertices"<<endl;
			for(int i=0;i<max_vertices;i++){
				cin>>value_array[i];
			}
		}
		void addedge(int start,int end){
			adjacency_matrix[start][end]=1;
			adjacency_matrix[end][start]=1;
		}
		void printadjacencymatrix(){
			cout<<endl;
			cout<<"\t";
			for(int i=0;i<max_vertices;i++){
				cout<<value_array[i]<<" ";
			}
			cout<<endl;
			for(int i=0;i<max_vertices;i++){
				cout<<value_array[i]<<" ";
				for(int j=0;j<max_vertices;j++){
					cout<<adjacency_matrix[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		bool linearsearch(int key,int& index){
		for(int i=0;i<max_vertices;i++){
				if(value_array[i]==key){
					index=i;
					return true;
				}
	}
	return false;
}
};
int main(){
	int n;
	cout<<"Enter the number of vertices"<<endl;
	cin>>n;
	graph g(n);//graph of n vertices created
	g.getvalues();
	//code for adding edges
	char consent='n';
	do{
		cout<<"do you want to add an edge? "<<endl;
		cin>>consent;
		if(consent=='y'){//y=yes
			int key,index;
			cout<<"Enter the value of the start vertex:";
			cin>>key;
			if(g.linearsearch(key,index)==false){
				cout<<"Key not found!"<<endl;
				continue;
			}
			int start=index;
			cout<<"Enter the value of the end vertex:";
			cin>>key;
			if(g.linearsearch(key,index)==false){
				cout<<"Key not found!"<<endl;
				continue;
			}
			int end=index;
			g.addedge(start,end);
			
		}
	}while(consent=='y');
	cout<<endl<<"The required adjacency matrix is: "<<endl;
	g.printadjacencymatrix();
	return 0;
}
