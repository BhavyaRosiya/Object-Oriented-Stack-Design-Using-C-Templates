#include<iostream>
#include <iomanip> 
using namespace std;

#define max_size 5  // SIZE OF STACK

//Colors
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define MAGENTA "\033[35m"

template <class Type> // Class To perform Stack Task for Different Datatypes
class Stack
{
  Type stk[max_size];  // Static Array
  int Top; // Index Of Top Ele
  
  public:
  Stack()     //Default Constructor
  {
    Top = -1;
  }
  
  void push() //Function To Push In Stack
  {
    if(Top == max_size - 1)
    {
      cout <<RED;
      cout <<"|====================|" << endl;
      cout <<"|Stack Is OverFlow   |" << endl;
      cout <<"|====================|" << endl;
      cout <<RESET;
      return;
    }
    
    cout <<"Enter The Data To Push In Stack = "; // Pushing In Stack
    cin >> stk[ ++Top];
    
    cout <<BLUE;
    cout <<"|=================================|" <<endl;
    cout <<"|***** Data Pushed In Stack ***** |" <<endl;
    cout <<"|=================================|" <<endl;
    cout <<RESET;
  }
  
  void pop()          //Function To Pop In Stack
  {
    if(Top <= -1)
    {
      cout <<RED;
      cout <<"|====================|" << endl;
      cout <<"|Stack Is UnderFlow  |" << endl;
      cout <<"|====================|" << endl;
      cout <<RESET;
    }
    else
    {
      cout <<YELLOW;
      cout <<"|==========================================|"<<endl;
      cout <<"| ****** Element Deleted In Stack : ****** |" <<endl; 
      cout <<"| Deleted Element = " << left << setw(23) << stk [ Top-- ] <<"|" <<endl;    // Poping Element From Stack 
      cout <<"|==========================================|" <<endl;
      cout <<RESET;
    }
  }
  
  void display()             // Function To Display In Stack
  {
    if( Top <= -1 )
    {
      cout <<"|===================|" << endl;
      cout <<"|Stack Is Empty     |" << endl;
      cout <<"|===================|" << endl;
    }
    else
    {
      cout <<MAGENTA;
      cout <<"|====================================|" <<endl;
      cout <<"|  ****** ELEMENTS IN STACK ******   |" <<endl;
      for(int i = 0; i <= Top; i++)
      {
        cout <<"| Element = "<< left << setw(25) << stk[i] <<"|"<< endl;
      }
      cout <<"|====================================|" <<endl;
      cout <<RESET;
    }
  }
  
  void reset()            // Function To Reset In Stack
  {
     Top = -1;
  }
}; // CLASS END HERE



template<class T1> // Generic Menu For Diffent Data Types
void StackMenu(const string &typeName)  //To display stack name so string used
{
  int op;
  static Stack <T1> s1; // static used cuz want use same stk object for same datatpe
  static int cnt = 0; // Count How many Times Same DataType Selected
  
  cnt++;
  if(cnt > 1)
  {
    while(1)
    {
       cout <<RED;
       cout <<"|=====================================|"<<endl;
       cout <<"|******* STACK ALREADY EXISTS ******* |" <<endl;
       cout <<"| 1) Continue With Old Stack          |"<<endl;
       cout <<"| 2) New Stack                        |" <<endl;
       cout <<"|=====================================|" <<endl;
       cout <<RESET;
       cout <<"Enter The Choice = ";
       cin >> op;
    
       if(op == 1)
       break;
      
       else if(op == 2)
       {
         s1.reset();
         cout <<MAGENTA;
         cout <<"|================================================|" <<endl;
         cout <<"|******* New Stack Created SuccessFully *******  |" <<endl;
         cout <<"|================================================|" <<endl;
         cout <<RESET;
         break;
       }
       else
       cout <<"Invalid Choice Select 1 or 2" <<endl;
    }
  }
  
  cout <<RED;
  cout <<"[******* " <<typeName <<" Stack Application Ready To Use *******]"<<endl;
  cout <<RESET;
  
  while(1)  // SUB MENU
  {
    cout <<GREEN;
    cout <<"|=========================|"<<endl;
    cout <<"|======= SUB MENU ========|" <<endl;
    cout <<"| 1) PUSH                 |" <<endl;
    cout <<"| 2) POP                  |" <<endl;
    cout <<"| 3) DISPLAY STACK        |" <<endl;
    cout <<"| 4) MAIN MENU            |" <<endl;
    cout <<"|=========================|"<<endl;
    cout <<RESET;
    cout <<"Enter The Sub Menu Option = ";
    cin >> op;
    
    switch(op)
    {
      case 1: s1.push(); break;
      case 2: s1.pop(); break;
      case 3: s1.display(); break;
      case 4: return;
      default : cout <<"******* Enter The Valid Option *******"<<endl;
    }
  }
}



int main()  // MAIN FUNCTION
{
  int op , c = 0;
  
  while(1)
  {
    cout <<MAGENTA;
    cout <<"|================================================|" <<endl;
    cout <<"|======= STACK APPLICATION USING TEMPLATE =======|" <<endl;
    cout <<"| 1) INT                                         |" <<endl;
    cout <<"| 2) CHAR                                        |" <<endl;
    cout <<"| 3) FLOAT                                       |" <<endl;
    cout <<"| 4) DOUBLE                                      |" <<endl;
    cout <<"| 5) STRING                                      |" <<endl;
    cout <<"| 6) EXIT                                        |" <<endl;
    cout <<"|================================================|" <<endl;
    cout <<RESET;
    cout <<"Enter The Option = ";
    cin >> op;
    
    switch(op)
    {
      case 1 : StackMenu<int>("INT"); c = 0; break; // PAssing Int 
      case 2 : StackMenu<char>("CHAR"); c = 0; break; //Passing Char
      case 3 : StackMenu<float>("FLOAT"); c = 0; break; // Passing Float
      case 4 : StackMenu<double>("DOUBLE"); c = 0; break; // Passing Double
      case 5 : StackMenu<string>("STRING"); c = 0; break; // Passing String
      case 6 : return 0;
      default : c++;
               if(c == 1)
               {
                 cout <<RED;
                 cout <<"********************************"<<endl;
                 cout <<"Please Read The Option CareFully" <<endl;
                 cout <<"********************************"<<endl;
                 cout << RESET;
               }
               else if(c == 2)
               {
                 cout <<RED;
                 cout <<"********************************"<<endl;
                 cout <<"Last Chance Please Take Care " << endl;
                 cout <<"********************************"<<endl;
                 cout <<RESET;
               }
               else
               {
                 cout <<RED;
                 cout <<"***************************************"<<endl;
                 cout <<"THANKS For Using Our Application"<<endl;
                 cout <<"Read The Manual And Come Back Properly"<<endl;
                 cout <<"***************************************"<<endl;
                 cout <<RESET;
                 return 0;
               }
               break;
    
    }
  }
}






