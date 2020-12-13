#include "roster.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void main() {
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Kyle,Heckard,khecka2@wgu.com,25,90,45,45,SOFTWARE"};

	int numStudents = size(studentData);

	cout << "Class Roster" << endl;
	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 001058397" << endl;
	cout << "Name: Kyle Heckard" << endl;
	cout << endl;
	cout << "DONE.";
	cout << endl;

	Roster* classRoster = new Roster(numStudents);
	
	for (int i = 0; i < numStudents; i++) {
		classRoster->parseThenAdd(studentData[i]);
	}

	classRoster->printAll();
	cout << endl;

	classRoster->printInvalidEmails();
	cout << endl;
	
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudent(i)->getStudentID());
	}
	cout << endl;

	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster->remove("A3");
	cout << endl;

	classRoster->remove("A3");

	delete classRoster;

	cout << "DONE.";

	return;
}

// Constructors *********************************

Roster::Roster() {
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) {
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[capacity];
}

Roster::~Roster() {}

// Manipulators *********************************

void Roster::parseThenAdd(string studentData) {
	istringstream inSS(studentData);

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	string age;
	string daysInCourse1;
	string daysInCourse2;
	string daysInCourse3;
	string degree;
	int    intAge;
	int	   intDIC1;
	int	   intDIC2;
	int    intDIC3;
	Degree degreeType;

	if (lastIndex < capacity) {
		lastIndex++;

		getline(inSS, studentID, ',');
		getline(inSS, firstName, ',');
		getline(inSS, lastName, ',');
		getline(inSS, emailAddress, ',');
		getline(inSS, age, ',');
		getline(inSS, daysInCourse1, ',');
		getline(inSS, daysInCourse2, ',');
		getline(inSS, daysInCourse3, ',');
		getline(inSS, degree);

		intAge = stoi(age.substr());
		intDIC1 = stoi(daysInCourse1.substr());
		intDIC2 = stoi(daysInCourse2.substr());
		intDIC3 = stoi(daysInCourse3.substr());

		if (degree == "SECURITY") { degreeType = SECURITY; }
		else if (degree == "NETWORK") { degreeType = NETWORKING; }
		else if (degree == "SOFTWARE") { degreeType = SOFTWARE; }
		else {
			cerr << "Invalid degree type. Exiting software\n";
			exit(-1);
		}

		add(studentID, firstName, lastName, emailAddress,
			intAge, intDIC1, intDIC2, intDIC3, degreeType);
	}
	else {
		cerr << "Error. List has exceeded max capacity\n Exiting Program";
		exit(-1);
	}

	return;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {

	int daysInCourse[Student::daysCompleteArraySize];
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;
	if (degree == SECURITY) {
		classRosterArray[lastIndex] = new SecurityStudent(studentID,
			firstName, lastName, emailAddress, age, daysInCourse, degree);
	}
	else if (degree == NETWORKING) {
		classRosterArray[lastIndex] = new NetworkStudent(studentID,
			firstName, lastName, emailAddress, age, daysInCourse, degree);
	}
	else {
		classRosterArray[lastIndex] = new SoftwareStudent(studentID,
			firstName, lastName, emailAddress, age, daysInCourse, degree);
	}

	return;
}

void Roster::remove(string studentID) {
	bool found = false;

	cout << "Removing " << studentID << endl;
	cout << endl;
	for (int i = 0; i <= this->lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			delete this->classRosterArray[i];
			if (i != lastIndex) {
				while (i < lastIndex) {
					this->classRosterArray[i] = this->classRosterArray[i + 1];
					i++;
				}
			}
			this->lastIndex--;
			break;
		}
	}

	if (found == false) {
		cout << "The student with the ID: ";
		cout << studentID << " was not found." << endl;
	}
	else {
		for (int i = 0; i <= this->lastIndex; i++) {
			this->classRosterArray[i]->print();
		}
	}

	return;
}

Student* Roster::getStudent(int index) {
	return classRosterArray[index];
}

// Prints ***************************************

void Roster::printAll() {

	cout << "Displaying all students:" << endl;
	for (int i = 0; i <= this->lastIndex; i++) {
		this->classRosterArray[i]->print();
	}

	return;
}

void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;
	
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			int* d = classRosterArray[i]->getDaysToCompleteCourse();
			cout << "Sudent ID: " << studentID << ", averages ";
			cout << (d[0] + d[1] + d[2]) / 3 << " days in course.";
			cout << endl;
		}
	}

	return;
}

void Roster::printInvalidEmails() {
	string emailAddress = "";
	int    index = -1;

	cout << "Displaying invald emails" << endl;
	cout << endl;
	for (int i = 0; i <= lastIndex; i++) {
		emailAddress = this->classRosterArray[i]->getEmailAddress();
		index = emailAddress.find(' ');
		if (index != string::npos) {
			cout << emailAddress << " - no spaces allowed.";
			cout << endl;
		}
		index = emailAddress.find('.');
		if (index == string::npos) {
			cout << emailAddress << " - missing a period.";
			cout << endl;
		}
		index = emailAddress.find('@');
		if (index == string::npos) {
			cout << emailAddress << " - missing an @ symbol.";
			cout << endl;
		}
	}

	return;
}

void Roster::printByDegreeProgram(Degree degreeProgram) {

	cout << "Showing students in degree program: ";
	cout << degreeStrings[degreeProgram] << endl;
	cout << endl;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			this->classRosterArray[i]->print();
		}
	}

	return;
} 