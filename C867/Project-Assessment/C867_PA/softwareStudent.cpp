#include "softwareStudent.h"
#include <iostream>
#include <string>
using namespace std;

// Subclass Default Constructor
SoftwareStudent::SoftwareStudent() :Student() {
	this->degreeType = Degree::SOFTWARE;
}

// Subclass Overload Constructor
SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName,
	string emailAddress, int age, int daysToCompleteCourse[], Degree degreeType)
	: Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourse)
{
	this->degreeType = Degree::SOFTWARE;
}

// Subclass Destructor
SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
}

// Getter
Degree SoftwareStudent::getDegreeProgram() {
	return this->degreeType;
}

// Print
void SoftwareStudent::print() {
	this->Student::print();
	cout << "SOFTWARE" << endl;
}