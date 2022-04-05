#include "CourseRegistration.h"
CourseRegistration::CourseRegistration()
{
	CourseIdentifier[0] = 0; StudentIdentifier[0][0] = 0;
	NumberOfCreditHours = 0; CourseGrade = 0.0f; StudentNum = 0;
}

CourseRegistration& CourseRegistration::operator=(CourseRegistration& c) {
	if (this == &c) return *this;
	delete[] CourseIdentifier;
	delete[] StudentIdentifier;
	NumberOfCreditHours = c.NumberOfCreditHours;
	CourseGrade = c.CourseGrade;
	strcpy(CourseIdentifier, c.CourseIdentifier);
	for (int i = 0; i < c.StudentNum; i++) {
		strcpy(StudentIdentifier[i], c.StudentIdentifier[i]);
	}
	return *this;
}

