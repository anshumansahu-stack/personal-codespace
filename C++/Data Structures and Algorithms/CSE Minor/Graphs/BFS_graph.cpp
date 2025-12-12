#include<iostream>
#include<climits>
using namespace std;
class queue{
	private:
		int arr[100];
		int front,rear,maxsize;
	public:
		queue(){
		}
		queue(int n){
			maxsize=n;
			front=0;
			rear=0;
		}
		int size(){
			return rear-front;
		}
		void enqueue(int n){//Inserting at the rear
			if(size()>=maxsize){
				cout<<"Enqueue Unsuccessful: Queue is already full!"<<endl;
				return;
			}
			arr[rear++]=n;
		}
		int dequeue(){
			if(size()<=0){
				cout<<"Dequeue Unsuccessful: Queue is already empty!"<<endl;
				return INT_MIN;
			}
			return arr[front++];
		}
		int Front(){
			if(size()<=0){
				cout<<"Front Unsuccessful: Queue is already empty!"<<endl;
				return INT_MIN;
			}
			return arr[front];
		}
		int Rear(){
			if(size()<=0){
				cout<<"Rear Unsuccessful: Queue is already empty!"<<endl;
				return INT_MIN;
			}
			return arr[rear-1];
		}
		int linearsearch(int key){
			for(int i=front;i<=rear;i++){
				if(arr[i]==key){
					return i;
				}
			}
			return -1;//error detection
		}
		bool isFull(){
			if(size()>=maxsize){
				return true;
			}
			return false;
		}
		bool isEmpty(){
			if(size()<=0){
				return true;
			}
			return false;
		}
};
class graph{
	private:
		int maxnode, adjacency_matrix[100][100], value_array[100], dynamic_storage[100], dynamic_index;
		queue visited_queue;//pointer declaration to the queue
	public:
		graph(int n): visited_queue(100){//initialiser list
			maxnode=n;
			for(int i=0;i<maxnode;i++){//row fix
				for(int j=0;j<maxnode;j++){//column fix
					adjacency_matrix[i][j]=0;
				}
			}
			for(int i=0;i<maxnode;i++){
				value_array[i]=0;
			}
			dynamic_index=0;
		}
		void getvalues(){
			cout<<"Enter the values of "<<maxnode<<" nodes:"<<endl;
			for(int i=0;i<maxnode;i++){
				cin>>value_array[i];	
			}
		}
		int linearsearch_value(int key){
			for(int i=0;i<maxnode;i++){
				if(value_array[i]==key){
					return i;
				}
			}
			return -1;//error detection
		}
		int linearsearch_dynamic(int key){
			for(int i=0;i<dynamic_index;i++){
				if(dynamic_storage[i]==key){
					return i;
				}
			}
			return -1;//error detection
		}
		void addedge(int startindex,int endindex){//Provide arguments using linearsearch function
			adjacency_matrix[startindex][endindex]=1;
			adjacency_matrix[endindex][startindex]=1;
		}
		void BFS(int node){
			if(linearsearch_dynamic(node)!=-1){
				return;//return if the element is in visited 
			}
			dynamic_storage[dynamic_index++]=node;
			visited_queue.enqueue(node);
			for(int i=linearsearch_value(node),j=0;j<maxnode;j++){
				if(adjacency_matrix[i][j]>0){
					dynamic_storage[dynamic_index++]=value_array[j];
					visited_queue.enqueue(value_array[j]);
				}
			}
			visited_queue.dequeue();
			for(int i=linearsearch_value(node),j=0;j<maxnode;j++){
				if(adjacency_matrix[i][j]>0){
					BFS(value_array[j]);
				}
			}
			if(visited_queue.isEmpty()==true){
				return;// return if the queue is empty
			}
		}
		void printadjacencymatrix(){
			cout<<endl;
			cout<<"\t";
			for(int i=0;i<maxnode;i++){
				cout<<value_array[i]<<" ";
			}
			cout<<endl;
			for(int i=0;i<maxnode;i++){
				cout<<value_array[i]<<" ";
				for(int j=0;j<maxnode;j++){
					cout<<adjacency_matrix[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		void printdynamicstorage(){
			for(int i=0;i<dynamic_index;i++){
				cout<<dynamic_storage[i];
			}
		}
};
int main(){
	int n;
	cout<<"Enter the number of nodes in the graph"<<endl;
	cin>>n;
	graph g(n);
	g.getvalues();//node values added
	char consent='n';
	do{
		cout<<"Do you want to add an edge?"<<endl;
		cin>>consent;
		if(consent=='y'){
			int start,end;
			cout<<"Enter the value of node to start"<<endl;
			cin>>start;
			cout<<"Enter the value of edge to end"<<endl;
			cin>>end;
			g.addedge(g.linearsearch_value(start),g.linearsearch_value(end));
		}
	}while(consent=='y');//edges added
	//BFS
	int m;
	cout<<"Enter the node to start BFS from:";
	cin>>m;
	g.BFS(m);
	cout<<endl;
	cout<<"The corresponding adjacency matrix is:"<<endl;
	g.printadjacencymatrix();
	cout<<endl;
	cout<<"The corresponding BFS array is:"<<endl;
	g.printdynamicstorage();
	return 0;
}
//void BFS(int startNode) {
//    if (linearsearch_dynamic(startNode) != -1) {
//        return; // If the start node is already visited, exit
//    }
//    
//    visited_queue.enqueue(startNode); // Start BFS from the node
//    while (!visited_queue.isEmpty()) {
//        int currentNode = visited_queue.dequeue();
//        
//        // If currentNode is already visited, skip
//        if (linearsearch_dynamic(currentNode) != -1) {
//            continue;
//        }
//        
//        // Mark currentNode as visited
//        dynamic_storage[dynamic_index++] = currentNode;
//        
//        // Enqueue all unvisited neighbors of currentNode
//        int nodeIndex = linearsearch_value(currentNode);
//        for (int j = 0; j < maxnode; j++) {
//            if (adjacency_matrix[nodeIndex][j] > 0 && linearsearch_dynamic(value_array[j]) == -1) {
//                visited_queue.enqueue(value_array[j]);
//            }
//        }
//    }
//}

