#ifndef Utilities_H
#define Utilities_H

#include "Person.h"

double Median(vector<double>& list);

double average(vector<double>& list);

void clearWrongInputs();

vector<Person> randomizePersons();

void gradeSplitter_2Vects(vector <Person>& students, vector <Person>& Passed, vector <Person>& Failed);

void gradeSplitter_2Lists(list <Person>& students, list <Person>& Passed, list <Person>& Failed);

void gradeSplitter_2Deques(deque <Person>& students, deque <Person>& Passed, deque <Person>& Failed);

void splitGrades_1Vect(vector<Person>& students, vector<Person>& other);

void splitGrades_1List(list<Person>& students,list<Person>& other);

void splitGrades_1Deque(deque<Person>& students,deque<Person>& other);

void gradeSorter_Vect(vector <Person>& students);

void gradeSorter_List(list <Person>& students);

void gradeSorter_Deque(deque <Person>& students);

void printGrades_AverAndMed(vector<Person>& students);

void printGrades_AverOrMed(vector<Person>& students);


#endif