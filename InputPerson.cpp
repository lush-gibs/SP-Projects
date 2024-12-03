#include "InputPerson.h"

vector<Person> manualInputPerson()
{
    int n;

    while (true)
    {
        cout << "\nPlease input number of students: ";

        cin >> n;
        if (cin.fail())
            clearWrongInputs();
        else break;
    }

    vector<Person> students(n);

    for (Person& student : students)
    {
        cin >> student;                 // calls overloaded cin to input data into Persons class member variables until number of students required has reached
    }

    return students;
}

 vector<Person> inputFile_Vector(const string& fileName)
 {
     vector <vector <string>> fileInfo;
     stringstream myBuffer;
     vector<Person> personsInFile;

     auto start = high_resolution_clock::now();

     ifstream file(fileName);

     if (!file.is_open())
     {
         std::cerr << "\nFile not found!\n";
         return personsInFile;
     }
     
     myBuffer << file.rdbuf();
     file.close();

     vector <string> wordsInLine;
     string lineOfFile;

     while (std::getline(myBuffer, lineOfFile))
     {
         wordsInLine.clear();
         std::istringstream is(lineOfFile);                  // Reads the lineOffile string

         string word;

         while (is >> word)                                     //words in lineOffile string is read separately using the word variable
         {
             wordsInLine.push_back(word);                             // fill the vector of string with each word from line
         }
         fileInfo.push_back(wordsInLine);                    //fill the vector with vector of string
     }

    std::chrono::duration <double> duration = high_resolution_clock::now() - start;
     cout << "Time taken to read to buffer then into a vector containing vector of strings: " << duration.count() << " seconds\n";

     bool firstLine = true;

     for (auto& lines : fileInfo)            // loops through entire vector which contains the file information, first index in vector is for first line in file
     {
         if (firstLine)
         {
             firstLine = false;
             continue;                       //skips first line in the file 
         }

         Person p;
         vector<double> hw;

         p.setFirstName(lines[0]);                           //sets object firstname variable with first word in the vector of string

         if (lines.size() > 1)
             p.setSurname(lines[1]);

         for (int i = 2; i < lines.size(); i++)
         {
             try
             {
                 if (lines[i].length() > 17) {
                     throw out_of_range("Number too large to fit into a double");
                 }

                 double value = std::stod(lines[i]);                     //converts string to double in exception checker block

                 if (i < lines.size() - 1)                      //checks if index is not on the last column which is reserved for exam scores
                     hw.push_back(value);
                 else
                     p.setExamScore(value);
             }
             catch (const invalid_argument& e)
             {
                 std::cerr << "\ninvalid homework or exam score detected in file for "
                     << lines[0] << " " << lines[1] << endl << endl;
             }
             catch (const out_of_range& e)
             {
                 std::cerr << "\nout of range homework score detected in file for "
                     << lines[0] << " " << lines[1] << ": " << lines[i] << endl << endl;
             }
         }

         p.setHomework(hw);
		 p.calcFinalGrade(1);                                   // (1) for calculting final grade via Average method for all file inputs
         personsInFile.push_back(p);
     }

     return personsInFile;
 }

 list<Person> inputFile_list(const string& fileName)
 {
     stringstream buffer;
     list<string> wordsInLine;
	 list<list<string>> fileInfo;
	 list<Person> personsInFile;
     

	 auto start = high_resolution_clock::now();

     ifstream fileIn(fileName);

     if (!fileIn)
     {
         cerr << "File not found!";
		 return personsInFile;
     }
     
     buffer << fileIn.rdbuf();
     fileIn.close();

     string line;

     while(getline(buffer,line))
     {
		wordsInLine.clear();

        stringstream is(line);
		string word;
        
		while (is >> word)
		{
            wordsInLine.push_back(word);
		}
		fileInfo.push_back(wordsInLine);
     }

	 std::chrono::duration<double> duration = high_resolution_clock::now() - start;
	 cout << "Time taken to read to buffer then into list container with list of strings: " << duration.count() << " seconds\n";

	 fileInfo.pop_front(); //removes first line of file which is table titles

	 for (auto& s : fileInfo)
	 {
		 Person p;
		 vector<double> hw;

		 p.setFirstName(s.front());
		 s.pop_front();

		 if (s.size() > 1)
			 p.setSurname(s.front());

		 s.pop_front();

		 for (auto it = s.begin(); it != s.end(); it++)
		 {
			 try
			 {
				 if (it->length() > 17) {
					 throw out_of_range("Number too large to fit into a double");
				 }

				 double value = std::stod(*it);

				 if (std::next(it) != s.end())
                     hw.push_back(value);
				 else
					 p.setExamScore(value);
			 }
			 catch (const invalid_argument& e)
			 {
				 std::cerr << "\ninvalid homework or exam score detected in file for "
					 << s.front() << " " << s.front() << endl << endl;
			 }
			 catch (const out_of_range& e)
			 {
				 std::cerr << "\nout of range homework score detected in file for "
					 << s.front() << " " << s.front() << ": " << *it << endl << endl;
			 }
		 }

		 p.setHomework(hw);
		 p.calcFinalGrade(1);                                   // (1) for calculting final grade via Average method for all file inputs
		 personsInFile.push_back(p);
	 }

     return personsInFile;
     
 }

 deque<Person> inputFile_Deque(const string& fileName)
 {
     stringstream buffer;
     deque<string> wordInLine;
     deque<deque<string>> fileInfo;
     string line;
	 deque<Person> personsInFile;

     auto start = high_resolution_clock::now();

     ifstream fileIn(fileName);

     if (!fileIn)
     {
         cerr << "File not found!";
     }

     buffer << fileIn.rdbuf();
     fileIn.close();


     while (getline(buffer, line))
     {
         wordInLine.clear();

     std:stringstream is(line);
         string word;

         while (is >> word)
         {
             wordInLine.push_back(word);
         }
         fileInfo.push_back(wordInLine);
     }

     std::chrono::duration<double> duration = high_resolution_clock::now() - start;
     cout << "Time taken to read to buffer then into deque container with list of strings: " << duration.count() << " seconds\n";

	 fileInfo.pop_front(); //removes first line of file

	 for (auto& s : fileInfo)
	 {
		 Person p;
		 vector<double> hw;

		 p.setFirstName(s.front());
		 s.pop_front();

		 if (s.size() > 1)
			 p.setSurname(s.front());

		 s.pop_front();

		 for (auto& i : s)
		 {
			 try
			 {
				 if (i.length() > 17) {
					 throw out_of_range("Number too large to fit into a double");
				 }

				 double value = std::stod(i);

				 if (s.size() > 1)
				 {
					 hw.push_back(value);
					 s.pop_front();
				 }
				 else
					 p.setExamScore(value);
			 }
			 catch (const invalid_argument& e)
			 {
				 std::cerr << "\ninvalid homework or exam score detected in file for "
					 << s.front() << " " << s.front() << endl << endl;
			 }
			 catch (const out_of_range& e)
			 {
				 std::cerr << "\nout of range homework score detected in file for "
					 << s.front() << " " << s.front() << ": " << i << endl << endl;
			 }
		 }

		 p.setHomework(hw);
		 p.calcFinalGrade(1);                                   // (1) for calculating final grade via Average method for all file inputs
		 personsInFile.push_back(p);
	 }

	 return personsInFile;
 }
