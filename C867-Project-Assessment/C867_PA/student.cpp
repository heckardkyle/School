#include "student.h"
#include <iostream>
#include <string>
using namespace std;

// Default Constructor
Student::Student() {

	firstName    = "";
	lastName     = "";
	emailAddress = "";
	for (int i = 0; i < daysCompleteArraySize; i++) {
		this->daysToCompleteCourse[i] = 0;
	}

	return;
}

// Overload Constructor
Student::Student(string studentID, string firstName, string lastName,
	string emailAddress, int age, int daysToCompleteCourse[]) {

	this->studentID    = studentID;
	this->firstName    = firstName;
	this->lastName     = lastName;
	this->emailAddress = emailAddress;
	this->age          = age;
	for (int i = 0; i < daysCompleteArraySize; i++) {
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	}

	return;
}

// Destructor
Student::~Student() {}

// Getters ***************************************

string Student::getStudentID() {
	return this->studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmailAddress() {
	return this->emailAddress;
}

int Student::getAge() {
	return this->age;
}

int* Student::getDaysToCompleteCourse() {
	return this->daysToCompleteCourse;
}

// Setters ***************************************

void Student::setStudentID(int studentID) {
	this->studentID = studentID;
	return;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
	return;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
	return;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
	return;
}

void Student::setAge(int age) {
	this->age = age;
	return;
}

void Student::setDaysToCompleteCourse(int daysToCompleteCourse[]) {
	for (int i = 0; i < daysCompleteArraySize; i++) {
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	}
	return;
}

// Print *****************************************

void Student::print() {
	cout <<                      getStudentID() << "\t";
	cout << "First Name: "    << getFirstName() << "\t";
	cout << "Last Name: "     << getLastName()  << "\t";
	cout << "Age: "           << getAge()       << "\t";
	cout << "daysInCourse: {";
		for (int i = 0; i < daysCompleteArraySize; i++) {
			cout << this->daysToCompleteCourse[i];
			if (i == (daysCompleteArraySize - 1)) { cout << "} "; }
			else { cout << ", "; }
		}
	cout << "Degree Program: ";

	return;
}