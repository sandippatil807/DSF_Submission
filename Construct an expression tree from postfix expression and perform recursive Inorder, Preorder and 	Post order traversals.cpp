 /*	Problem statement :Construct an expression tree from postfix expression and perform recursive Inorder, Preorder and
	Post order traversals

*/

#include<iostream>
using namespace std;

class TreeNode
{
public:
	char data;
	TreeNode *left;
	TreeNode *right;
	
public:
	TreeNode *createTreeNode(char x);
	
	void preorder(TreeNode *Root);

	void inorder(TreeNode *Root);

	void postorder(TreeNode *Root);

};

TreeNode * root = NULL;

class stack
{
public:
	TreeNode *treenode;
	stack *next ;
public:
	void push(stack *sn);
	TreeNode *pop();
	stack *createStackNode(TreeNode *tn);

};
stack *Top = NULL;



int main()
{
	TreeNode tree;
	stack stk;

	char exp[30];
	int choise;
	


	do{
		cout<<"\n------------------------------------------------------------------------------------\n";
		cout<<"\n\t\t\tRecursive Tree Traversal\n\n";
		cout<<"\t\t1.Create an Expression Tree\n";
		cout<<"\t\t2.Preorder Traversal\n";
		cout<<"\t\t3.Inorder Traversal\n";
		cout<<"\t\t4.Postorder Traversal\n";
		cout<<"\t\t5.Exit\n";
		cout<<"Your choise : ";
		cin>>choise;

		switch(choise)
		{
			case 1:
			{
				cout<<"Enter the postfix expression : ";
				cin>>exp;	
				for(int i=0;exp[i]!='\0';i++)
				{
					if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
					{
						TreeNode *newTNode = tree.createTreeNode(exp[i]);
						newTNode->right = stk.pop();
						newTNode->left = stk.pop();
						stack *newSNode = stk.createStackNode(newTNode);
						stk.push(newSNode);
						root = newTNode;
					}
					else
					{
						TreeNode *newTNode = tree.createTreeNode(exp[i]);
						stack *newSNode = stk.createStackNode(newTNode);
						stk.push(newSNode);

					}
				}
			cout<<"\n\tYour Expression Tree is ready !!\n";

			}
			break;
			case 2:
			{
				cout<<"Preorder Traversal of Expression Tree :  ";
	
				tree.preorder(root);
				cout<<"\n";
			}
			break;
			case 3:
			{
				cout<<"Inorder Traversal of Expression Tree : ";
				tree.inorder(root);

			}
			break;
			case 4:
			{
				cout<<"Postorder Traversal of Expression Tree : ";
				tree.postorder(root);
			}
			break;
		}

	}while(choise<5&&choise>0);

	
}





TreeNode *TreeNode :: createTreeNode(char x)
{
	TreeNode *temp = new TreeNode;
	temp->data = x;
	temp->right= NULL;
	temp->left = NULL;
	return temp;
}

stack *stack ::createStackNode(TreeNode *tn)
{
	stack *temp = new stack;
	temp->treenode = tn;
	temp->next = NULL;
	return temp;
}

void stack:: push(stack *sn)
{
	if(Top==NULL)
		Top = sn;
	else{
		sn->next = Top;
		Top = sn;
	}
	
}

TreeNode *stack ::pop()
{
	stack *temp = Top;
	Top = Top->next;
	return temp->treenode;
}


 void TreeNode:: preorder(TreeNode *Root)
{

		TreeNode *temp = Root;
		if(temp==NULL)
			return;
		cout<<"   "<<temp->data;
		preorder(temp->left);
		preorder(temp->right);
}
void TreeNode:: inorder(TreeNode *Root)
{
	TreeNode *temp = Root;
	if(temp==NULL)
		return;
	inorder(temp->left);
	cout<<"  "<<temp->data;
	inorder(temp->right);
}

void TreeNode:: postorder(TreeNode *Root)
{
	TreeNode *temp = Root;
	if(temp==NULL)
		return;
	postorder(temp->left);
	postorder(temp->right);
	cout<<"  "<<temp->data;
}
