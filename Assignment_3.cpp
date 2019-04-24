/*	Problem Statement : Construct binary search tree by inserting the values in the order given. After constructing a binary search tree
						i.Insert new node
						ii. Find number of nodes in longest path along with its height
						iii. Minimum data value found in the tree

*/

#include<iostream>
#include<math.h>
using namespace std;
struct tnode{
	int data;
	tnode *lptr,*rptr;
};
tnode *root=NULL;
tnode *insert(int val);
void create(int val);
void inorder(tnode *);
void preorder(tnode *);
void postorder(tnode*);
int minimum(tnode *);
int height(tnode * );
int main()
{
	int num,a,choise;
	cout<<"Nodes in tree : ";
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cout<<"Enter the data : ";
		cin>>num;
		create(num);
	}
	do {
		cout<<"-------------------------------------------------------------------------\n";
		cout<<"\n\t\t\tHave Fun with Binary Search Tree!!\n";
		cout<<"\n\t\t1.Inser a new node\n\t\t2.Find heiht of tree\n\t\t3.Minimum node present in Tree \n\t\t4.Inorder Traversal\n\t\t5.Exit\n\t\tYour choise : ";
		cin>>choise;
		switch(choise)
		{
			case 1:
			cout<<"Enter the data : ";
			cin>>num;
			create(num);
			cout<<"\tNode inserted Successflly in Tree!!\n";
			break;
			case 2:
			cout<<"The Height of tree is : ";
			cout<<height(root)<<endl;
			break;
			case 3:
			cout<<"The minimum of tree is : ";
			cout<<minimum(root)<<endl;
			break;
			case 4:
			cout<<"Inorder Traversal of Tree : \n";
			inorder(root);
			break;
	}
	
}
	while(choise<5);

}
tnode *insert(int val)
{
	tnode *newNode =new tnode;
	newNode->data=val;
	newNode->lptr =newNode->rptr =NULL;
	return newNode;
}
void create(int val)
{
	tnode *parent,*current=root;
	if(root==NULL)
	{
		root   = insert(val);
	}
	else
	{
		while(current!=NULL)
		{
			parent =current;
			if(val<current->data)
			current =current->lptr;
			else
			current = current->rptr;
		}
		if(val<parent->data)
			parent->lptr=insert(val);
			else
			parent->rptr =insert(val);
	}
}

void inorder(tnode *Root)
{
	
	
	tnode *temp =Root;
	if(temp==NULL)
	return ;
	inorder(temp->lptr);
	cout<<temp->data<<endl;
	inorder(temp->rptr);
}
void preorder(tnode *Root)
{
	tnode *temp=Root;
	if(temp==NULL)
	return ;
	cout<<temp->data<<endl;
	preorder(temp->lptr);
	preorder(temp->rptr);
	
}
void postorder(tnode *Root)
{
	tnode *temp =Root;
	if(temp==NULL)
	return ;
	preorder(temp->lptr);
	preorder(temp->rptr);
	cout<<temp->data<<endl;


	
}

int minimum(tnode *Root)
{
	tnode *parent,*temp = Root;
	while(temp!=NULL)
	{	
		parent = temp ;
		temp =temp->lptr;
	}
	return parent->data;
	
}

int height(tnode *Root)
{
	tnode *current =Root;
	if(current == NULL)
	return 0;

	int ht = max(height(current->lptr),height(current->rptr));
		return ht+1;
}


