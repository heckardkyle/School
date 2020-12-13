#include "securityStudent.h"
#include <iostream>
#include <string>
using namespace std;

// Subclass Default Constructor
SecurityStudent::SecurityStudent():Student() {
	this->degreeType = Degree::SECURITY;
}

// Subclass Overload Constructor
SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName,
	string emailAddress, int age, int daysToCompleteCourse[], Degree degreeType)
	: Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourse)
{
	this->degreeType = Degree::SECURITY;
}

// Subclass Destructor
SecurityStudent::~SecurityStudent() {
	Student::~Student();
}

// Getter
Degree SecurityStudent::getDegreeProgram() {
	return this->degreeType;
}

// Print
void SecurityStudent::print() {
	this->Student::print();
	cout << "SECURITY" << endl;
}