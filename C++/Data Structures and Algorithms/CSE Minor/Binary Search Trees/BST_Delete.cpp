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
		TreeNode* findMin(){
			TreeNode* current=this;
			while(current && current->children[0]!=nullptr){
				current=current->children[0];
			}
			return current;
		}
		TreeNode* DeleteNode(TreeNode* root, int key){
			if(root==nullptr){
				return root;//Node Not found
			}
			
			//Finding the key
			if(key<root->data){
				root->children[0]->DeleteNode(children[0],key);
			}//left search
			else if(key>root->data){
				root->children[1]->DeleteNode(children[1],key);
			}//right search
			else{
				//key found
				//case 1: no children
				if(root->children[0]==nullptr && root->children[1]==nullptr){
					delete root;
					return nullptr;
				}
				//case 2: one children
				else if(root->children[0]==nullptr){
					TreeNode* temp=root->children[1];
					delete root;
					return temp;
				}
				else if(root->children[1]==nullptr){
					TreeNode* temp=root->children[0];
					delete root;
					return temp;
				}
				//case 3: both children
				else{
					TreeNode* temp=root->children[1]->findMin();
					root->data=temp->data;
					root->children[1]=DeleteNode(root->children[1],temp->data);
				}
			}
			return root;
		}
		void display(){
			//preorder traversal
			cout<<data<<" ";
			if(children[0]!=nullptr){
				children[0]->display();
			}
			if(children[1]!=nullptr){
				children[1]->display();
			}
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
	root.display();
	int delnum;
	cout<<endl<<"Enter the number to be deleted:"<<endl;
	cin>>delnum;
	root.DeleteNode(&root,delnum);
	root.display();
	return 0;
}
