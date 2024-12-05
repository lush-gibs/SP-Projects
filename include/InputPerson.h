#ifndef InputPerson_H
#define	InputPerson_H

#include "Utilities.h"


vector<Person> manualInputPerson();

vector<Person> inputFile_Vector(string& fileName);

list<Person> inputFile_List(string& fileName);

deque<Person> inputFile_Deque(string& fileName);

#endif