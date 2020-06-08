//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
class Stack{
	private:

	char info;
	Stack* next;

	public:
	char GetInfo(){
		return info;
	}
	void SetInfo(char info){
		this->info = info;
	}
	Stack(){
		next = NULL;
		info = NULL;
	}
	Stack* Push(Stack* beginning, char info){
		Stack* newEl = new Stack;
		newEl->info = info;
		newEl->next = beginning;
        return newEl;
	}
	Stack* Pop(Stack* beginning,char* info){
		Stack* temp = beginning;
		*info = beginning->info;
		temp = temp->next;
		delete beginning;
		return temp;

	}


};

//---------------------------------------------------------------------------
#endif
