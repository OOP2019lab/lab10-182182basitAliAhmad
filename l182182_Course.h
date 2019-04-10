#pragma once
#include<string>
#include<iostream>
using namespace std;

class Student;
class Course
{
private:
	string course_name;
	string course_number;
	Student* students[4];

	void addStudent(Student*);
	void dropStudent(Student*);

public:
	friend class Student;

	Course();
	Course(string, string);
	Course(const Course&);
	~Course();
	friend ostream& operator << (ostream&, const Student&);
	friend ostream& operator << (ostream&, const Course&);
	Course& operator = (const Course&);

	void task2_addStudent(Student*);


};

