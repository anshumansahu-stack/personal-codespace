#include<iostream>
using namespace std;
const int Max_children=2;
class TreeNode{
	int data;
	TreeNode* children[Max_children];
	public:
		TreeNode(int value){
			data=value;
			for(int i=0;i<Max_children;i++){
				children[i]=nullptr;
			}
		}
		void Addchild(TreeNode* child,int index){
			if(index>=0 && index<Max_children){
				children[index]=child;
			}
			else{
				cout<<"Index out of bounds!!"<<endl;
			}
		}
		void display(){//preorder traversal
			cout<<data<<" ";
			for(int i=0;i<Max_children;i++){
				if(children[i]!=nullptr){
					children[i]->display();
				}
			}
		}
};
void AddNode(TreeNode* child1,int index){
	char nconsent='n';
	cout<<"Any element in the Left Subtree? press y for yes, other for no."<<endl;
	cin>>nconsent;
	if(nconsent=='y'){
		int value;
		cout<<"Enter the value of the node"<<endl;
		cin>>value;
		TreeNode* child2=new TreeNode(value);
		child1->Addchild(child2,0);
		AddNode(child2,0);
	}
	nconsent='n';
	cout<<"Any element in the Right Subtree? press y for yes, other for no."<<endl;
	cin>>nconsent;
	if(nconsent=='y'){
		int value;
		cout<<"Enter the value of the node"<<endl;
		cin>>value;
		TreeNode* child2=new TreeNode(value);
		child1->Addchild(child2,1);//Dereferencing child1
		AddNode(child2,1);
	}
	
}
int main(){
	int n;
	cout<<"Add the root of the Binary Search tree:"<<endl;
	cin>>n;
	TreeNode root(n);
	char consent='n';
	cout<<"Any element in the Left Subtree? press y for yes, other for no."<<endl;
	cin>>consent;
	if(consent=='y'){
		int value;
		cout<<"Enter the value of the node"<<endl;
		cin>>value;
		TreeNode* child1=new TreeNode(value);
		root.Addchild(child1,0);
		AddNode(child1,0);
	}
	consent='n';
	cout<<"Any element in the Right Subtree? press y for yes, other for no."<<endl;
	cin>>consent;
	if(consent=='y'){
		int value;
		cout<<"Enter the value of the node"<<endl;
		cin>>value;
		TreeNode* child1=new TreeNode(value);
		root.Addchild(child1,1);
		AddNode(child1,1);
	}
	root.display();
	return 0;
}
