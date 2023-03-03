// C libraries
#include <cstdio> // C++ version of C's stdio.h
#include <cstring> // for strlen()

// C++ used for printing
#include <iostream>

// Warning this mixes C file IO with C++ cout! You probably want to 
// look at how to do both in C++
int main()
       {
           char filename[] = "./test.txt";
           FILE *stream;
           
           // set up the buffer
           char buffer[1000]; // maximum line length

           stream = fopen(filename, "r");
           if (stream == NULL) {
               std::cerr << "Opening the file failed!" << std::endl;
               return(-1);
           }

           /* The C library function char *fgets(char *str, int n, FILE *stream) 
            * reads a line from the specified stream and stores it into the string 
            * pointed to by str. It stops when either (n-1) characters are read, the 
            * newline character is read, or the end-of-file is reached, whichever 
            * comes first. See https://en.cppreference.com/w/c/io/fgets
            */
           while (fgets(buffer, sizeof(buffer), stream) != NULL) 
               std::cout << "I read " << strlen(buffer) << " character: " << buffer;
            
            std::cout << std::endl;
     
           fclose(stream);
           return(0);
       }
