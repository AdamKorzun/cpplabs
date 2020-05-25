//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
#include <vcl.h>
class Tree {
	protected:
	class Node{
		protected:
		String fio;
		int passNum;
		Node* left;
		Node* right;
		public:
		Node(String fio, int passNum){
			this->fio = fio;
			this->passNum = passNum;
			left = NULL;
			right = NULL;
		}
		Node(){
			
			
		}
		void Print(TTreeView* treeView,TMemo* memo, int kl){
			//treeView->Items->AddChildFirst(NULL,);

            if (kl== -1) {
				treeView->Items->AddFirst(NULL,fio + ":" + IntToStr(passNum));
			}
			else{
					treeView->Items->AddChildFirst(treeView->Items->Item[kl],fio + ":" + IntToStr(passNum));
			}
			kl++;
			if (left) {

				left->Print(treeView, memo,kl);

			}

			//memo->Lines->Add(fio + ":" + IntToStr(passNum));

			if (right) {

				right->Print(treeView, memo,kl);

			}
			kl--;

		}
		/*
		void Balance(String fio, int passNum){

			if (passNum > this->passNum && right && left) {
				right->Insert(fio, passNum);
			}
			else if (passNum > this->passNum && right && !left) {
				left = new Node(fio,passNum);
			}
			else if(passNum > this->passNum && !right){
				right = new Node(fio, passNum);
			}
			else if(passNum < this->passNum && left && right){
				left->Insert(fio,passNum);
			}
			else if(passNum < this->passNum && left && !right){
				right = new Node(fio,passNum);
			}
			else {
				left = new Node(fio, passNum);
			}
		}
		*/
		void Insert(String fio,int passNum){
			if (passNum > this->passNum && right) {
				right->Insert(fio, passNum);
			}
			else if(passNum > this->passNum && !right){
				right = new Node(fio, passNum);
			}
			else if(passNum < this->passNum && left){
				left->Insert(fio,passNum);
			}
			else {
				left = new Node(fio, passNum);
			}
		}
		void DelElement(int el){
			
			if(left){
				if (left->passNum == el) {
					if(!left->left && !left->right){
						delete left;
						left = NULL;
					}
					else if(!left->left && left->right){
						
						left = left->right;
					}
					else if(left->left && !left->right){
						
						left = left->left;
					}
					else{
							
                    }
				}
				left->DelElement(el);
			}
			if(right){
				right->DelElement(el);
			}

			
		}
		void Search(TMemo* memo, int number){
			if (number == passNum) {
				memo->Lines->Add(fio + ":" + IntToStr(passNum));
			}
			if (left) {
				left->Search(memo, number);
			}
			if(right){
				right->Search(memo, number);
			}
			
		}
		void Del(){
			if (left) {
				left->Del();
				delete left;
			}
			if (right) {
				right->Del();
				delete right;
			}
		}
		void PrObh(TMemo* memo){
			memo->Lines->Add(fio + ":" + IntToStr(passNum));
			if (left) {

				left->PrObh(memo);

			}
			if (right) {

				right->PrObh(memo);

			}
		}
		void ObrObh(TMemo* memo){
		
			if (left) {

				left->ObrObh(memo);

			}
			if (right) {

				right->ObrObh(memo);

			}
			memo->Lines->Add(fio + ":" + IntToStr(passNum));
		}
		void KeyObh(TMemo* memo){
			if (left) {

				left->KeyObh(memo);

			}
			memo->Lines->Add(fio + ":" + IntToStr(passNum));
			if (right) {

				right->KeyObh(memo);

			}
			
		}
		/*
		void Balance(Node **root, int intArr[],String strArr[], int start, int end)
		{
			if (start <= end)
			{
				int mid = (start + end + 1) / 2;
 
				root = new Node(strArr[mid], intArr[mid]);
				Balance(&((*root)->left), intArr,strArr, start, mid - 1);
				Balance(&((*root)->right), intArr,strArr, mid + 1, end);
			}
		}
		*/
		Node *createNode(String fio, int v)
		{
			Node *p = new Node;
 
			if (p != NULL)
			{
				p->fio = fio;
				p->passNum = v;
				p->left = NULL;
				p->right = NULL;
			}
 
			return p;
		}
		void Balance(Node** root,int intArr[],String strArr[], int start, int end)
		{
			if (start <= end)
			{
				int mid = (start + end + 1) / 2;
				*root = createNode(strArr[mid],intArr[mid]);
				//left = new Node(strArr[mid],intArr[mid]);
				
				//Insert(strArr[mid],intArr[mid]);
				Balance(&((*root)->left),intArr,strArr, start, mid - 1);
				//right = new Node(strArr[mid],intArr[mid]);
				Balance(&((*root)->right),intArr,strArr, mid + 1, end);
				
			}
		}
		void Average(int* res, TMemo* memo){
			*res += passNum;
			//memo->Lines->Add(IntToStr(res));
			if (left) {

				left->Average(res,memo);

			}

			if (right) {

				right->Average(res,memo);

			}
		}
		void FindAverage(String* st, int* res, int average, float* deviation){
			if (float(abs(average - passNum)) < *deviation ) {
				*st= fio;
				*res = passNum;
				*deviation = float(abs(average - passNum));
			}
            if (left) {

				left->FindAverage(st,res, average, deviation);

			}

			if (right) {

				right->FindAverage(st,res, average, deviation);

			}
		}
		String GetFio(){
			return fio;
		}
		int GetPassNum(){
            return passNum;
		}



	};
	Node* root;
	public:
	Tree(){
		root = NULL;
	}
	void Print(TTreeView* treeView, TMemo* memo){
		root->Print(treeView, memo,-1);
	}
	void Balance(String strArr[], int intArr[],int start, int n){
		
		root->Balance(&root,intArr,strArr,0,n - 1);


	}
	Node* GetRoot(){
		return root;
	}
	void SetRoot(Node* root){
		this->root = root;
	}
	void Insert(String fio, int passNum){
		if (!root) {
			root = new Node(fio, passNum);
		}
		else {
			root->Insert(fio,passNum);
		}
	}
	void Search(TMemo* memo,int number){
		memo->Clear();
		root->Search(memo,number);
	}

	void PrObh(TMemo* memo){
		memo->Clear();
		root->PrObh(memo);
	}
	void ObrObh(TMemo* memo){
		memo->Clear();
		root->ObrObh(memo);
	
	}
	void KeyObh(TMemo* memo){
		memo->Clear();
		root->KeyObh(memo);

	}
	
	~Tree(){
		if (!root) {
			return;
		}
		root->Del();
		delete root;
		root = NULL;

	}


};
//---------------------------------------------------------------------------
#endif
