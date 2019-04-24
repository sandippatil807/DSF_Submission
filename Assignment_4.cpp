/*			Problem Statement : Modify the above BST such that the roles of the left and right pointers are swapped at every node

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
int swapTree(tnode *);
void swap(tnode *,tnode *);
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
	do 
	{
		cout<<"\n-------------------------------------------------------------------------\n";
		cout<<"\n\t\t\tPlay With Binary Search Tree\n";
		cout<<"\n\t\t1.Inser a new node\n\t\t2.Swipe the tree\n\t\t3.Inorder traversal\n\t\t4.Exit\n\t\tYour choise : ";
		cin>>choise;
		switch(choise)
		{
			case 1:
			cout<<"Enter the data : ";
			cin>>num;
			create(num);
			break;
			case 2:
			swapTree(root);			
			cout<<"Tree Swiped ! ";
			break;
			case 3:
			cout<<"Inorder Traversal of Tree : \n";
			inorder(root);
			break;
		}
	}while(choise<4);
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
int swapTree(tnode *Root)
{
	tnode *current = Root;

	if(current==NULL)
		return 0;
	tnode *temp =current->rptr;
	current->rptr = current->lptr;
	current->lptr = temp;
	//swap(current->lptr,current->rptr);
	swapTree(current->lptr);
	swapTree(current->rptr);


}
void swap(tnode *r,tnode *l)
{
	tnode *temp = r;
	r = l;
	l = temp;
}