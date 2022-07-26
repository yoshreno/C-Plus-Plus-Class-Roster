#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student() {
	studentID = "";
	firstName = "";
	lastName = "";
	email = "";
	age = 0;
	daysInCourse[0] = 0;
	daysInCourse[1] = 0;
	daysInCourse[2] = 0;
	degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[3], DegreeProgram degreeProgram) {
	SetStudentID(studentID);
	SetFirstName(firstName);
	SetLastName(lastName);
	SetEmail(email);
	SetAge(age);
	SetDaysInCourse(daysInCourse[0], daysInCourse[1], daysInCourse[2]);
	SetDegreeProgram(degreeProgram);
}

void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}

void Student::SetEmail(string email) {
	this->email = email;
}

void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetDaysInCourse(int  daysInCourse1, int  daysInCourse2, int  daysInCourse3) {
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmail() const {
	return email;
}

int Student::GetAge() const {
	return age;
}

int Student::GetDaysInCourse1() const {
	return daysInCourse[0];
}

int Student::GetDaysInCourse2() const {
	return daysInCourse[1];
}

int Student::GetDaysInCourse3() const {
	return daysInCourse[2];
}

DegreeProgram Student::GetDegreeProgram() const {
	return degreeProgram;
}

string Student::PrintDegreeValue(DegreeProgram degreeProgram) {
	if (degreeProgram == 0) {
		return "SECURIY";
	}
	else if (degreeProgram == 1) {
		return "NETWORK";
	}
	else if (degreeProgram == 2) {
		return "SOFTWARE";
	}
}

void Student::Print() {
	cout << studentID << '\t';
	cout << "First Name: " << firstName << '\t';
	cout << "Last Name: " << lastName << '\t';
	cout << "Age: " << age << '\t';
	cout << "Days in Course: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "} ";
	cout << "Degree Program: " << PrintDegreeValue(degreeProgram) << endl;
}