#ifndef OutputPerson_H
#define	OutputPerson_H

#include "Utilities.h"

void outputVectorToFile_HW_EX(const string& fileName, vector<Person> students);

void outputListToFile_HW_EX(const string& fileName, list<Person> students);

void outputListToFile_HW_EX(const string& fileName, deque<Person> students);

void outputVectorToFile_Grade(const string& fileName, vector<Person> students);

void outputSplitGrade_Vect(vector <Person>& students);

void outputSplitGrade_list(list <Person>& students);

void outputSplitGrade_deque(deque <Person>& students);

#endif