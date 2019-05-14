#include<iostream>
#include<string>
using namespace std;

class hashing{
	typedef struct Node{
		string word;
		string meaning;
		Node *next;
		
	}Node;
	
	Node *arr[10];
	public:
	hashing()
	{
	int i=0;
		while(i<10)
		{
			arr[i]=NULL;
			i++;
		}
	}
	
	public:
		
		void input()
		{
			char ch;
			do
			{
				string key,value;
				cout<<"Enter the word : ";
				cin>>key;
				cout<<"Enter the meaning : ";
				cin>>value;
				
				Node *New =new Node;
				New->word = key;
				New->meaning = value;
				New->next = NULL;
				
				
				int x = hash(key);
				
				if(arr[x]==NULL)
					arr[x] = New;
				else
				{
					Node *temp = arr[x];
					while(temp->next!=NULL)
						temp =temp->next;
					temp->next = New;
					
				}
				cout<<"Want to add more ?  ";
				cin>>ch;
			}while(ch=='y'||ch=='Y');
			
		}
		
		int hash(string word)
		{
			int i=0,x=0,sum=0;
			while(i<word.length())
			{
				x = word[i];
				sum = sum +x;
				i++;
			}
			sum = sum %10;
			return sum;
		}
		
		void display()
		{
			Node *temp =NULL;
			int j=0;
			while(j<10)
			{
				if(arr[j]==NULL)
				{
					j++;
					continue;
				}
				else{
					temp = arr[j];
					
					while(temp!=NULL)
					{
						cout<<"\t"<<temp->word<<"\t"<<temp->meaning<<endl;
						temp = temp->next;
					}
					j++;
				}
				
			}
		}
		void delWord()
		{
			string key;
			cout<<"Enter the word to delete : ";
			cin>>key;
			int flag = 0;
			int  x= hash(key);
			
			Node *temp = NULL;
			temp =arr[x];
			
			while(temp!=NULL&&temp->word!=key)
			{
				temp =temp->next;
			}
			
			if(temp ==NULL)
			{
				cout<<"The word does not found in the list \n";
			}
			else
			{
				Node *p;
				if(flag==0)
				{
					p=temp;
					temp =temp->next;
					arr[x] =temp;
					delete (p);
					display();
				}
				else{
					p = temp ->next;
					temp->next = (temp->next)->next;
					delete(p);
					display();
				}
			}
		}
		
		void search()
		{
			string find;
			cout<<"Enter the word : ";
			cin>>find;
			
			int x=hash(find);
			
			Node *temp =arr[x];
			
			while(temp!=NULL&&temp->word!=find)
			{
				temp = temp->next;
				
			}
			if(temp==NULL)
			{
				cout<<"Sorry word does not found in dictonary\n";
			}
			else
			{
				cout<<"The word "<<find <<" mean "<<temp->meaning<<endl;
			}
		}
		
	
};


int main()
{
	hashing s;
	s.input();
	s.display();
	s.delWord();
	s.search();
}












