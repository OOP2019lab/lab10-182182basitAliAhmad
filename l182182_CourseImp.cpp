#pragma once
#include "Student.h"
#include "Course.h"


void Course::addStudent(Student* ptr)
{
	bool flag = true;
	for (int i = 0; i < 4 && flag; i++)
	{
		if (students[i] == nullptr)
		{

			students[i] = ptr;
			flag = false;
		}
	}
	if (flag)
		cout << "Course has already 4 students" << endl;
}

void Course::dropStudent(Student* ptr)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->students[i] == ptr)
		{
			this->students[i] = nullptr;
			break;
		}
	}
}

Course::Course()
{
	course_name = "";
	course_number = "";
	for (int i = 0; i < 4; i++)
		students[i] = nullptr;
}

Course::Course(string name, string number) : course_name(name), course_number(number)
{
	for (int i = 0; i < 4; i++)
		students[i] = nullptr;
}

Course::Course(const Course &dummy)
{
	this->course_name = dummy.course_name;
	this->course_number = dummy.course_number;
	for (int i = 0; i < 4; i++)
		this->students[i] = dummy.students[i];
}

Course::~Course()
{

}

Course & Course::operator=(const Course &dummy)
{
	if (this != &dummy)
	{
		this->course_name = dummy.course_name;
		this->course_number = dummy.course_number;
		for (int i = 0; i < 4; i++)
			this->students[i] = dummy.students[i];
	}
	
	return *this;
}

void Course::task2_addStudent(Student *ptr)
{
	bool flag = true;
	for (int i = 0; i < 4 && flag; i++)
	{
		if (students[i] == nullptr)
		{

			students[i] = ptr;
			ptr->task2_addCourse(this);
			flag = false;
		}
		else if (students[i] == ptr)
		{
			cout << "Student is already taking that course" << endl;
			flag = false;
		}
	}
	if (flag)
		cout << "Course has already 4 students" << endl;
}

ostream& operator << (ostream& out, const Course& dummy)
{
	out << dummy.course_name << endl;
	out << dummy.course_number << endl;
	for (int i = 0; i < 4; i++)
	{
		if (dummy.students[i] != nullptr)
			out << dummy.students[i]->name << endl;
	}

	return out;
}
