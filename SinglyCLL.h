#include<iostream>
using namespace std;

template <class T>

struct Node{
	T data;
	struct Node<T> *next;
	
};

template <class T>
class SinglyCLL{
	public:
			struct Node<T> *Head;
			struct Node<T> *Tail;
			int size=0;
		
		SinglyCLL(){
				Head=NULL;
				Tail=NULL;
				
		}
		
		int count(){
			int cnt=0;
			do {
				 cnt++;
				Head=Head->next;
			}while(Head!=Tail->next);
			return cnt;
		}
		
		void Display(){
			struct Node<T> *temp=Head;
			
			do{
				cout<<temp->data<<"\t";
				temp=temp->next;
				
			}while(temp!=Tail->next);
		}
		
	void InsertFirst(T value){
		struct  Node<T>* newn=new Node<T>;
		newn->next=NULL;
		newn->data=value;
		
		if((Head==NULL)&&(Tail==NULL)){
			Head=newn;
			Tail=newn;
		}
		
		else{
			newn->next=Head;
			Head=newn;
		}
		Tail->next=Head;
	}		
	
	void InsertLast(T value){
		struct Node<T> *newn=new Node<T>;
		newn->next=NULL;
		newn->data=value;
		
		if((Head==NULL) && (Tail==NULL)){
			Head=newn;
			Tail=newn;
		}
		
		else{
			
			Tail->next=newn;
			newn->next=Tail;
			Tail=newn;
			
		}
		
		Tail->next=Head;
	}
	
	void DeleteFirst(){
		if((Head==NULL)&&(Tail==NULL)) return;
		if(Head==Tail){
			delete(Head);
			Head=NULL;
			Tail=NULL;
		}
		
		else{
			Head=Head->next;
			delete(Tail->next);
			Tail->next=Head;
		}
	}
	
	void DeleteLast(){
		if((Head==NULL)&&(Tail==NULL)) return;
		if(Head==Tail){
			delete(Head);
			Head=NULL;
			Tail=NULL;
		}
		
		else{
			struct Node<T> *temp=Head;
			while(temp->next->next!=Tail){
				temp=temp->next;
			}
			
			Tail=temp->next;
			delete(Tail->next);
			
		}
		Tail->next=Head;
	}
	void InsertAtPos(T value,int pos){
		int size=count();
		
		if((pos<0)||(pos>size+1)) return;
		
		if(pos==1) InsertFirst(value);
		else if(pos==size+1) InsertLast(value);
		else{
			struct Node<T> *newn=new Node<T>;
			struct Node<T> *temp=Head;
			newn->data=value;
			newn->next=NULL;
			for(int i=1;i<pos-1;i++){
				temp=temp->next;
			}
			
			newn->next=temp->next;
			temp->next=newn;
		}
		
	}
	
	void DeleteAtPos(int pos){
		int size=count();
		if((pos<0)||(pos>size)) return;
		if(pos==1) DeleteFirst();
		else if(pos==size) DeleteLast();
		
		else{
			struct Node<T> *temp1=Head;
			struct Node<T> *temp2=Head;
			for(int i=1;i<pos-1;i++){
				temp1=temp1->next;
			}
			temp2=temp1->next;
			temp1->next=temp2->next;
			delete(temp2);
			
			
		}
	}
};











