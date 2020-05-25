//---------------------------------------------------------------------------
#include <stddef.h>
#include <vcl.h>

#ifndef QueueH
#define QueueH

struct Node {
	 int x;
	 Node* next;
	 Node* prev;
};
class Queue{
	protected:
	Node* Head;
	Node* Tail;
	public:
	Queue(){
		Head = 0;
		Tail = 0;
	}
	void Show(TListBox *listBox){
		Node* temp = Tail;
		temp=Head;
		while(temp != NULL){
			listBox->Items->Add(IntToStr(temp->x));
			temp = temp->next;
		}
	}
	void Add(int x){
		Node* temp = new Node;
		temp->next = NULL;
		temp->x = x;
		if (Head!=NULL) {
			temp->prev = Tail;
			Tail->next = temp;
			Tail = temp;
		}
		else {
			temp->prev = NULL;
			Head=Tail=temp;
		}
	}
	void DelN(){
		if (Head == 0) {
			return;
		}
		Node* temp;
		temp = Head->next;
		delete Head;
		Head = temp;
	}
	Node* GetHead(){
		return Head;
	}
	Node* GetTail(){
		return Tail;
	}
	~Queue() {
		while (Head){
			Tail = Head->next;
			Head = Tail;
		}

	};
};
//---------------------------------------------------------------------------
#endif
