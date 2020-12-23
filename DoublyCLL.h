//Generic Implementation of DoublyCLL
#include<iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	struct Node<T> *next;
	struct Node<T> *prev;
};

template <class T>
class DoublyCLL
{
	public :
		struct Node<T> *Head;
		struct Node<T> *Tail;
	
	DoublyCLL()
	{
		Head=NULL;
		Tail=NULL;
	}
	
	int Count()
	{
		int cnt=0;
		do
		{
			cnt++;
			Head=Head->next;
		}while(Head!=Tail->next);
		return cnt;
	}
	
	void InsertFirst(T value)
	{
		struct Node<T> *newn=new Node<T>;
		newn->data=value;
		newn->next=NULL;
		newn->prev=NULL;
		
		if((Head==NULL) &&(Tail==NULL))
		{
			Head=newn;
			Tail=newn;
		}
		
		else
		{
			newn->next=Head;
			Head->prev=newn;
			Head=Head->prev;
		}
		
		Tail->next=Head;
		Head->prev=Tail;
	}
	
	void InsertLast(T value)
	{
		struct Node<T> *newn=new Node<T>;
		newn->data=value;
		newn->next=NULL;
		newn->prev=NULL;
		if((Head==NULL)&&(Tail==NULL))
		{
			Head=newn;
			Tail=newn;
		}
		
		else
		{
			Tail->next=newn;
			newn->prev=Tail;
			Tail=Tail->next;
		}
		
		Tail->next=Head;
		Head->prev=Tail;
	}
	
	void InsertAtPos(T value,int iPos)
	{
		int Size=Count();
		
		if((iPos<0)||(iPos>Size+1))
		{
			return;
		}
		
		if(iPos==1)
		{
			InsertFirst(value);
		}
		
		else if(iPos==Size+1)
		{
			InsertLast(value);
		}
		
		else
		{
			struct Node<T> *newn=new Node<T>;
			struct Node<T> *temp=Head;
			newn->data=value;
			newn->next=NULL;
			newn->prev=NULL;
			
			for(int i=1;i<iPos-1;i++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			newn->next->prev=newn;
			
			temp->next=newn;
			newn->prev=temp;
		}
	}
	
	void DeleteFirst()
	{
		if((Head==NULL)&&(Tail==NULL))
		{
			return;
		}
		
		if(Head==Tail)
		{
			delete(Head);
			Head=NULL;
			Tail=NULL;
		}
		
		else
		{
			Head=Head->next;
			delete(Tail->next);
			Tail->next=Head;
			Head->prev=Tail;
			
		}
	}
	
	void DeleteLast()
	{
		if((Head==NULL)&&(Tail==NULL))
		{
			return;
		}
		
		if(Head==Tail)
		{
			delete(Head);
			Head=NULL;
			Tail=NULL;
		}
		
		else
		{
			Tail=Tail->prev;
			delete(Tail->next);
			Head->prev=Tail;
			Tail->next=Head;
		}
	}
	
	void DeleteAtPos(int iPos)
	{
		int Size=Count();
		
		if((iPos<0)||(iPos>Size))
		{
			return;
		}
		
		if(iPos==1)
		{
			DeleteFirst();
		}
		
		else if(iPos==Size)
		{
			DeleteLast();
		}
		
		else
		{
			for(int i=1;i<iPos-1;i++)
			{
				
			}
		}
	}
	
	
	
	void Display()
	{
		do
		{
			cout<<Head->data<<"\t";
			Head=Head->next;
		}while(Head!=Tail->next);
		cout<<"\n";
	}
};

