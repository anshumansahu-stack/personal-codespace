#include<iostream>
using namespace std;
const int Max_children=3;
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

int main(){
	//Creating Nodes
	TreeNode root(1);
	TreeNode child1(2);
	TreeNode child2(3);
	TreeNode child3(4);
	TreeNode grandchild1(5);
	TreeNode grandchild2(6);
	TreeNode grandchild3(7);
	
	//Attaching the nodes
	root.Addchild(&child1,0);
	root.Addchild(&child2,1);
	root.Addchild(&child3,2);
	child1.Addchild(&grandchild1,0);
	child2.Addchild(&grandchild2,0);
	child3.Addchild(&grandchild3,0);
	
	//Printing the tree
	root.display();
	return 0;
}
