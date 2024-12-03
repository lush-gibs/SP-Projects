#ifndef InputPerson_H
#define	InputPerson_H

#include "Utilities.h"


vector<Person> manualInputPerson();

vector<Person> inputFile_Vector(const string& fileName);

list<Person> inputFile_list(const string& fileName);

deque<Person> inputFile_Deque(const string& fileName);



#endif