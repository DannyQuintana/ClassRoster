#pragma once
#include <iostream>
#include<iomanip>
#include <string>
#include "degree.h"
using namespace std;

/*
	D1 and D2 Student class
	This file combined with student.cpp are attempting to meet requirements for D1 and D2.
	variables have been assigned, mutator/accessors, print function and
	constructors have been used and demonstrated.
*/


class Student
{
public:
	const static int numDays = 3; //this is used to set the array size numberOfDaysInCourse.
	
	//setting variables
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysInCourse[numDays];
		DegreeProgram degree;

	public:

		//constructors parameters and no parameterless.
		Student();
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degree);
		
		//destructor 
		~Student(); 

		//Setters/mutators
		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmailAddress(string emailAddress);
		void setAge(int age);
		void setDaysInCourse(int daysInCourse[]);
		void setDegree(DegreeProgram degree);

		//getters/accessors
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmailAddress();
		int getAge();
		int* getDaysInCourse();
		DegreeProgram getDegree();

		//Additional function 
		void print();
};

