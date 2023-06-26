#include<iostream>
#include<string>
#include "student.h"
using namespace std;

/*
	D2
	The student.cpp file covers D2. each variable has an instance of a getter and setters functions.
	Constructors with and without parameters defined.  
	Print function has also been defined. 

*/

Student::Student() //Setting paramters on this constructor using this-> pointer to "point" to variable.
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;

	//Using for loop to initialize array numberOfDaysInCourse setting values to 0. 
	for (int i = 0; i < numDays; i++) 
	{ 
			this->daysInCourse[i] = 0; 
	}

	//Defaul to Network
	this->degree = DegreeProgram::NETWORK;

}

Student::Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourse[], DegreeProgram Degree)
{
	this->studentID = StudentID;
	this->firstName = FirstName;
	this->lastName = LastName;
	this->emailAddress = EmailAddress;
	this->age = Age;
	
	//As with the parameterless constructor using a for loop to initialize array but now reference the parameter in full constructor.
	for (int i = 0; i < numDays; i++) 
	{ 
		this->daysInCourse[i] = DaysInCourse[i]; 
	}
	this->degree = Degree;

}

Student::~Student() {} //included but do not need it. here for good practice. 

//Getters 
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegree() { return this->degree; }


//Setters kept on single line for readability. 
void Student::setStudentID(string StudentID) {studentID = StudentID;}
void Student::setFirstName(string FirstName) {firstName = FirstName;}
void Student::setLastName(string LastName) {lastName = LastName;}
void Student::setEmailAddress(string EmailAddress) {emailAddress = EmailAddress;}
void Student::setAge(int Age) {age = Age;}

void Student::setDaysInCourse(int daysInCourse[])
{
	//loops through the 3 numbers per course. 
	for (int i = 0; i < numDays; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}
void Student::setDegree(DegreeProgram Degree){this->degree = Degree;}



//printing function to be used to present to console. 
void Student::print()
{
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << "{" << this->getDaysInCourse()[0] << ",";
	cout << this->getDaysInCourse()[1] << ",";
	cout << this->getDaysInCourse()[2] << "}" << '\t';
	cout << degreeString[this->getDegree()] << endl;
}
