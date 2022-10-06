// C libraries
#include <cstdio> // C++ version of C's stdio.h
#include <cstdlib> // C++ version of C's stdlib.h

// C++ used for printing
#include <iostream>

// Note: this uses getline() from stdio.h (C) which is different from std::getline() in the C++ <string> library!!!
// See: https://man7.org/linux/man-pages/man3/getline.3.html
//
// Alternatively you can use getc() (also in stdio.h) to read a single character at a time.

       int main()
       {
           char filename[] = "./test.txt";
           FILE *stream;
           
           // set up the buffer
           char buffer[1001]; // add extra space for null terminator, etc.
           char *b = buffer;  // we need a pointer to the buffer 
           size_t maxlen = 1000;
           
           size_t nread;

           stream = fopen(filename, "r");
           if (stream == NULL) {
               std::cerr << "Opening the file failed!" << std::endl;
               return(-1);
           }

           // getline wants pointers to all its arguments!
           // size_t getline(char **lineptr, size_t *n, FILE *stream)
           while ((nread = getline(&b, &maxlen, stream)) != -1) 
               std::cout << "I read " << nread << " character: " << buffer;
            
            std::cout << std::endl;
     

           fclose(stream);
           return(0);
       }
