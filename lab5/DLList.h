//---------------------------------------------------------------------------

#ifndef DLListH
#define DLListH
#include "Queue.cpp"
//---------------------------------------------------------------------------
#endif


class DLList : public Queue{
	public:
	void Swap(){

		Node* temp = Tail;
		temp=Head;
		int maxEl = temp->x;
		int minEl = temp->x;
		while(temp != NULL){
			if (temp->x > maxEl) {
				maxEl = temp->x;
			}
			else if (temp->x < minEl) {
                minEl = temp->x;
			}
			temp = temp->next;
		}
		temp=Head;
		while (temp!=NULL){

			if (temp->x == minEl) {
				temp->x = maxEl;
			}
			else if(temp->x == maxEl){
                temp->x = minEl;
			}
			temp = temp->next;
		}
	}
	void SetBase(Node* Head, Node* Tail){
		this->Head = Head;
		this->Tail = Tail;
	}
	~DLList() {
		while (Head){
			Tail = Head->next;
			Head = Tail;
		}

	};
};

