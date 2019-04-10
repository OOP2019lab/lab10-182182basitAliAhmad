#pragma once
#include "Student.h"
#include "Course.h"


void Student::task2_addCourse(Course *ptr)
{
	bool flag = true;
	for (int i = 0; i < 2 && flag; i++)
	{
		if (courses[i] == nullptr)
		{
			courses[i] = ptr;
			flag = false;
		}
	}
	if (flag)
		cout << "This student is already taking 2 courses" << endl;
}

Student::Student()
{
	username = "";
	name = "";
	roll_number = "";
	for (int i = 0; i < 2; i++)
		courses[i] = nullptr;
}

Student::Student(string uname, string name, string rollnum) : username(name), name(name), roll_number(rollnum)
{
	for (int i = 0; i < 2; i++)
		courses[i] = nullptr;
}

Student::Student(const Student &dummy)
{
	this->username = dummy.username;
	this->name = dummy.name;
	this->roll_number = dummy.roll_number;

	for (int i = 0; i < 2; i++)
		this->courses[i] = dummy.courses[i];
}

Student::~Student()
{

}

void Student::addCourse(Course* ptr)
{
	bool flag = true;
	for (int i = 0; i < 2 && flag; i++)
	{
		if (courses[i] == nullptr)
		{
			courses[i] = ptr;
			ptr->addStudent(this);
			flag = false;
		}
		else if (courses[i] == ptr)
		{
			cout << "Course is already added in student" << endl;
			flag = false;
		}
	}
	if (flag)
		cout << "This student is already taking 2 courses" << endl;
}

Student & Student::operator=(const Student &dummy)
{
	if (this != &dummy)
	{
		this->username = dummy.username;
		this->name = dummy.name;
		this->roll_number = dummy.roll_number;

		for (int i = 0; i < 2; i++)
			this->courses[i] = dummy.courses[i];
	}

	return *this;
}

void Student::dropCourse(Course* ptr)
{
	bool flag = true;
	for (int i = 0; i < 2 && flag; i++)
	{
		if (this->courses[i] == ptr)
		{
			this->courses[i] = nullptr;
			ptr->dropStudent(this);
			flag = false;
		}
	}
	
	if (flag)
		cout << "student is not registered with this course" << endl;
}

ostream& operator << (ostream& out, const Student& dummy)
{
	out << dummy.name << endl;
	out << dummy.roll_number << endl;
	for (int i = 0; i < 2; i++)
	{
		if (dummy.courses[i] != nullptr)
		{
			out << dummy.courses[i]->course_name << endl;
		}
	}

	return out;
}



