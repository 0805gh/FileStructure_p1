#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef STUDENT
#define STUDENT
#include <iostream>
class Student
{
public:
	char Identifier[10]; char Name[11]; char Address[16];
	char DateOfFirstEnrollment[11]; int NumberOfCreditHours;
public:
	Student();
	Student& operator=(Student& s);
	void modify();
	void increaseNumberOfCreditHours(int hours);
	friend std::istream& operator >> (std::istream& stream, Student& s);
	friend std::ostream& operator << (std::ostream& stream, Student& s);
};
#endif