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
		void find_max_min(int& maximum,int& minimum){
			//preorder traversal
			if(data>maximum){
				maximum=data;
			}
			if(data<minimum){
				minimum=data;
			}
			if(children[0]!=nullptr){
				children[0]->find_max_min(maximum,minimum);
			}
			if(children[1]!=nullptr){
				children[1]->find_max_min(maximum,minimum);
			}
		}
		int getdata(){
			return data;
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
	int maximum=root.getdata(),minimum=root.getdata();
	root.find_max_min(maximum,minimum);
	cout<<"The maximum value in the tree is "<<maximum<<endl;
	cout<<"The minimum value in the tree is "<<minimum<<endl;
	
	return 0;
}
