// dummy.cpp : Defines the entry point for the console application.
//
#pragma once
#include "Student.h"
#include "Course.h"

int main()
{
	// creating 5 students with given data
	Student* S1 = new Student("anum", "Anum", "11-1351");
	Student* S2 = new Student("sara", "Sara", "12-6462");
	Student* S3 = new Student("sana", "Sana", "11-4531");
	Student* S4 = new Student("zara", "Zara", "12-4342");
	Student* S5 = new Student("hira", "Hira", "11-5940");

	// creating 3 course with given data
	Course* C1 = new Course("OOP", "CS102");
	Course* C2 = new Course("PF", "CS101");
	Course* C3 = new Course("AI", "CS365");

	S1->addCourse(C1);
	S1->addCourse(C2);
	S1->addCourse(C2);
	S1->addCourse(C3);
	S2->addCourse(C2);
	S3->addCourse(C2);
	S4->addCourse(C2);
	S5->addCourse(C2);
	//C1->addStudent(S5); it is giving error as it is a private function

	cout << *S1 << endl;
	cout << *C1 << endl;
	cout << *C2 << endl;

	// task 2
	C1->task2_addStudent(S5);
	S5->addCourse(C3);
	
	// task 3

	S5->dropCourse(C1);
	
	S4->dropCourse(C3);
	//C1->dropStudent(S1); it is giving error as it is a private function

	delete S1;
	delete S2;
	delete S3;
	delete S4;
	delete S5;

	delete C1;
	delete C2;
	delete C3;

    return 0;
}

