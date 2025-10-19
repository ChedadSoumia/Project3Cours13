#pragma once
#include <iostream>
using namespace std;

template <typename T>
class clsDblLinkedList
{
protected:
	short _Size = 0 ;

	

public:
	class Node
	{
	public:
		T Value;
		Node* Next;
		Node* Prev;
	};
	
	Node* head = NULL;

	void InsertAtBeginning(T Value) {

		Node* NewNode = new Node();
		NewNode->Value = Value;
		NewNode->Next = head;
		NewNode->Prev = NULL;

		if (head != NULL) {
			head->Prev = NewNode;
		}

		head = NewNode;
		_Size++;
	}

	Node* Find(T Value) {

		Node* Current = head;
		while (Current != NULL) {
			
			if (Current->Value == Value) {
				return Current;
			}

			Current = Current->Next;

		}
		return NULL;
	}

	void PrintList() {
		Node* Current = head;
		while (Current != NULL) {
			cout << Current->Value << " ";
			Current = Current->Next;
		}
		cout << endl;
	}

	void InsertAfter(Node* Current,T Value) {

		Node* newNode = new Node();
		newNode->Value = Value;
		newNode->Next = Current->Next;
		newNode->Prev = Current;

		if (Current->Next != NULL) {
			Current->Next->Prev = newNode;
		}

		Current->Next = newNode;
		_Size++;
	}

	void InsertAtEnd(T Value) {
		
		Node* newNode = new Node();
		newNode->Value = Value;
		newNode->Next = NULL;

		if (head == NULL) {
			newNode->Prev = NULL;
			head = newNode;
		}
		else {

			Node* Current = head;
			while (Current->Next != NULL) {
				Current = Current->Next;
			}
			Current->Next = newNode;
			newNode->Prev = Current;

		}
		_Size++;
	}

	void DeleteNode(Node*& NodeToDelete) {

		if (head == NULL || NodeToDelete == NULL) {
			return;
		}
		if (head == NodeToDelete) {
			head = NodeToDelete->Next;
		}
		if (NodeToDelete->Next != NULL) {
			NodeToDelete->Next->Prev = NodeToDelete->Prev;
		}

		if (NodeToDelete->Prev != NULL) {
			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}
		delete NodeToDelete;  
		_Size--;
	}

	void DeleteFirstNode(){
	
		if (head == NULL) {
			return;
		}

		Node* temp = head;
		head = head->Next;
		if (head != NULL) {
			head->Prev = NULL;
		}
		delete temp;
		_Size--;
	}
	
	void DeleteLastNode() {
	
		if (head == NULL) {
			return;
		}

		if(head->Next == NULL){
			delete head;
			head = NULL;
			_Size--;
			return;
		}
	
		Node* Current = head;
	
		while (Current->Next->Next != NULL) {
			Current = Current->Next;
		}

		Node* temp = Current->Next;
		Current->Next = NULL;
		delete temp;
		_Size--;
	}

	int Size() {
		return _Size;
	}

	bool IsEmpty() {
		return (_Size == 0? true :false );
	}

	void Clear() {
		while (_Size > 0) {
			DeleteFirstNode();
		}
	}
	
	void  Reverse()
	{
		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr) {
			temp = current->Prev;
			current->Prev = current->Next;
			current->Next = temp;
			current = current->Prev;
		}

		if (temp != nullptr) {
			head = temp->Prev;
		}
	}

	Node* GetNode(int Index) {

		int Counter = 0;

		if (Index > _Size - 1 || Index < 0 ) {
			return NULL;
		}

		Node* Current = head;
		while (Current != NULL && (Current->Next != NULL)) {
			
			if (Counter == Index) {
				break;
			}
			Current = Current->Next;
			Counter++;
		}

		return Current;
	}


	T GetItem(int Index) {

		Node* ItemNode = GetNode(Index);
		
		if (ItemNode == NULL) {
			return NULL;
		}
		else {
			return ItemNode->Value;
		}
		
	}

	bool UpdateItem(int Index, T Value) {

		Node* ItemNode = GetNode(Index);
		if (ItemNode != NULL) {
			ItemNode->Value = Value;
			return true;
		}
		else {
			return false;
		}

	}

	bool   InsertAfter(int Index, T Value) {

		Node* ItemNode = GetNode(Index);
		if (ItemNode != NULL) {
			InsertAfter(ItemNode, Value);
			return true;
		}
		else {
			return false;
		}
	}




};

