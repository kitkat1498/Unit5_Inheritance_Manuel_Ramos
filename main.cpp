/* By Manuel Ramos
Date: 10/10/2019 
Professor: Dr. Tyson McMillan 
School: Tarrant County College 
Assignment: Create a way to find the total cost of a 60 hour degree.
Lesson: Learned how to initialize a program from a spreadsheet.
*/

#include <iostream>
#include <string>
#include "Input_Validation_Extended.h"

using namespace std;


class Semester
{
  protected:
    static const int hourClass = 3; //Hours per class
    static const int monthSem = 4; //Months in a Semester
    static const int semYear = 3; //Semesters in a year
    static const int hoursDegree = 120; // Hours in a degree
    //changeable settings (setters and getters)
    double costHour; //cost per credit hour
    double bookClass; //book cost per class
    double roomMonth; //Room and Board cost per roomMonth
    double foodMonth; //Food cost per Month
    double travelMonth; //Travel cost per Month
    int hourDegree; //Hours in a degree
    int hoursTaken; //hours taken by the student
    string schoolName; //School name
    
  public:
    Semester()
    {
      costHour = 64.00;
      bookClass = 100.00;
      roomMonth = 1000.00;
      foodMonth = 150.00;
      travelMonth = 90.00;
      hourDegree = 60;
      hoursTaken = 0;
      schoolName = "TCC";
      
    }
    Semester(double cH,double bC, double rM, double fM, double tM, int hD, int hT,string sN) : costHour(cH),bookClass(bC),roomMonth(rM),foodMonth(fM),travelMonth(tM),hourDegree(hD),hoursTaken(hT),schoolName(sN) {};
    void setCostHour(double cH) {costHour = cH;}
    void setBookClass(double bC) {bookClass = bC;}
    void setRoomMonth(double rM) {roomMonth = rM;}
    void setFoodMonth(double fM) {foodMonth = fM;}
    void setTravelMonth(double tM) {travelMonth = tM;}
    void setHourDegree(int hD) {hourDegree = hD;}
    void setHoursTaken(int hT) {hoursTaken = hT;}
    void setSchoolName(string sN) {schoolName = sN;}
    double getCostHour() const {return costHour;}
    double getBookClass() const {return bookClass;}
    double getRoomMonth() const {return roomMonth;}
    double getFoodMonth() const {return foodMonth;}
    double getTravelMonth() const {return travelMonth;}
    int getHourDegree() const {return hourDegree;}
    int getHoursTaken() const {return hoursTaken;}
    string getSchoolName() const {return schoolName;}
    //calculate tuition cost
    double calculateTuition() {return (hoursTaken * costHour);}
    //calculate room and board cost
    double calculateRoomAndBoard() {return (monthSem * roomMonth);}
    //Calc books cost
    double calculateBookCost() {return (bookClass * (hoursTaken/3));}
    //calc food cost
    double calculateFoodCost() {return (foodMonth * monthSem);}
    //calc travel cost
    double calculateTravelCost() {return (travelMonth * monthSem);}
    //calculate total cost per semester 
    double calculateTotalCostSemester() {return (calculateTuition() + calculateRoomAndBoard() + calculateFoodCost() + calculateTravelCost() + calculateBookCost());}
    //calculate the semesters per 60 hour degree
    int sem60Hours() {return (hoursDegree / hoursTaken);}
    //calculate the total cost of a 60 hour degree
    double total60Hours() {return (calculateTotalCostSemester() * sem60Hours());}
    //calculate the time in years for a 60 hour degree
    double year60Hours() {return (sem60Hours() / semYear);}
    
    
    void showValues()
    {
      cout << "\nSchool Details:" << endl;
      cout << "The school name is: " << getSchoolName() << endl;
      cout << "The tuition cost is: $" << calculateTuition() << endl;
      cout << "The cost of room and board is: $" << calculateRoomAndBoard() << endl;
      cout << "The cost of books is: $" << calculateBookCost() << endl;
      cout << "The cost of travel is: $" << calculateTravelCost() << endl;
      cout << "The cost of food is: $" << calculateFoodCost() << endl;
      cout << "The total cost of a semester is: $" << calculateTotalCostSemester() << endl;
      cout << "The time to complete a 60 hour degree in semesters: " << sem60Hours() << endl;
      cout << "The time to complete a 60  hour degree in years: " << year60Hours() << endl;
      cout << "The total cost of a 60 hour degree: $" << total60Hours() << endl;
      
    }
    void setValues()
    {
      cout << "\nWhat is the school's name? ";
      schoolName=validateString(schoolName);
      cout << "\nWhat is the cost per credit hour? ";
      costHour=validateDouble(costHour);
      cout << "\nWhat is the cost of room and board per month? ";
      roomMonth=validateDouble(roomMonth);
      cout << "\nWhat cost of travel per month? ";
      travelMonth=validateDouble(travelMonth);
      cout << "\nWhat is the cost of food per month? ";
      foodMonth=validateDouble(foodMonth);
      cout << "\nWhat is the cost of books per class? ";
      bookClass=validateDouble(bookClass);

      cout << "\n***UPDATING VALUES***" << endl;

      showValues();
    }
    
};

int main() 
{
  const int hoursFull = 12;
  const int hoursPart = 9;
  const int hoursHalf = 6;
  char yesno = '\0';
  char hoursTaken = '\0';

  Semester Full, Part, Half;

  Full.setHoursTaken(hoursFull);
  Part.setHoursTaken(hoursPart);
  Half.setHoursTaken(hoursHalf);
  Semester FullCollege(hoursFull, 60, 1565.00, 100.00, 1000.00, 150.00, 90.00, "TCU"); 
  Semester PartCollege(hoursPart, 60, 1565.00, 100.00, 1000.00, 150.00, 90.00, "TCU"); 
  Semester HalfCollege(hoursHalf, 60, 1565.00, 100.00, 1000.00, 150.00, 90.00, "TCU"); 
  //show Per semester information
  cout << "\nFull Time College Info: " << endl;
  FullCollege.showValues();
  cout << "\nPart Time College Info: " << endl;
  PartCollege.showValues();
  cout << "\nHalf Time College Info: " << endl;
  HalfCollege.showValues();

  cout << "\nFull Time TCC Info: " << endl;
  Full.showValues();
  cout << "\nPart Time TCC Info: " << endl;
  Half.showValues();
  cout << "\nHalf Time TCC Info: " << endl;
  Part.showValues();
  //show question answers
  


  cout << "\nWould you like to enter your own college information? y/n: ";
  yesno=validateChar(yesno);
  if (yesno=='y')
  {
    cout << "Are you taking Full time, Part time, or Half time classes? f/p/h: ";
    hoursTaken=validateChar(hoursTaken);
    if (hoursTaken=='f')
    {
      Full.setValues();
    }
    else if (hoursTaken=='p')
    {
      Part.setValues();
    }
    else if (hoursTaken=='h')
    {
      Half.setValues();
    }
    else 
    {
      cout << "There was an error, please try again." << endl;
      
    }
  }
  else if (yesno=='n')
  {
    cout << "Have a nice day!";
    return 0;
  }
  else 
  {
    cout << "There was an error, please try again.";
  }
  
  
  return 0;
}