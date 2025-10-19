#include "clsMyStack.h"

int main()
{

	clsMyStack<int> MyStack;


	MyStack.push(4);
	MyStack.push(9);
	MyStack.push(2);
	MyStack.push(3);
	MyStack.push(5);
	MyStack.push(1);
	 

	MyStack.PrintList();
	
	MyStack.pop();
	MyStack.PrintList();

	cout << "\nthe size of stack is : " << MyStack.Size();
	cout << "\nthe 2 Item of stack is : " << MyStack.GetItem(2);
	cout << "\nthe Top of stack is : " << MyStack.Top();
	cout << "\nthe Bottom of stack is : " << MyStack.Bottom();
	cout << endl;
	MyStack.InsertAfter(3,100);
	MyStack.PrintList();
	MyStack.InsertAtFront(10);
	MyStack.PrintList();
	MyStack.InsertAtBack(200);
	MyStack.PrintList();
	cout << endl; cout << endl;
	cout << "\nthe 2 Item of stack is : " << MyStack.GetItem(2);
	cout << "\nthe Top of stack is : " << MyStack.Top();
	cout << "\nthe Bottom of stack is : " << MyStack.Bottom();


	cout << endl; cout << endl;
	MyStack.Reverse();
	MyStack.PrintList();
	cout << endl; cout << endl;
	MyStack.UpdateItem(3,200);
	MyStack.PrintList();
	cout << endl; cout << endl;

	return 0;
}
