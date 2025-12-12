#include <iostream>
#include <string>
using namespace std;
void printName(string name, int count)
{
    if (count > 5)
        return;
    cout << name << endl;
    printName(name, count + 1);
}
int main()
{
    string name;
    cout << "Enter your name" << endl;
    cin >> name;
    printName(name, 1);
    return 0;
}