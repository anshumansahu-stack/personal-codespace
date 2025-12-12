#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *prev;
    Node *next;
};

class DoubleLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the beginning
    void insertAtBegin(char value)
    {
        Node *newNode = new Node{value, nullptr, head};
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        if (tail == nullptr)
            tail = newNode;
    }

    // Insert at the end
    void insertAtEnd(char value)
    {
        Node *newNode = new Node{value, tail, nullptr};
        if (tail != nullptr)
            tail->next = newNode;
        tail = newNode;
        if (head == nullptr)
            head = newNode;
    }

    // Insert at a specific position
    void insertAtPosition(char value, int position)
    {
        if (position == 1)
        {
            insertAtBegin(value);
            return;
        }

        Node *temp = head;
        for (int i = 1; temp != nullptr && i < position - 1; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Position out of range\n";
            return;
        }

        Node *newNode = new Node{value, temp, temp->next};
        if (temp->next != nullptr)
            temp->next->prev = newNode;
        temp->next = newNode;

        if (newNode->next == nullptr)
            tail = newNode;
    }

    // Insert after a specific value
    void insertAfterValue(char target, char value)
    {
        Node *temp = head;
        while (temp != nullptr && temp->data != target)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Value " << target << " not found\n";
            return;
        }

        Node *newNode = new Node{value, temp, temp->next};
        if (temp->next != nullptr)
            temp->next->prev = newNode;
        temp->next = newNode;

        if (newNode->next == nullptr)
            tail = newNode;
    }

    // Delete at the beginning
    void deleteAtBegin()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
    }

    // Delete at the end
    void deleteAtEnd()
    {
        if (tail == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = tail;
        tail = tail->prev;

        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;

        delete temp;
    }

    // Delete at a specific position
    void deleteAtPosition(int position)
    {
        if (position == 1)
        {
            deleteAtBegin();
            return;
        }

        Node *temp = head;
        for (int i = 1; temp != nullptr && i < position; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Position out of range\n";
            return;
        }

        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;

        if (temp == tail)
            tail = temp->prev;

        delete temp;
    }

    // Delete after a specific value
    void deleteAfterValue(char target)
    {
        Node *temp = head;
        while (temp != nullptr && temp->data != target)
        {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "Value " << target << " not found or no element after it\n";
            return;
        }

        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete->next != nullptr)
            toDelete->next->prev = temp;

        if (toDelete == tail)
            tail = temp;

        delete toDelete;
    }

    // Search for an element
    bool search(char value)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Count elements in the list
    int count()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Print the list
    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    DoubleLinkedList dll;
    int choice, position;
    char value, target;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at Begin\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Insert After Value\n";
        cout << "5. Delete at Begin\n";
        cout << "6. Delete at End\n";
        cout << "7. Delete at Position\n";
        cout << "8. Delete After Value\n";
        cout << "9. Search for Value\n";
        cout << "10. Count elements\n";
        cout << "11. Print List\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            dll.insertAtBegin(value);
            break;

        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            dll.insertAtEnd(value);
            break;

        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position to insert: ";
            cin >> position;
            dll.insertAtPosition(value, position);
            break;

        case 4:
            cout << "Enter target value: ";
            cin >> target;
            cout << "Enter value to insert after " << target << ": ";
            cin >> value;
            dll.insertAfterValue(target, value);
            break;

        case 5:
            dll.deleteAtBegin();
            break;

        case 6:
            dll.deleteAtEnd();
            break;

        case 7:
            cout << "Enter position to delete: ";
            cin >> position;
            dll.deleteAtPosition(position);
            break;

        case 8:
            cout << "Enter target value: ";
            cin >> target;
            dll.deleteAfterValue(target);
            break;

        case 9:
            cout << "Enter value to search: ";
            cin >> value;
            if (dll.search(value))
                cout << value << " found in the list.\n";
            else
                cout << value << " not found in the list.\n";
            break;

        case 10:
            cout << "Total elements in the list: " << dll.count() << endl;
            break;

        case 11:
            cout << "List contents: ";
            dll.print();
            break;

        case 12:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 12);

    return 0;
}
