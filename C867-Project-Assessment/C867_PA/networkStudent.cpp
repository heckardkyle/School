#include "networkStudent.h"
#include <iostream>
#include <string>
using namespace std;

// Subclass Default Constructor
NetworkStudent::NetworkStudent() :Student() {
	this->degreeType = Degree::NETWORKING;
}

// Subclass Overload Constructor
NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName,
	string emailAddress, int age, int daysToCompleteCourse[], Degree degreeType)
	: Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourse)
{
	this->degreeType = Degree::NETWORKING;
}

// Subclass Destructor
NetworkStudent::~NetworkStudent() {
	Student::~Student();
}

// Getter
Degree NetworkStudent::getDegreeProgram() {
	return this->degreeType;
}

// Print
void NetworkStudent::print() {
	this->Student::print();
	cout << "NETWORKING" << endl;
}