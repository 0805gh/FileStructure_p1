#include "Student.h"
#include <iostream>
using namespace std;

Student::Student()
{
	Identifier[0] = 0; Name[0] = 0; Address[0] = 0;
	DateOfFirstEnrollment[0] = 0; NumberOfCreditHours = 0;
}

Student& Student::operator=(Student& s) {
	if (this == &s) return *this;
	delete[] Identifier;
	delete[] Name;
	delete[] Address;
	delete[] DateOfFirstEnrollment;
	NumberOfCreditHours = s.NumberOfCreditHours;
	strcpy(Identifier, s.Identifier);
	strcpy(Name, s.Name);
	strcpy(Address, s.Address);
	strcpy(DateOfFirstEnrollment, s.DateOfFirstEnrollment);
	return *this;
}

void Student::modify() {
	int num;
	cout << "Enter the number : " << endl;
	cin >> num;
	switch (num) {
	case 1:
	{
		char id[10];
		cout << "Enter the new Identifier : " << endl;
		cin >> id;
		delete[] Identifier;
		strcpy(Identifier, id);
		break;
	}
	case 2:
	{
		char name[11];
		cout << "Enter the new Name : " << endl;
		cin >> name;
		delete[] Name;
		strcpy(Name, name);
		break;
	}
	case 3:
	{
		char ad[16];
		cout << "Enter the new Address : " << endl;
		cin >> ad;
		delete[] Address;
		strcpy(Address, ad);
		break;
	}
	case 4:
	{
		char date[11];
		cout << "Enter the new Date Of First Enrollment : " << endl;
		cin >> date;
		delete[] DateOfFirstEnrollment;
		strcpy(DateOfFirstEnrollment, date);
		break;
	}
	case 5:
	{
		cout << "Enter the new Number Of Credit Hours : " << endl;
		cin >> NumberOfCreditHours;
		break;
	}
	}
}

void Student::increaseNumberOfCreditHours(int hours)
{
	NumberOfCreditHours += hours;
}
