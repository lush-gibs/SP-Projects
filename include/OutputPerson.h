#ifndef OutputPerson_H
#define	OutputPerson_H

#include "Utilities.h"

void outputVectorToFile_HW_EX(const string& fileName, vector<Person> students);

void outputListToFile_HW_EX(const string& fileName, list<Person> students);

void outputListToFile_HW_EX(const string& fileName, deque<Person> students);

void outputVectorToFile_Grade(const string& fileName, vector<Person> students);

void outputSplitGrade_Vect2(vector <Person>& students);

void outputSplitGrade_List2(list <Person>& students);

void outputSplitGrade_Deque2(deque <Person>& students);

void outputSplitGrade_Vect1(vector<Person>& students);

void outputSplitGrade_List1(list<Person>& students);

void outputSplitGrade_Deque1(deque<Person>& students);

#endif