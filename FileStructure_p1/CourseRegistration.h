#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef COURSEREGISTRATION
#define COURSEREGISTRATION
#include <iostream>
class CourseRegistration
{
public:
	char CourseIdentifier[20]; char StudentIdentifier[20][20];
	int NumberOfCreditHours; float CourseGrade; int StudentNum;
public:
	CourseRegistration();
	CourseRegistration& operator=(CourseRegistration& c);
	friend std::istream& operator >> (std::istream& stream, CourseRegistration& c);
	friend std::ostream& operator << (std::ostream& stream, CourseRegistration& c);
};
#endif
