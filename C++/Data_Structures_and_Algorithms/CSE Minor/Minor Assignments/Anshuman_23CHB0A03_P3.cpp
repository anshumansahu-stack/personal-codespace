#include <iostream>
#include <string>
using namespace std;

struct student {
    string studentName;
    string RollNo;
    string Department;

    // Combine student data into a single string
    string Combine() {
        return studentName + "\t" + RollNo + "\t" + Department;
    }

    // Set student data and return the combined string
    string setData() {
        cout << "Enter the name of the student:" << endl;
        cin.ignore(); // Clear input buffer
        getline(cin, studentName);
        cout << "Enter the corresponding roll number:" << endl;
        cin >> RollNo;
        cout << "Enter the corresponding Department:" << endl;
        cin >> Department;
        return Combine();
    }
};

// Queue class to manage student data using circular array
class Queue {
private:
    string q[10000]; // Queue declaration in the form of an array
    int frontIndex;  // Index of the front element in the queue
    int rearIndex;   // Index of the rear element in the queue
    int maxlim;      // Maximum limit of the queue
    int size;        // Current number of elements in the queue

public:
    Queue() : frontIndex(0), rearIndex(-1), maxlim(0), size(0) {} // Constructor

    // Set the maximum limit of the queue
    void setmax() {
        cout << "Enter the number of students in the Institute:" << endl;
        cin >> maxlim;
        cout << endl;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == maxlim;
    }

    // Add a new element to the queue (EnQueue)
    bool EnQueue(string v) {
        if (isFull()) {
            cout << "The Queue is Full!" << endl;
            return false;
        } else {
            rearIndex = (rearIndex + 1) % maxlim;
            q[rearIndex] = v;
            size++;
            return true;
        }
    }

    // Remove the front element from the queue (DeQueue)
    string DeQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return "Error";
        } else {
            string temp = q[frontIndex];
            frontIndex = (frontIndex + 1) % maxlim;
            size--;
            return temp;
        }
    }

    // Get the front element of the queue
    string Front() {
        if (!isEmpty()) {
            return q[frontIndex];
        } else {
            return "Empty Queue";
        }
    }

    // Get the rear element of the queue
    string Rear() {
        if (!isEmpty()) {
            return q[rearIndex];
        } else {
            return "Empty Queue";
        }
    }

    // Return the number of elements in the queue
    int Count() {
        return size;
    }

    // Print all elements of the queue
    void Print() {
        cout << "Printing all elements of queue:" << endl;
        cout << "Name\tRollNo\tDepartment" << endl;
        int i = frontIndex;
        for (int count = 0; count < size; count++) {
            cout << q[i] << endl;
            i = (i + 1) % maxlim;
        }
    }

    // Display the menu and handle user choices
    void menu() {
        int response = 0;
        while (response != 8) {
            cout << "1: DeQueue element" << endl;
            cout << "2: Read front element" << endl;
            cout << "3: Read rear element" << endl;
            cout << "4: EnQueue element" << endl;
            cout << "5: Print all elements" << endl;
            cout << "6: isEmpty" << endl;
            cout << "7: isFull" << endl;
            cout << "8: Exit" << endl;
            cin >> response;

            switch (response) {
                case 1: {
                    cout << "Name\tRollNo\tDepartment" << endl;
                    cout << DeQueue() << endl;
                    cout << "This is the student that was dequeued." << endl;
                } break;
                case 2: {
                    cout << "The frontmost Student in the queue is:" << endl;
                    cout << "Name\tRollNo\tDepartment" << endl;
                    cout << Front() << endl;
                } break;
                case 3: {
                    cout << "The rearmost Student in the queue is:" << endl;
                    cout << "Name\tRollNo\tDepartment" << endl;
                    cout << Rear() << endl;
                } break;
                case 4: {
                    if (isFull()) {
                        cout << "Queue is Full!" << endl;
                    } else {
                        student tempStudent;
                        string data = tempStudent.setData();
                        EnQueue(data);
                    }
                } break;
                case 5: {
                    Print();
                } break;
                case 6: {
                    if (isEmpty()) {
                        cout << "The Queue is Empty!" << endl;
                    } else {
                        cout << "The queue is not Empty!" << endl;
                    }
                } break;
                case 7: {
                    if (isFull()) {
                        cout << "The Queue is Full!" << endl;
                    } else {
                        cout << "The queue is not Full!" << endl;
                    }
                } break;
                case 8: {
                    cout << "OK Thank you!" << endl;
                } break;
                default: {
                    cout << "Enter a valid response!" << endl;
                } break;
            }
        }
    }
};

int main() {
    Queue studentQueue;
    studentQueue.setmax(); // Initialize the number of students
    int numberOfStudents = studentQueue.Count();

    for (int i = 0; i < numberOfStudents; i++) {
        string data = student().setData();
        studentQueue.EnQueue(data);
        char response;
        cout << "Another Student? (y/n): ";
        cin >> response;
        if (response != 'y') {
            cout << "You have entered " << studentQueue.Count() << " elements." << endl;
            break;
        }
    }

    studentQueue.menu();
    return 0;
}
