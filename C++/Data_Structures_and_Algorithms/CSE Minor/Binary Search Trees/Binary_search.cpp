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
		bool Binarysearch(int key){
			if(data==key){
				return true;
			}
			else if(key<data){
				if(children[0]!=nullptr){
					return children[0]->Binarysearch(key);
				}
			}
			else{
				if(children[1]!=nullptr){
					return children[1]->Binarysearch(key);
				}
			}
			return false;
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
	root.display();//Displayed the tree
	
	//Binary Searching the tree
	int m;
	char nconsent;
	do{
		nconsent='n';
		cout<<"Enter the number to be searched"<<endl;
		cin>>m;
		if(root.Binarysearch(m)==true){
		cout<<"The element has been found!"<<endl;
	}
	else{
		cout<<"The element has not been found!"<<endl;
	}
	cout<<"Do you want to find another element?"<<endl;
	cin>>nconsent;
	}while(nconsent=='y');
	
	return 0;
}
