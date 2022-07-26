#include "roster.h"
#include <string>
#include <iostream>
using namespace std;

Roster::Roster() {
	classRosterArray[0] = nullptr;
	classRosterArray[1] = nullptr;
	classRosterArray[2] = nullptr;
	classRosterArray[3] = nullptr;
	classRosterArray[4] = nullptr;

	return;
}

Roster::~Roster() {
	cout << "Calling Roster destructor..." << endl << endl;
	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
	}
	return;
}

void Roster::parse(string row) {
	int firstCommaIndex = row.find(',');
	string studentID = row.substr(0, firstCommaIndex);

	int nextStartingIndex = firstCommaIndex + 1;
	int nextCommaIndex = row.find(',', nextStartingIndex);
	string firstName = row.substr(nextStartingIndex, nextCommaIndex - nextStartingIndex);

	nextStartingIndex = nextCommaIndex + 1;
	nextCommaIndex = row.find(',', nextStartingIndex);
	string lastName = row.substr(nextStartingIndex, nextCommaIndex - nextStartingIndex);

	nextStartingIndex = nextCommaIndex + 1;
	nextCommaIndex = row.find(',', nextStartingIndex);
	string emailAddress = row.substr(nextStartingIndex, nextCommaIndex - nextStartingIndex);

	nextStartingIndex = nextCommaIndex + 1;
	nextCommaIndex = row.find(',', nextStartingIndex);
	string ageString = row.substr(nextStartingIndex, nextCommaIndex - nextStartingIndex);
	int age = stoi(ageString);

	nextStartingIndex = nextCommaIndex + 1;
	nextCommaIndex = row.find(',', nextStartingIndex);
	string daysInCourse1String = row.substr(nextStartingIndex, nextCommaIndex - nextStartingIndex);
	int daysInCourse1 = stoi(daysInCourse1String);

	nextStartingIndex = nextCommaIndex + 1;
	nextCommaIndex = row.find(',', nextStartingIndex);
	string daysInCourse2String = row.substr(nextStartingIndex, nextCommaIndex - nextStartingIndex);
	int daysInCourse2 = stoi(daysInCourse2String);

	nextStartingIndex = nextCommaIndex + 1;
	nextCommaIndex = row.find(',', nextStartingIndex);
	string daysInCourse3String = row.substr(nextStartingIndex, nextCommaIndex - nextStartingIndex);
	int daysInCourse3 = stoi(daysInCourse3String);

	nextStartingIndex = nextCommaIndex + 1;
	nextCommaIndex = row.find(',', nextStartingIndex);
	string degreeProgramString = row.substr(nextStartingIndex, nextCommaIndex - nextStartingIndex);
	DegreeProgram degreeprogram;
	if (degreeProgramString == "SECURITY") {
		degreeprogram = DegreeProgram::SECURITY;
	}
	else if (degreeProgramString == "NETWORK") {
		degreeprogram = DegreeProgram::NETWORK;
	}
	else if (degreeProgramString == "SOFTWARE") {
		degreeprogram = DegreeProgram::SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
			break;
		}
	}
}

void Roster::printAll() {

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
	}
	cout << endl << endl;
}

void Roster::printInvalidEmails() {
	cout << "Invalid Email List:" << endl;

	for (int i = 0; i < 5; i++) {
		bool isValidEmail;
		string emailToCheck = classRosterArray[i]->GetEmail();
		int indexOfAt = emailToCheck.find('@');
		int indexOfPeriod = emailToCheck.find('.');
		int indexOfSpace = emailToCheck.find(' ');

		if (indexOfAt > 0) {
			isValidEmail = true;
			if (indexOfPeriod > 0) {
				isValidEmail = true;
				if (indexOfSpace > 0) {
					isValidEmail = false;
				}
				else {
					isValidEmail = true;
				}
			}
			else {
				isValidEmail = false;
			}
		}
		else {
			isValidEmail = false;
		}

		if (!isValidEmail) {
			cout << emailToCheck << endl;
		}
	}

	cout << endl << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
	string studentIdToCheck;
	double avgDaysInCourse;

	for (int i = 0; i < 5; i++) {
		studentIdToCheck = classRosterArray[i]->GetStudentID();
		if (studentIdToCheck == studentID) {
			int totalDaysInCourse = classRosterArray[i]->GetDaysInCourse1() + classRosterArray[i]->GetDaysInCourse2() + classRosterArray[i]->GetDaysInCourse3();
			avgDaysInCourse = totalDaysInCourse / 3.0;
		}
	}

	cout << "Average days in course for Student ID " << studentID << ": " << avgDaysInCourse << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	DegreeProgram degreeToCheck;

	cout << "Students by degree program: " << degreeProgram << endl;

	for (int i = 0; i < 5; i++) {
		degreeToCheck = classRosterArray[i]->GetDegreeProgram();
		if (degreeToCheck == degreeProgram) {
			classRosterArray[i]->Print();
		}
	}
	cout << endl << endl;
}

void Roster::remove(string studentID) {
	string studentIdToCheck;
	bool studentIdFound = false;

	cout << "Deleting Student ID: " << studentID << endl;
	try {
		for (int i = 0; i < 5; i++) {
			if (classRosterArray[i] != nullptr) {
				studentIdToCheck = classRosterArray[i]->GetStudentID();
				if (studentIdToCheck == studentID) {
					classRosterArray[i] = nullptr;
					studentIdFound = true;
					cout << endl << endl;
				}
			}
		}
		if (!studentIdFound) {
			throw runtime_error("The following Studuent ID was not found: ");// << endl << endl << endl;
		}
	}
	catch (runtime_error& excpt) {
		cout << excpt.what() << studentID << endl << endl << endl;
	}
}