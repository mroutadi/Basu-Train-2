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
string Selected;
void Start()
{
    cout<<"*.*.*.*.*.*.*.* In The Name Of God *.*.*.*.*.*.*.*"<<endl;
    cout<<" Welcome to our class manager programmed by MrOutadi!"<<endl;
    cout<< "Our Program work with CLs(CommandLines) so please care about your Enters!"<<endl;
    cout<< "You knew CLs well But Whenever need help, Just write \"basu help\""<<endl;
    cout<< "And If you want to choose a class before use CLs, Just write \"basu select class <Class Name>\""<<endl;
    cout << "It's Better at first add a class to can do works (basu add class ...) : ";
    bool A = 1;              //program processing
    vector <string> History; //An additional vector for history of your CLs
    while(A)                 //This is same as forever loop until you want close the program !!!
        {
        string WTDs;                            //What is Doing CLs that you Entered(WTD = What To Do)
        getline(cin , WTDs);                    //This will get Command Line
        if ("basu" == WTDs.substr(0,4) || (WTDs.size()>1 && WTDs.size()<5)) History.push_back(WTDs);
        vector <string> Getter;                 //This is vector that save your command line
        string delimiter = "";                  //This string is every word of your CLs sentence
        int wordCounter = 0;                    //A good name will explain everything "Jorge Bosch" ;)
        for (char x : WTDs)                     //This will make your CLs in lower case
        {
            if (x == ' ')                       //separate word checker
            {
                for(char &zx : delimiter)       //letter minimizer
                {
                    if ( zx >= 'A' && zx <= 'Z')//It's Clear
                        zx += 32;
                }
                Getter.push_back(delimiter);    //Add word to sentence words vector
                wordCounter ++ ;
                delimiter = "";                 //Word from new , Daily bread from new :)
            }
            else
            {
                delimiter += x;                 //No space found so last word isn't complete
            }
        }
        Getter.push_back(delimiter);            //There is no space after last word(It's Enter (\n)) so it will add last word

        if(Getter.size() == 4 && "add" == Getter[1] && "class" == Getter[2])            //This is for add a class from classes file
        {
            AddClass(Getter[3]);
        }
        else if(Getter.size() == 4 && "remove" == Getter[1] && "class" == Getter[2])    //This is for remove a class from classes database
        {
            RemoveClass(Getter[3]);
        }
        else if(Getter.size() == 4 && "select" == Getter[1] && "class" == Getter[2])    //This is for select a class to do works
        {
            SelectClass(Getter[3]);
        }
        else if(Getter.size() == 3 && "select" == Getter[1] && "none" == Getter[2])     //This is for no class selected
        {
            SelectClass("");
            cout<< "No class is on selected mode"<<endl;
        }
        else if(Getter.size() == 3 && "add" == Getter[1] && "student" == Getter[2])     //This is to add a student to the selected class(Will ask if not selected)
        {
            string NandF;                                                   //Name and Family string
            cout<< "Enter Student's Name & Family : ";
            getline(cin , NandF);                                           //Get Name and Family
            string BirthDay;                                                //BirthDay string
            cout<< "Enter Student's Birthday(in this form YYYY/MM/DD) : ";
            cin >> BirthDay;                                                //Get Birthday
            Date B1;                                                        //Student Birthday variable(Class Date)
            B1.Year = stoi(BirthDay.substr(0,4));                           //Get Year (@@@@/--/--)
            B1.Month = stoi(BirthDay.substr(5,2));                          //Get Month (----/@@/--)
            B1.Day = stoi(BirthDay.substr(8,2));                            //Get Day (----/--/@@)
            cout<< "Enter Student's ID : ";
            unsigned long long int ID;                                      //ID variable
            cin >> ID;                                                      //Get ID
            cout<< "Enter Student's Grade : ";
            float Grade;                                                    //Student Grade Variable
            cin >> Grade;                                                   //Get Student Grade
            AddStudent(NandF, B1, ID, Grade);
        }
        else if(Getter.size() == 4 && "remove" == Getter[1] && "student" == Getter[2])  //This is to remove a student from the selected class
        {
            RemoveStudent(stoll(Getter[3]));
        }
        else if(Getter.size() == 3 && "search" == Getter[1] && 5 != Getter[2].size())   //This is for search student by it's ID
        {
            Search(stoull(Getter[2]));
        }
        else if(Getter.size() == 4 && "search" == Getter[1] && 5 == Getter[2].size())   //This is for search student by it's Name and Family
        {
            if ( Getter[2][0] >= 'a' && Getter[2][0] <= 'z')      //Make Name first letter Uppercase
                Getter[2][0] -= 32;
            for (int q = 1 ; q < Getter[2].size() ; q++)          //Make Name first letter lowercase
            {
                if ( Getter[2][q] >= 'a' && Getter[2][q] <= 'z')
                Getter[2][q] += 32;
            }
            if ( Getter[3][0] >= 'a' && Getter[3][0] <= 'z')      //Make Family first letter Uppercase
                Getter[3][0] -= 32;
            for (int q = 1 ; q < Getter[3].size() ; q++)          //Make Family first letter lowercase
            {
                if ( Getter[3][q] >= 'a' && Getter[3][q] <= 'z')
                Getter[3][q] += 32;
            }
            string N = Getter[2];                                 //Name variable
            string L = Getter[3];                                 //Family variable
            Search(N,L);
        }
        else if(Getter.size() == 2 && "show" == Getter[1])                              //This will Show selected class Info
        {
            ShowClass(Selected);
        }
        else if(Getter.size() == 3 && "show" == Getter[1])                              //This will Show the class in the Entered Cls
        {
            ShowClass(Getter[2]);
        }
        else if(Getter.size() == 3 && "sort" == Getter[1] && "name" == Getter[2])       //Sort selected class by Name
        {
            SortByName();
        }
        else if(Getter.size() == 3 && "sort" == Getter[1] && "id" == Getter[2])         //Sort selected class by ID
        {
            SortById();
        }
        else if(Getter.size() == 2 && "save" == Getter[1])                              //Save classes to a file
        {
            Save();
        }
        else if(Getter.size() == 2 && "history" == Getter[1])                           //Show history of Command Lines
        {
            for(string &i : History)                                                    //This vector added all your CLs and now are at one place for remembering
            {                                    /*History may not repeat itself, but it sure does rhyme.   --Mark Twain*/
                cout << "\t" <<i << endl;
            }
        }
        else if ("exit" == Getter[0])                                                   //Exit
        {
            A = 0;                                                                      //See Line 63 comment
            cout << "\nGood Bye"<<endl;
            return;
        }
        else if(Getter.size() == 2 && "rank" == Getter[1])                              //This will show class students with their rank
        {
            int RankCtr = 1;                                                            //Rank counter to create a numbered list
          	for(Class &j : Database)                                                    //search class in DB
            {
              	if(j.ClassName == Selected)                                             //Check selected class
                {
            		for(Student &slct : j.Data)
                    {
                        if (RankCtr < 10) cout << " ";
                        if (slct.Grade >18 && slct.Grade <=20)
                        {
                            cout<<RankCtr<<". "<<slct.Firstname<<" "<<slct.Lastname<<string(5 , ' ')<<"A"<<endl;
                        }
                        else if (slct.Grade >15 && slct.Grade <=18)
                        {
                            cout<<RankCtr<<". "<<slct.Firstname<<" "<<slct.Lastname<<string(5 , ' ')<<"B"<<endl;
                        }
                        else if (slct.Grade >12 && slct.Grade <=15)
                        {
                            cout<<RankCtr<<". "<<slct.Firstname<<" "<<slct.Lastname<<string(5 , ' ')<<"C"<<endl;
                        }
                        else if (slct.Grade >10 && slct.Grade <=12)
                        {
                            cout<<RankCtr<<". "<<slct.Firstname<<" "<<slct.Lastname<<string(5 , ' ')<<"D"<<endl;
                        }
                        else if (slct.Grade >=0 && slct.Grade <=10)
                        {
                            cout<<RankCtr<<". "<<slct.Firstname<<" "<<slct.Lastname<<string(5 , ' ')<<"E"<<endl;
                        }

                        RankCtr ++ ;
                    }
                }
            }
        }
        else if(Getter.size() == 2 && "help" == Getter[1])                              //Show help
        {
            cout << setw(35) << left   << "Welcome, our program work with CLs(Command LineS) that you will Enter"<<endl;
            cout << setw(35) << left   << "don't forget to add \"basu \" before these CLs"<<endl;
            cout << setw(35) << left   << "DB : DataBase \n"<<endl<<setfill('.');
            cout << setw(35) << left   << " add class <fileName>"     <<setw(10)<<" This is to add a class to program DB from your file name\n";
            cout << setw(35) << left   << " remove class <Class Name>"<<setw(10)<<" This is for remove class from our DB"<<endl;
            cout << setw(35) << left   << " add student"              <<setw(10)<<" This is for add student to selected class"<<endl;
            cout << setw(35) << left   << " remove student <ID>"      <<setw(10)<<" This is for remove a student by It's ID"<<endl;
            cout << setw(35) << left   << " select class <Class Name>"<<setw(10)<<" This will Select a class to do works"<<endl;
            cout << setw(35) << left   << " select none"              <<setw(10)<<" This is for that you don't want any class selected"<<endl;
            cout << setw(35) << left   << " search <ID>"              <<setw(10)<<" This is for search for a student by It's Id"<<endl;
            cout << setw(35) << left   << " search <Full Name>"       <<setw(10)<<" This is for search for a student by It's Name and Family"<<endl;
            cout << setw(35) << left   << " show"                     <<setw(10)<<" It will Show You selected class students"<<endl;
            cout << setw(35) << left   << " show <Class Name>"        <<setw(10)<<" It Will Show you the class you want"<<endl;
            cout << setw(35) << left   << " sort name"                <<setw(10)<<" It will sort a class members by their LName"<<endl;
            cout << setw(35) << left   << " sort id"                  <<setw(10)<<" It will sort a class members by their ID"<<endl;
            cout << setw(35) << left   << " exit"                     <<setw(10)<<" It Will end the program"<<endl;
            cout << setw(35) << left   << " basu history"             <<setw(10)<<" It's very good you want what you did from first to now"<<endl;
        }
        else                                                                            //incorrect CLs
        {
            if (WTDs != "\n" && WTDs != "\r\n" && 0 != WTDs.size())                     //This will check for incorrect Enter
                cout<<"Please enter correct CommandLine !"<<endl;
        }
    }
}
