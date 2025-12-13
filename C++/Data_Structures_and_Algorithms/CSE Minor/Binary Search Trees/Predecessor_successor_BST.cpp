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
		int getValue(){
			return data;
		}
		void prearr_store(int prearr[],int &preind){
			//preorder traversal: root left right
			prearr[preind++]=data;//store root
			if(children[0]!=nullptr){
				children[0]->prearr_store(prearr,preind);
			}//store all left
			if(children[1]!=nullptr){
				children[1]->prearr_store(prearr,preind);
			}//store all right
		}
		void prearr_search(int prearr[],int key,int& predecessor,int& successor,int& preind){
			for(int i=0;i<preind;i++){
				if(prearr[i]==key){
					if(i==0){
						successor=prearr[i+1];
						cout<<"The successor is "<<successor<<endl;
						cout<<"Predecessor Does not exist"<<endl;
					}
					else if(i==preind-1){
						predecessor=prearr[i-1];
						cout<<"Successor Does not exist"<<endl;
						cout<<"The predecessor is "<<predecessor<<endl;
					}
					else{
						predecessor=prearr[i-1];
						successor=prearr[i+1];
						cout<<"The successor is "<<successor<<endl;
						cout<<"The predecessor is "<<predecessor<<endl;
					}
				}
			}
		}
		void inarr_store(int inarr[],int &inind){
			//inorder traversal: left root right
			if(children[0]!=nullptr){
				children[0]->inarr_store(inarr,inind);
			}//store all left
			inarr[inind++]=data;//store root
			if(children[1]!=nullptr){
				children[1]->inarr_store(inarr,inind);
			}//store all right
		}
		void inarr_search(int inarr[],int key,int& predecessor,int& successor,int& inind){
			for(int i=0;i<inind;i++){
				if(inarr[i]==key){
					if(i==0){
						successor=inarr[i+1];
						cout<<"The successor is "<<successor<<endl;
						cout<<"Predecessor Does not exist"<<endl;
					}
					else if(i==inind-1){
						predecessor=inarr[i-1];
						cout<<"Successor Does not exist"<<endl;
						cout<<"The predecessor is "<<predecessor<<endl;
					}
					else{
						predecessor=inarr[i-1];
						successor=inarr[i+1];
						cout<<"The successor is "<<successor<<endl;
						cout<<"The predecessor is "<<predecessor<<endl;
					}
				}
			}
		}
		void postarr_store(int postarr[],int &postind){
			//inorder traversal: left root right
			if(children[0]!=nullptr){
				children[0]->postarr_store(postarr,postind);
			}//store all left
			if(children[1]!=nullptr){
				children[1]->postarr_store(postarr,postind);
			}//store all right
			postarr[postind++]=data;//store root
		}
		void postarr_search(int postarr[],int key,int& predecessor,int& successor,int& postind){
			for(int i=0;i<postind;i++){
				if(postarr[i]==key){
					if(i==0){
						successor=postarr[i+1];
						cout<<"The successor is "<<successor<<endl;
						cout<<"Predecessor Does not exist"<<endl;
					}
					else if(i==postind-1){
						predecessor=postarr[i-1];
						cout<<"Successor Does not exist"<<endl;
						cout<<"The predecessor is "<<predecessor<<endl;
					}
					else{
						predecessor=postarr[i-1];
						successor=postarr[i+1];
						cout<<"The successor is "<<successor<<endl;
						cout<<"The predecessor is "<<predecessor<<endl;
					}
				}
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
	int prearr[1000],inarr[1000],postarr[1000];
	int preind=0,inind=0,postind=0;
	int predecessor,successor;
	cout<<"Finding Predecessor and successor"<<endl;
	int key;
	cout<<"Enter the key"<<endl;
	cin>>key;
	cout<<"Preorder analysis:"<<endl;
	root.prearr_store(prearr,preind);
	root.prearr_search(prearr,key,predecessor,successor,preind);
	cout<<"Inorder analysis:"<<endl;
	root.inarr_store(inarr,inind);
	root.inarr_search(inarr,key,predecessor,successor,inind);
	cout<<"Postorder analysis:"<<endl;
	root.postarr_store(postarr,postind);
	root.postarr_search(postarr,key,predecessor,successor,postind);
	return 0;
}
