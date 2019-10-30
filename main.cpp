#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

vector <class> Database;

struct Date {
    unsigned short int Year;
    unsigned short int Month;
    unsigned short int Day;
};

struct Student {
    string Firstname;
    string Lastname;
    unsigned long long int ID;
    Date Birthday;
    float Grade
};

struct Class {
        string ClassName;
        float Average;
        unsigned short int Capacity;
        vector <Student> Data;
};

void SelectClass(string);//choose a class and put it on work
void AddClass(string);//add a file to the DB classes
void RemoveClass(string);//delete a class from DB
void AddStudent(string, Date, unsigned long long int, float)//Add student to a Class
void RemoveStudent(unsigned long long int);//Remove student from a class
void Search(unsigned long long int);//search a student by ID
void Search(string, string);//search a student by FName and LName
void ShowClass(string);//Show a class students
void ShowAll();//show all students
void SortByName();//Sort a class by Name
void SortById();//Sort a Class by ID
void Save();//Save all classes to files


using namespace std;

int main()
{
    Start();
    return 0;
}
