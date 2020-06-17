//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
class Stack {
	private:
	int key;
	Stack* next;
	public:
	Stack(int key){
		this->key = key;
		next = NULL;
	}
	Stack(){
		key = NULL;
		next = NULL;
	}
	Stack* Push(int key){
		Stack* temp = new Stack(key);
		temp->next = this;
		return temp;
	}
	Stack*- Pop(){
		//info = this->key;
		Stack* temp = this->next;

		delete this;

		return temp;
	}
	int GetKey(){
		return key;
	}
	bool Filled(){
		return !(key == NULL);
	}
};
//---------------------------------------------------------------------------
#endif
