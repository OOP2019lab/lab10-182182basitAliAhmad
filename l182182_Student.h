#pragma once

#include<string>
#include<iostream>
using namespace std;

class Course;
class Student
{
private:
	string username;
	string name;
	string roll_number;
	Course* courses[2];

	void task2_addCourse(Course*);

public:
	friend class Course;

	Student();
	Student(string, string, string);
	Student(const Student&);
	~Student();
	void addCourse(Course*);
	friend ostream& operator << (ostream&, const Student&);
	friend ostream& operator << (ostream&, const Course&);
	Student& operator = (const Student&);

	void dropCourse(Course*);
};

