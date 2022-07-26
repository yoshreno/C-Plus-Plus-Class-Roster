#include "roster.h"
#include <string>
#include <iostream>
using namespace std;

int main() {

	cout << "Course Title: C867 - Scripting and Programming - Applications" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "WGU Student ID: #001924631" << endl;
	cout << "Name: Yoshitaka Ventura" << endl;
	cout << endl << endl;

	cout << "Starting application..." << endl << endl << endl;


	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Yoshitaka,Ventura,yventu2@wgu.edu,38,10,20,30,SOFTWARE"
	};

	Roster rosterClass;

	for (int i = 0; i < sizeof(studentData); i++) {
		rosterClass.parse(studentData[i]);
	}

	rosterClass.printAll();

	rosterClass.printInvalidEmails();

	for (int i = 0; i < sizeof(studentData); i++) {
		string id = rosterClass.classRosterArray[i]->GetStudentID();
		rosterClass.printAverageDaysInCourse(id);
	}
	cout << endl << endl;

	rosterClass.printByDegreeProgram(DegreeProgram::SOFTWARE);

	rosterClass.remove("A3");

	rosterClass.printAll();

	rosterClass.remove("A3");

	return 0;
}