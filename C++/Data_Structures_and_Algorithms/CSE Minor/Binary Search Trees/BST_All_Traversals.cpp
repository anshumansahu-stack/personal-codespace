#include<iostream>
using namespace std;
class TreeNode{
	int data;
	TreeNode* children[2];
	public:
		TreeNode(int value){
			data=value;
			for(int i=0;i<2;i++){
				children[i]=nullptr;
			}
		}
		void insert(int key){
			if(key<data){
				if(children[0]==nullptr){
					children[0]=new TreeNode(key);
				}
				else{
					children[0]->insert(key);
				}
			}
			else if(key >data){
				if(children[1]==nullptr){
					children[1]=new TreeNode(key);
				}
				else{
					children[1]->insert(key);
				}
			}
			else{
				cout<<"ERROR: A binary search Tree cannot have identical values!"<<endl;
			}
		}
		void preorder_display(){
			//preorder traversal
			cout<<data<<" ";//Print root
			if(children[0]!=nullptr){
				children[0]->preorder_display();
			}//Print all left
			if(children[1]!=nullptr){
				children[1]->preorder_display();
			}//Print all right
		}
		void inorder_display(){
			//inorder traversal
			if(children[0]!=nullptr){
				children[0]->inorder_display();
			}//Print all left
			cout<<data<<" ";//Print root
			if(children[1]!=nullptr){
				children[1]->inorder_display();
			}//Print all right
		}
		void postorder_display(){
			//postorder traversal
			if(children[0]!=nullptr){
				children[0]->postorder_display();
			}//Print all left
			if(children[1]!=nullptr){
				children[1]->postorder_display();
			}//Print all right
			cout<<data<<" ";//Print root
		}
};
int main(){
	int n;
	cout<<"Enter the root of the tree"<<endl;
	cin>>n;
	TreeNode root(n);
	char consent ='n';
	do{
		cout<<"Do you want to insert another Number?"<<endl;
		cin>>consent;
		if(consent=='y'){
			int key;
			cout<<"Enter a number:";
			cin>>key;
			root.insert(key);
		}
	}while(consent=='y');
	cout<<"Preorder Display:"<<endl;
	root.preorder_display();
	cout<<endl;
	cout<<"Inorder Display:"<<endl;
	root.inorder_display();
	cout<<endl;
	cout<<"Postorder Display"<<endl;
	root.postorder_display();
	cout<<endl;
	return 0;
}
