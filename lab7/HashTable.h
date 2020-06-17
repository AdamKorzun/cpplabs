//---------------------------------------------------------------------------
#include "Stack.h"
#ifndef HashTableH
#define HashTableH
class HashTable{
	private:
	int size;
	Stack** hashes;
	public:
	HashTable(int size){
		this->size = size;
		hashes = new Stack*[size];
		for (int i = 0; i < size; i++) {
			hashes[i] =  new Stack();
		}
	}
	Stack* GetStack(int key){
		return hashes[key % size];
	}
	void SetStack(int i, Stack* stack){
         hashes[i] = stack;
	}
	void Add(int key){
		Stack* stack = hashes[key % size];
		hashes[key % size] = stack->Push(key);
	}
	void Remove(int key){
		Stack* stack = hashes[key % size];
		if (stack->Filled()) {
			while (stack->Filled() && stack->GetKey() == key){
				hashes[key % size] = stack->Pop();
			}



		}

	}
	void DeleteTable(){
		for (int i = 0; i < size; i++) {
		   Stack* stack = hashes[i];
		   while(stack->Filled()){
				stack = stack->Pop();
		   }
		   delete hashes[i];
		}
	}


};
//---------------------------------------------------------------------------
#endif
