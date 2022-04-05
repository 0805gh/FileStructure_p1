#include "Student.h"
#include "CourseRegistration.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<Student> students;
vector<CourseRegistration> course;
const int MaxBufferSize = 500;

int WriteStudent(ostream& stream, Student& s)
{
	char buffer[MaxBufferSize];
	char hours[20]; sprintf(hours, "%d", s.NumberOfCreditHours);
	strcpy(buffer, s.Identifier); strcat(buffer, "|");
	strcat(buffer, s.Name); strcat(buffer, "|");
	strcat(buffer, s.Address);  strcat(buffer, "|");
	strcat(buffer, s.DateOfFirstEnrollment); strcat(buffer, "|");
	strcat(buffer, hours); strcat(buffer, "|");
	short length = strlen(buffer);
	stream.write((char*)&length, sizeof(length));
	stream.write(&buffer[0], length);
	return 1;
}

int WriteCourse(ostream& stream, CourseRegistration& c)
{
	char buffer[MaxBufferSize]; 
	char hours[20]; char grade[20]; char num[20];
	strcpy(buffer, c.CourseIdentifier); strcat(buffer, "|");
	sprintf(num, "%d", c.StudentNum);
	strcat(buffer, num); strcat(buffer, "|");
	for (int i = 0; i < c.StudentNum; i++) {
		strcat(buffer, c.StudentIdentifier[i]); strcat(buffer, "|");
	}
	sprintf(hours, "%d", c.NumberOfCreditHours);
	sprintf(grade, "%.2f", c.CourseGrade);
	strcat(buffer, hours);  strcat(buffer, "|");
	strcat(buffer, grade); strcat(buffer, "|");
	short length = strlen(buffer);
	stream.write((char*)&length, sizeof(length));
	stream.write(&buffer[0], length);
	return 1;
}

istream& operator >> (istream& stream, Student& s)
{
	cout << "Enter identifier, or <cr> to end: " << flush;
	stream.getline(s.Identifier, 30);
	if (strlen(s.Identifier) == 0) return stream;
	cout << "Enter name: " << flush; stream.getline(s.Name, 30);
	cout << "Enter address: " << flush; stream.getline(s.Address, 30);
	cout << "Enter date of the first enrollment: " << flush; stream.getline(s.DateOfFirstEnrollment, 30);
	students.push_back(s);
	return stream;
}

istream& operator >> (istream& stream, CourseRegistration& c)
{
	char creditHours[20], grade[20], num[20];
	cout << "Enter course identifier, or <cr> to end: " << flush;
	stream.getline(c.CourseIdentifier, 30);
	if (strlen(c.CourseIdentifier) == 0) return stream;
	cout << "Enter number of credit hours: " << flush; stream.getline(creditHours, 30);
	c.NumberOfCreditHours = atoi(creditHours);
	cout << "Enter course grade: " << flush; stream.getline(grade, 30);
	c.CourseGrade = atof(grade);
	cout << "Enter number of students: " << flush; stream.getline(num, 30);
	c.StudentNum = atoi(num);
	for (int i = 0; i < c.StudentNum; i++) {
		cout << "Enter student identifier: " << flush; stream.getline(c.StudentIdentifier[i], 30);
		for (int j = 0; j < students.size(); j++) {
			if (!strcmp(c.StudentIdentifier[i], students[j].Identifier)) {
				students[j].increaseNumberOfCreditHours(c.NumberOfCreditHours);
				break;
			}
		}
	}
	course.push_back(c);
	return stream;
}

int main() {
	char filename[20];
	Student s; CourseRegistration c;
	cout << "Enter the file name: " << flush;
	cin.getline(filename, 19);
	ofstream stream(filename, ios::out);
	if (stream.fail()) {
		cout << "File open failed!" << endl;
		return 0;
	}
	while (1) {
		cout << "[Student]\n" << flush;
		cin >> s;
		if (strlen(s.Identifier) == 0) break;
	}
	while (1) {
		cout << "[CourseRegistration]\n" << flush;
		cin >> c;
		if (strlen(c.CourseIdentifier) == 0) break;
	}
	for(int i = 0; i < students.size(); i++)
		WriteStudent(stream, students[i]);
	for (int i = 0; i < course.size(); i++)
		WriteCourse(stream, course[i]);
	system("pause");
	return 1;
}