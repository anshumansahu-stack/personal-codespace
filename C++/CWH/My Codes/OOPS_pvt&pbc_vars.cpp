#include<iostream>
#include<string>
using namespace std;
class Employee{
    private:
    int age,retirementdate,maritallife;
    string name;

    // Declaring variables at the class scope(outside any functions) ensures that they are
    // member variables of the class.This means that they are associated with  each instance of the class and maintain
    // their values throughout the lifetime of the object.

    int lifespan(){//Private function using private variables

        //The reason for not passing any parameters here or anywhere else in the functions is because lifespan function is designed to be a member function of
        //the employee class, that operates on the private member variables given. These members were each a part of the employee object
        //already, so they needn't be declared once again in the brackets().

        return (age+retirementdate+maritallife)/3;
    }

    int weeklyEarnings(){//Private function using public variables
        return salary*officehours;
    }

    public:
    int salary,officehours;

    //****CONSTRUCTOR****
    //Instead of initializing variables in various lines, For instance

    //Employee Abhay
    //Abhay.retirementdate=blah
    //Abhay.officehours=blah blah
    // Ye hai aam zindagi

    Employee(int a,int m, int r, int s, int o, string n)
    :age(a), maritallife(m), retirementdate(r), salary(s), officehours(o), name(n){}

    //This is something called as a constructor. With this present here, you wont need
    //multiple lines of codes to initialize each variable you have stated. just put
    //the required variable values in the bracket in the correct order.

    //In C++, constructors cannot be created within the private part of the class.
    //Constructors are special member functions that must be accessible to the outside world so
    //the objects can be created and initialized.
    //We can call the private values of the class also using a constructor.


    int salaryperlifespan(){//Calling a private function from public 
        return (salary*officehours)/lifespan();
    }

    int totallifemetrics(){//Calling private variables from public
        return age + maritallife + retirementdate;
    }

    int yearlysalary(){//Calling public variables from public
        return salary*officehours*52;//Assuming there are 52  working weeks in a year
    }

    int totalworkyears(){//Calling Private variables from public
        return retirementdate-age;
    }

    int getweeklyearnings(){//Public function to get the weekly earnings via the private function
        return weeklyEarnings();
    }

    void getdata(int n){
        cout<<"Start entering the info of the "<<n<<"th candidate:"<<endl;
        cout<<"Name: ";
        cin>>name;
        cout<<"Age: ";
        cin>>age;
        cout<<"Marital life: ";
        cin>>maritallife;
        cout<<"Retirement Day: ";
        cin>>retirementdate;
        cout<<"Salary: ";
        cin>>salary;
        cout<<"Office Hours: ";
        cin>>officehours;
        Employee(age,maritallife,retirementdate,salary,officehours,name);

    }
    void display(int n){
        cout<<endl;
        cout<<endl;
        cout<<"The details entered for the employee "<<n<<" are: "<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Marital Life: "<<maritallife<<endl;
        cout<<"Retirement Day: "<<retirementdate<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"Office hours: "<<officehours<<endl;
    }

};
int main(){
    //I wanted to make multiple objects at a time in this code but currently i dont have knowledge about vectors.

    int numEmployees;
    cout<<"Enter the number of employees: ";
    cin>>numEmployees;

    return 0;
}