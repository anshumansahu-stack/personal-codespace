#include<iostream>
using namespace std;
int max(int a,int b){
	if(a>=b){
		return a;
	}
	else{
		return b;
	}
}
class TreeNode{
	int data,height;
	TreeNode* children[2];
	public:
		TreeNode(int value){
			data=value;
			height=1;
			children[1]=nullptr;
			children[0]=nullptr;
		}
		void getHeight(TreeNode* node){
			if(node==nullptr){
				return 0;
			}
			return height;
		}
		void getBalancefactor(TreeNode* node){
			if(node==nullptr){
				return 0;
			}
			return getHeight(node->children[0])-getHeight(node->children[1]);
		}
		TreeNode* rotateLeft(TreeNode* y){
			TreeNode* x=y->children[1];
			TreeNode* Temp=x->children[0];
			
			x->children[0]=y;
			y->children[1]=temp;
			
			y->height=max(getHeight(y->children[0]),getHeight(y->children[1]))+1;
			x->height=max(getHeight(x->children[0]),getHeight(x->children[1]))+1;
			
			return x;
		}
		
		TreeNode* rotateRight(TreeNode* y){
			TreeNode* x=y->children[0];
			TreeNode* Temp=x->children[1];
			
			x->children[1]=y;
			y->children[0]=temp;
			
			y->height=max(getHeight(y->children[0]),getHeight(y->children[1]))+1;
			x->height=max(getHeight(x->children[0]),getHeight(x->children[1]))+1;
			
			return x;
		}
		
		TreeNode* insert(TreeNode* Node,int key){
			if(node==nullptr){
				return new TreeNode(key);
			}
			if(key<node->data){
				node->children[0]=insert(node->children[0];key;)
			}
			else if(key>node->data){
				node->children[1]=insert(node->children[1];key;)
			}
			else{
				cout<<"BST Does not have identical values!"<<endl;
				return node;
			}
			
			node->height=max(getHeight(node->children[0],node->children[1]))+1;
			
			int balancefactor=getHeight(node->children[0])-getHeight(node->children[1]);
			
			//Rotations:
			//LeftLeft:
			if(balancefactor>1 && key<node->value){
				return rotateRight(node);
			}
			//rightright
			if(balancefactor<1 && key>node->value){
				return rotateLeft(node);
			}
//			LeftRight
			if(balancefactor>1 && key>node->value){
				node->children[0]=rotateLeft(node->children[0]);
				return rotateRight(node);
			}
//			rightleft
			if(balancefactor<1 && key<node->value){
				node->children[1]=rotateRight(node->children[1]);
				return rotateLeft(node);
			}
			return node;
		}
		void inorder(TreeNode* root){
        if (root != nullptr) {
            inorder(root->children[0]);
            cout << root->data << " ";
            inorder(root->children[1]);
        }
    }
    int main(){
    	TreeNode* root=nullptr;
    	char consent='n';
    	
    	do{
    		cout<<"Do you want to insert a number?"<<endl;
    		cin>>consent;
    		int number;
    		cout<<
		}
	}
};
