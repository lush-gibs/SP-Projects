cmake ./CMakeLists.txt
cmake --install .
cmake --build .
copy src\students500k.txt .
copy src\students10000.txt .
copy src\students500k.txt Debug\students500k.txt
copy src\students10000.txt Debug\students1000.txt
Debug\GradeSystem.exe