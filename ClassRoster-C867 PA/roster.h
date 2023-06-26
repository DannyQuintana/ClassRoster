#pragma once
#include<iostream>
#include "student.h"
using namespace std;

/*
	E. 
	Header file includes classRosterArray, function definition and deconstructor. 

*/


class Roster {

	public:
		int indexing = -1;
		const static int numRoster = 5; //used to set size of Array
		Student* classRosterArray[numRoster];

	public:
		// deconstructor
		~Roster();

		//functions for  objective E3
		void parseString(string indexNum);
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysinCourse1, int daysinCourse2, int daysinCourse3, DegreeProgram degreeprogram);
		void remove(string studentID);
		void printAll();
		void printAverageDaysinCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeProgram);

};