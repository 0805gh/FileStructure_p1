#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <strstream>
#include <string.h>
#include <iomanip>
#include "Student.h"
#include "CourseRegistration.h"

using namespace std;

istream& operator >> (istream& stream, Student& s)
{
	char credit[10];
	stream.getline(s.Identifier, 30, '|');
	if (strlen(s.Identifier) == 0) return stream;
	stream.getline(s.Name, 30, '|');
	stream.getline(s.Address, 30, '|');
	stream.getline(s.DateOfFirstEnrollment, 30, '|');
	stream.getline(credit, 30, '|');
	s.NumberOfCreditHours = atoi(credit);
	return stream;
}

istream& operator >> (istream& stream, CourseRegistration& c)
{
	char num[10]; char credit[10]; char grade[10];
	stream.getline(c.CourseIdentifier, 30, '|');
	if (strlen(c.CourseIdentifier) == 0) return stream;
	stream.getline(num, 30, '|');
	c.StudentNum = atoi(num);
	for (int i = 0; i < c.StudentNum; i++) {
		stream.getline(c.StudentIdentifier[i], 30, '|');
	}
	stream.getline(credit, 30, '|');
	stream.getline(grade, 30, '|');
	c.NumberOfCreditHours = atoi(credit);
	c.CourseGrade = (float)atof(grade);
	return stream;
}

int ReadVariableStudent(istream& stream, Student& s)
{
	short length;
	stream.read((char*)&length, sizeof(length));
	if (stream.fail()) { s.Identifier[0] = 0; return 0; }
	char* buffer = new char[length + 1];
	stream.read(buffer, length);
	buffer[length] = 0;
	istrstream strbuff(buffer);
	strbuff >> s;
	return 1;
}

int ReadVariableCourse(istream& stream, CourseRegistration& c)
{
	short length;
	stream.read((char*)&length, sizeof(length));
	if (stream.fail()) { c.CourseIdentifier[0] = 0; return 0; }
	char* buffer = new char[length + 1];
	stream.read(buffer, length);
	buffer[length] = 0;
	istrstream strbuff(buffer);
	strbuff >> c;
	return 1;
}

ostream& operator << (ostream& stream, Student& s)
{
	cout << "Student 객체를 출력한다" << endl;
	stream << s.Identifier << '|' << s.Name << '|'
		<< s.Address << '|' << s.DateOfFirstEnrollment << '|'
		<< s.NumberOfCreditHours << '|';
	cout << endl;
	return stream;
}

ostream& operator << (ostream& stream, CourseRegistration& c)
{
	cout << "CourseRegistration 객체를 출력한다" << endl;
	stream << c.CourseIdentifier << '|';
	for (int i = 0; i < c.StudentNum; i++) {
		if(i == c.StudentNum-1)
			stream << c.StudentIdentifier[i] << '|';
		else
			stream << c.StudentIdentifier[i] << ',';
	}
	stream << c.NumberOfCreditHours << '|';
	stream << fixed << setprecision(2) << c.CourseGrade << '|';
	cout << endl;
	return stream;
}

int main(void) {
	char filename[20];
	Student s; CourseRegistration c;
	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);
	ifstream stream(filename, ios::in);
	if (stream.fail()) {
		cout << "File open failed!" << endl;
		return 0;
	}
	for(int i = 0; i < 5; i++) {
		ReadVariableStudent(stream, s);
		if (strlen(s.Identifier) == 0) break;
		cout << s;
	}
	for (int i = 0; i < 5; i++) {
		ReadVariableCourse(stream, c);
		if (strlen(c.CourseIdentifier) == 0) break;
		cout << c;
	}
	system("pause");
	return 1;
}