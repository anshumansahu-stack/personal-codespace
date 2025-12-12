#include <iostream>
using namespace std;

class stack
{ // Declare a class 'stack'
private:
	int s[10000];	   // stack declaration in the form of array
	int topIndex = -1; // To determine whether the stack is empty or not
	int maxlim;		   // Maximum limit till which you can stack
public:
	int count() { return topIndex + 1; } // returns number of elements in the stack
	void setmax()
	{ // Initialize the maximum limit of the stack
		cout << "Enter the number of elements in the stack" << endl;
		cin >> maxlim;
		cout << endl;
	}
	void setelements()
	{ // Set Elements for the corresponding stack
		for (int i = 0; i < maxlim; i++)
		{
			int m;
			char response; // y=continue.
			cout << "Enter the " << i + 1 << " th element:" << endl;
			cin >> m;
			push(m);
			cout << " y:Enter another element \n n:Cancel" << endl;
			cin >> response;
			if (response == 'y')
			{
				continue;
			}
			else
			{
				cout << "You have entered a total of " << count() << " elements." << endl;
				cout << endl;
				break;
			}
		}
	}

	bool isFull() { return (topIndex >= maxlim - 1); } // detects whether the stack is full or not

	bool isEmpty() { return (topIndex == -1); } // detects whether the stack is empty or not

	bool push(int v)
	{
		if (isFull())
		{
			return false;
		} // returns false if the stack is full
		else
		{
			topIndex++;
			s[topIndex] = v;
			return true;
		} // if stack is not full then add another element and increase top index count
	}

	int top()
	{
		return s[topIndex];
	} // To access the top element in a stack

	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty!" << endl;
			cout << endl;
			return -1; // Error message
		}
		else
		{
			topIndex--;
			return s[topIndex + 1];
		}
	} // To remove the topmost element and to return the value of the removed item
	void info()
	{
		cout << "The topmost element is " << top() << endl;
		if (isFull())
		{
			cout << "The stack is Full." << endl;
		}
		else if (isEmpty())
		{
			cout << "The stack is empty." << endl;
		}
		else
		{
			cout << "The stack is partially filled." << endl;
			cout << "It has " << count() << " elements." << endl;
		}
	}
	void print()
	{
		cout << "Printing all elements of stack:" << endl;
		for (int i = 0; i <= topIndex; i++) // The index of the stack elements always runs from 0 to Topindex.
		{
			cout << s[i] << endl;
		}
	}
	void menu()
	{
		int response = 0;
		while (response != 7)
		{
			cout << "1:pop element(s)" << endl;
			cout << "2:read top element" << endl;
			cout << "3:push element(s)" << endl;
			cout << "4:print all elements" << endl;
			cout << "5:Information about stack" << endl;
			cout << "6:Number of elements in stack" << endl;
			cout << "7:Exit"<<endl;
			cin >> response;

			switch (response)
			{
			case 1:
			{
				int n;
				cout << "Enter the number of elements to pop " << endl;
				cin >> n;
				if (n > count())
				{
					cout << "Not enough elements in stack!" << endl;
				}
				else
				{
					for (int i = 1; i <= n; i++)
					{
						cout << "Popped Number " << pop()<<endl;
					}
				}
			}
			break;
			case 2:
			{
				cout << "The topmost element in the stack is " << top() << endl;
			}
			break;
			case 3:
			{
				int n;
				cout << "Enter the number of elements to push " << endl;
				cin >> n;
				for (int i = 1; i <= n; i++)
				{
					if (isFull())
					{
						cout << "Stack is Full!" << endl;
						break;
					}
					else
					{
						int m;
						cout << "Enter the " << i << "th element to push:" << endl;
						cin >> m;
						push(m);
					}
				}
			}
			break;
			case 4:
			{
				print();
			}
			break;
			case 5:
			{
				info();
			}
			break;
			case 6:
			{
				cout << "The number of elements in the stack is: " << count() << endl;
			}
			break;
			case 7:
			{
				cout << "OK Thank you!" << endl;
			}
			break;
			}
		}
	}
};
int main()
{
	stack s;
	s.setmax();
	s.setelements();
	s.menu();

	return 0;
}