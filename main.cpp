; 
/* 
Name: Lucy Ayala
Date: 02/10/2020 IDE: Repl.it tool 
This program display's employee's weekly pay.
*/  
#include <iostream>
#include <iomanip>
#include <locale>
#include <string>
using namespace std;

// function prototype
double weeklyPay(double, double, string, int); 
void upper (string); // function to convert output to uppercase
void lower (string); //functiont to convert output to lowercase

//*****************************************************************************************
int main( )
{   
//declare and initalize variables 
string st1 = "TCC-TR IS COOL";
string st2 = "i will succeed at c++";
//Displays upper and lowercase variables
upper(st2);
cout << endl; 
lower(st1);

 cout << showpoint << fixed << setprecision (2);
         //a function call for each person - no input from the console for part 1
        
         cout << "\n" << weeklyPay (47, 505.75,"Lucy: ",2)  << endl;
         cout << "\n" << weeklyPay (45, 55.25,"Melivin: ",2) << endl;
         cout << "\n" << weeklyPay (15, 65.25,"Susan: ",1) << endl;
         cout << "\n" << weeklyPay (41, 14.75,"Mika: ",2) << endl;
         cout << "\n" << weeklyPay (25, 15.0,"Eldridge: ",1) << endl;
         cout << "\n" << weeklyPay (55,203.50,"Freedom: ",2) << endl;
         cout << "\n" << weeklyPay (32.5, 100.25,"Tyson: ",2) << endl;

  return 0;
}

//****************************************************************************************
double weeklyPay(double hours, double rate, string name, int empType)
{// complete the function definition

   //Declared and initialized variables
   double netPay = 0.0, grossPay= 0.0, taxableWages= 0.0, Taxes= 0.0, overTimeHours = 0.0,
   overTimeMoney = 0.0, FIT = 0.0, SST = 0.0, Medi = 0.0;
   

//color constants
const string colorRed = "\033[31m";
const string colorGreen = "\033[32m";
const string colorBlue = "\033[34m";
const string colorPurple = "\033[35m";
const string colorReset = "\033[0m";
//-------------------
locale loc; //Displays employe's name in all caps
cout << colorRed << endl;
       for(int i = 0; i < name.length(); i++)
     {
         cout << toupper(name[i], loc) ; 
     }
cout << colorReset;
//-----------------
  if (empType == 2) //FullTime eployee's
  {   //constant variables 
      const double regularHours = 40, Dental = 17.00, Retirement= 77.00;
      
        if( hours > 40) //OverTime employee's
        {
          const double regularHours = 0.0;
          grossPay = 40 * rate;
          overTimeHours = hours-40;
          overTimeMoney = (overTimeHours * (rate * 2 ));
          grossPay = overTimeMoney + grossPay; // Overtime pays 2x regular rate
        }
        else
        {
          grossPay = hours *rate;
        }
  
   taxableWages = (grossPay - Dental)- Retirement; // Dental and Retirement deducation

      if (rate <15)// 12% FIT rate where hourtly rate is <15
      {
         FIT = (taxableWages *.12);
      }
      else
      { 
        FIT = (taxableWages *.15);
      }
      //Calculates, Social Secutiry Taxes, Medicare Taxes
        SST = (grossPay *.062);
        Medi = (grossPay *.0145);
        Taxes = FIT +SST+ Medi;
        netPay = taxableWages - Taxes;

      //Display's output 
      cout << "\nStatus: Full Time";
      cout << colorPurple << "\nGross Pay:" << colorReset << "$" << grossPay;
      cout << setw(20) << "OverTime worked: " << overTimeHours << "\nRegular Rate: " << rate << setw(25) << "Overtime Rate: "<< 
      (rate *2) << endl;
      cout << "Dental Deduction:$ " << Dental << setw(28) <<  "Retirement Deduction:$ " << Retirement; 
      cout << colorGreen << "\nTaxable Wages Total: " << colorReset << "$" << taxableWages; 
      cout << "\nFederal Income Tax: $" << FIT;
      cout << "\nSocial Security Taxes: $" << SST;
      cout << "\nMedicare Taxes:$ " << Medi;
       
    }
    else if (empType == 1)//PartTime employee's 
    {
      grossPay= rate * hours;      
      if(rate < 15) // 12% FIT rate where hourtly rate is <15
        {
         FIT = (grossPay *.12);
        }
      else 
      {
       FIT = (grossPay *.15); 
      }
      //Calculates Taxes
      SST = (grossPay *.062);
      Medi = (grossPay *.0145);
      Taxes = FIT +SST+ Medi;
      netPay = grossPay - Taxes;
     //Display's output to the screen  
      cout << "\nStatus: Part Time";
      cout << colorPurple << "\nGross Pay:" << colorReset << "$" << grossPay;
      cout << "\nRegular hours worked: " << hours<< "\nRegular Rate: " << rate; 
      cout << "\nFederal Income Tax: $" << FIT;
      cout << "\nSocial Security Taxes: $" << SST;
      cout << "\nMedicare Taxes:$ " << Medi;
    }

 cout << colorBlue << "\nNet Pay:" << colorReset << "$"; //Displays the word Net pay
  return netPay; //returns netpay back to the function call
}

//***************************************************************************************
void upper (string cool ) //Definition Function for uppercase words
{
locale loc;
  for (int i=0; i < cool.length (); i++)
  {
    cout << toupper (cool[i], loc);
  }
}

//****************************************************************************************
void lower (string succeed) // Definition Function for lowercase words
{
  locale loc;
  for (int i=0; i < succeed.length (); i++)
  {
    cout << tolower (succeed[i], loc);
    
  }
}