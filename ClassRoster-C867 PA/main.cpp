#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "roster.h"
#include "student.h" 
using namespace std;

int main()
{	
	//F.1 print out course and student information
	cout << "Scripting and Programming Applications - C867\n";
	cout << "Programming Language: C++\n";
	cout << "Student ID: 001214053\n";
	cout << "Name: Daniel Quintana";
	cout << endl << endl << endl; 
	
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Daniel,Quintana,dquin39@wgu.edu,31,20,30,40,SOFTWARE"
	}; // The dataTable has been modified requirement A 

	const int numStudents = 5;
	//F.2 creating a class of Roster
	Roster classRoster;

	//E.2 and F.3 parsing all data from studentData to classRoster
	for (int i = 0; i < numStudents; i++) {
		classRoster.parseString(studentData[i]);
	}
	
	//F4
	classRoster.printAll();
	classRoster.printInvalidEmails();
	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysinCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster.remove("A3");
	cout << endl;
	
	classRoster.printAll();
	cout << endl;

	classRoster.remove("A3");
	cout << endl;

	return 0;
}


