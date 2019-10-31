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

void SelectClass(string ClassName)                                                      //This will select a class
{
    Selected = ClassName;
    if (ClassName != "") cout<< ClassName <<" is Selected!"<<endl;                      //Notice that class selected
}
void AddClass(string FileName)                                                          //This will add a class
{
    Class Cclass;                                               //After deceleration we have a class
    ifstream AddClassFM;                                        //Adding Class File Manager
    AddClassFM.open(FileName.c_str());                          //Opening File

    if (!AddClassFM){                                           //Error for Not opening
        cerr << "Error while opening your file" << endl;
        return;
    }
    getline(AddClassFM , Cclass.ClassName);                     //Get class Name
    AddClassFM >> Cclass.Capacity;                              //Get class Capacity
    float ClassSum = 0;                                         //Sum of students grade for class average
    while(!AddClassFM.eof()){                                   //Get Students
        Student Daneshju;                                       //Student var created
        AddClassFM >> Daneshju.Firstname >> Daneshju.Lastname;
        string Birth;                                           //Birthday string created
        AddClassFM >> Birth;                                    //Read birthday string
        Daneshju.Birthday.Year= (unsigned short int) stoi(Birth.substr(0,4));
        Daneshju.Birthday.Month = (unsigned short int) stoi(Birth.substr(5,2));
        Daneshju.Birthday.Day = (unsigned short int) stoi(Birth.substr(8,2));
        AddClassFM >> Daneshju.Grade >> Daneshju.ID;
        ClassSum += Daneshju.Grade;
        Cclass.Data.push_back(Daneshju);
    }
    Cclass.Average = ClassSum / Cclass.Capacity;
    AddClassFM.close();                                         //Close The File
    Database.push_back(Cclass);                                 //Add class to DB
    cout<< "Class that is in file "<<FileName<<" Added"<<endl;
}
void RemoveClass(string ClassName)                                                      //This will remove a class
{
    int Counter = 0;                                            //This will find class place in DB vector
    for (Class &WillRmv : Database){
        if(ClassName == WillRmv.ClassName) break;
        Counter++;
    }
    Database.erase(Database.begin() + Counter);                 //Remove class from DB
    cout<< "Class "<<ClassName<<" Removed"<<endl;
}
void AddStudent(string NF, Date B, unsigned long long int ID1, float G)                 //This will add a student
{
    Student S;                                                  //Student var created
    S.Firstname = NF.substr(0,5);
    S.Lastname = NF.substr(6,7);
    S.Birthday = B;
    S.ID = ID1;
    S.Grade = G;
    while ("" == Selected)                                      //Check class of student who will add
    {
        cout << "Please choose that this student will add to what class : ";
        cin >> Selected;
    }
  	for (Class &Class : Database)
    {                                                           //change class Information related to student
        if (Class.ClassName == Selected) {
            Class.Data.push_back(S);
            float Sum = (Class.Average * Class.Capacity);
            Class.Capacity += 1;
            Class.Average = (Sum + S.Grade) / (Class.Capacity);
          	break;
        }
    }
    cout<< "Your student have added successfully"<<endl;
}
void RemoveStudent(unsigned long long int ID1)                                          //This will remove a student
{
    for(Class &i : Database){                           //Search for student who will remove
        for(int j = 0; j < i.Data.size(); j++) {
            if(i.Data[j].ID == ID1)                     //Check for ID
            {
                float Sum = i.Average * i.Capacity;
                Sum -= i.Data[j].Grade;
                i.Data.erase(i.Data.begin() + j);
                i.Capacity -= 1;
                i.Average = Sum / i.Capacity;
            }
        }
    }
    cout << "Student with Id : "<<ID1<<" Removed successfully!"<<endl;
}

void Search(unsigned long long int ID1)                                                 //This id for search by ID
{
  	for(Class &i : Database)
    {
        for(Student &j : i.Data)
        {
            if (j.ID == ID1)
            {
                cout << "Student with ID "<<ID1<<" is : "<<endl;
                cout<< "Name and Family : "<<j.Firstname<<" "<<j.Lastname<<endl;
                cout<< "Born : "<< j.Birthday.Year<<"/"<<j.Birthday.Month<<"/"<<
                j.Birthday.Day<<"    and with Grade : "<<j.Grade;
            }
        }
    }
}
void Search(string Name, string Last)                                                   //This id for search by Name and Family
{
  	for(Class &j : Database)
    {
        for(Student &i : j.Data)
        {
            //cout << Name <<"="<<i.Firstname<<"   "<<Last<< "="<<i.Lastname<<endl;
            if (Name == i.Firstname && Last == i.Lastname)
            {
                cout<< "Student with Name and Family "<<i.Firstname<<" "<<i.Lastname;
                cout << " is : \nID "<<i.ID;
                cout<< "    Born : "<< i.Birthday.Year<<"/"<<i.Birthday.Month<<"/"<<
                i.Birthday.Day<<"    with Grade : "<<i.Grade<<endl;
                cout<<"Student is in class "<<j.ClassName<<endl;
            }
        }
    }
}
void ShowClass(string Cls)                                                              //This will show selected or all class
{
    if ("" == Selected && "" == Cls)
    {
        int ClsCntr = 1;                            //Class counter for have a numbered list
        int StdCntr = 1;                            //Student counter for have a numbered list
        for(Class &i : Database)
        {
            StdCntr = 1;
            cout <<ClsCntr<<") "<<i.ClassName<<" :\n"<<endl;
            for(Student &j : i.Data)
            {
                if (StdCntr < 10) cout << " ";
                cout <<StdCntr<<". "<<j.Firstname<<" " <<j.Lastname<< endl;
                StdCntr ++ ;
            }
            ClsCntr ++ ;
            cout<< endl <<string(30 , '-') << endl ;
        }
    }
    else
    {
        for(Class &i:Database)
        {
            if(i.ClassName == Cls)
            {
                cout<< "The Selected Class is "<<i.ClassName<<" And have "<<
                i.Capacity << " Student.\nClass average is : "<< i.Average<<endl;
                cout<<"Do You Want See Class Students Name ?(Y/n)";                     //We want that your screen not be busy so ask about some prints(cout)
                char Checker;                                                           //This character is your answer Var
                cin>> Checker;
                while(1)                                                                //Check for correct answer
                {                                                                       /*Anyone who has never made a mistake, has never tried anything new  "Albert Enistein"*/
                    if('Y'!=Checker && 'n'!=Checker)
                    {
                        cout<<"Please Enter Y or n(Be Careful about big or small letters)";
                        continue;
                    }
                    if('Y'==Checker)
                    {
                        int counter = 1;
                        for(Student &j : i.Data)
                        {
                            cout <<counter<<". " <<j.Firstname<< " "<<j.Lastname;
                            if(counter%3==0) cout<<endl;
                            else cout<<string(5 , ' ');
                            counter ++;
                        }
                        cout << endl;
                        break;
                    }
                    if('n'==Checker)
                        return;
                }
            }
        }
    }
}

void SortByName()                                                                       //This will sort selected class by Family
{
  	for(Class &i : Database)
    {
      	if (i.ClassName == Selected)
        {
            for (int j = 0; j < i.Data.size() - 1; j++)
            {
                for (int k = 0; k < i.Data.size() - j - 1; k++)
                {
                    if(i.Data[k].Lastname > i.Data[k + 1].Lastname)
                    {
                        Student Temp;
                        Temp = i.Data[k];
                        i.Data[k] = i.Data[k+1];
                        i.Data[k+1] = Temp;
                    }
                }
            }
            cout << "Class "<<Selected<<" after sort by LName :"<<endl;
            int counter = 1;                                                //Again for a numbered list
            for(Student &j : i.Data)
            {

                if (counter < 10) cout << " ";
                cout<<counter<<". "<<j.Firstname<<" "<<j.Lastname<<string(5 , ' ')<<j.ID<<endl;
                counter ++;
            }
        }
    }


}
void SortById()                                                                         //This will sort selected class by Id
{
    for(Class &i : Database)
    {
      	if (i.ClassName == Selected)
        {
            for (int j = 0; j < i.Data.size() - 1; j++)
            {
                for (int k = 0; k < i.Data.size() - j - 1; k++)
                {
                    if(i.Data[k].ID > i.Data[k + 1].ID)
                    {
                        Student Temp;
                        Temp = i.Data[k];
                        i.Data[k] = i.Data[k+1];
                        i.Data[k+1] = Temp;
                    }
                }
            }
            cout << "Class "<<Selected<<" after sort by ID :"<<endl;
            int counter = 1;
            for(Student &j : i.Data)
            {
                if (counter < 10) cout << " ";
                cout<<counter<<". "<<j.Firstname<<" "<<j.Lastname<<string(5 , ' ')<<j.ID<<endl;
                counter ++;
            }
        }
    }
}
void Save()                                                                             //This will save DB in Files With Name Mphj<n>.basu
{
    int Counter = 1;
    for (Class i : Database)
    {
        ofstream OutPut;
        OutPut.open(string("ILMphj")+to_string(Counter)+".basu", ios::out | ios::trunc);
        OutPut << i.ClassName << endl;
        OutPut << i.Capacity << endl;
        for (Student &j : i.Data)
        {
            OutPut <<j.Firstname<<" "<<j.Lastname<<" "
            <<j.Birthday.Year<<"/"<<j.Birthday.Month<<"/"
            <<j.Birthday.Day<<" "<<j.Grade<<" "<<j.ID<<endl;
        }
        OutPut.close();
        Counter ++ ;
    }
}

/*Info
        I think every thing is clear and others were defined in comment
        Everything i doesn't comment for example most of Funcs are clear

        But every question just ask me

        Email : Mohammad6Outadi@yahoo.com


*/

