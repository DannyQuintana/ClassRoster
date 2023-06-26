#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

/*
	Defintions of functions. Includes a function to parse student data table using the classRosterArray
	in main.
*/

void Roster::parseString(string indexNum)
{

	int rightSide = indexNum.find(","); //will locate the index of "," in the string.
	string ID = indexNum.substr(0, rightSide); // right handSide will hold the index number of ,

	int leftSide = rightSide + 1; // this sets leftSide to the index value of +1 of "," 
	rightSide = indexNum.find(",", leftSide);
	string fName = indexNum.substr(leftSide, rightSide - leftSide);

	leftSide = rightSide + 1; // repeating these 3 lines of codes for each element onthe table
	rightSide = indexNum.find(",", leftSide);
	string lName = indexNum.substr(leftSide, rightSide - leftSide);

	leftSide = rightSide + 1;
	rightSide = indexNum.find(",", leftSide);
	string email = indexNum.substr(leftSide, rightSide - leftSide);

	leftSide = rightSide + 1;
	rightSide = indexNum.find(",", leftSide);
	int age = stoi(indexNum.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1;
	rightSide = indexNum.find(",", leftSide);
	int d1 = stoi(indexNum.substr(leftSide, rightSide - leftSide)); 

	leftSide = rightSide + 1;
	rightSide = indexNum.find(",", leftSide);
	int d2 = stoi(indexNum.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1;
	rightSide = indexNum.find(",", leftSide);
	int d3 = stoi(indexNum.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1;
	rightSide = indexNum.find(",", leftSide);
	string strDegree = indexNum.substr(leftSide, rightSide - leftSide);

	//this if-else branch allows us to parse enums degreeprogram data types. 

	DegreeProgram d = NETWORK; //"SECURITY", "NETWORK", "SOFTWARE"
	if (strDegree == "SECURITY") {
		d = DegreeProgram::SECURITY;
	}
	else if (strDegree == "NETWORK") {
		d = DegreeProgram::NETWORK;
	}
	else if (strDegree == "SOFTWARE") {
		d = DegreeProgram::SOFTWARE;
	}

	add(ID, fName, lName, email, age, d1, d2, d3, d); //call the add function 

 }

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysinCourse1, int daysinCourse2, int daysinCourse3, DegreeProgram degreeprogram)
{	
	// the add function uses a full constructor and also will takes the 3 ints for days in course and combines to a single array  
	int dayArr[3] = { daysinCourse1, daysinCourse2, daysinCourse3 };
	classRosterArray[++indexing] = new Student(studentID, firstName, lastName, emailAddress, age, dayArr, degreeprogram);
}

void Roster::remove(string studentID)
{

	//This will loop through the array and remove parameter 
	bool removed = false;
	for (int i = 0; i <= Roster::indexing; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			removed = true;

			if (i < numRoster - 1)
			{
				Student* hold = classRosterArray[i]; //swap with last student on roster
				classRosterArray[i] = classRosterArray[numRoster - 1];
				classRosterArray[numRoster - 1] = hold;
			}
			Roster::indexing--;
		}
		
	}
	if (removed)
	{
		cout << studentID << " removed from roster" << endl;
	}
	else {
		cout << "The student with " << studentID << " not found." << endl;
	}

}

void Roster::printAll()
{
	cout << "Displaying student Roster." << endl;

	//using for loop to loop through the indices of the array. 
	for (int i = 0; i <= Roster::indexing; i++) {
		classRosterArray[i]->print(); // REVISION calling print() 

	}
	cout << endl;
}

void Roster::printAverageDaysinCourse(string studentID)
{
	for (int i = 0; i <= Roster::indexing; i++) {
		
		if (classRosterArray[i]->getStudentID() == studentID) 
		{
			cout << "Student ID: " << studentID << ", average days in course is: ";
			cout << ((classRosterArray[i]->getDaysInCourse()[0]
				+ classRosterArray[i]->getDaysInCourse()[1]
				+ classRosterArray[i]->getDaysInCourse()[2])
				/ 3) << endl;;
			
		}
	}
}

void Roster::printInvalidEmails()
{
	/*
	This function checks to ensure the string includes @ and a '.' without spaces.
	sampleEmail@sample.com is valid
	sample email@samplecom is invalid
	using find and npos(no position) to check if required/illegal characters are present. 
	*/

	bool check = false;
	cout << "Displaying invalid emails: " << endl << endl;

	for (int i = 0; i <= Roster::indexing; i++)
	{
		string rid = (classRosterArray[i]->getEmailAddress());
		if ( (rid.find('@') == string::npos) || (rid.find('.') == string::npos) || (rid.find(' ') != string::npos) ) {
			
			check = true;
			cout << rid << " - is invalid." << endl;
		}
	}
	if (!check) {
		cout << "No invalid emails." << endl;
	}
	cout << endl << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	cout << "Students in degree program: SOFTWARE" << endl;
	//Display the degree program of the student. 
	for (int i = 0; i <= Roster::indexing; i++) {
		if (Roster::classRosterArray[i]->getDegree() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

Roster::~Roster()
{
	cout << "Desctrutor running.. DONE." << endl;
	for (int i = 0; i < numRoster; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}