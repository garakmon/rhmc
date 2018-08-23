#include <fstream>
using std::ofstream; using std::ifstream; using std::fstream; 
//using std::ios;

#include <cstdlib>
//using

#include <cstdio>
//using

#include "io.h"

bool write_to_file(string path, string text) {

    // change this to something not stupid
    try {

        ofstream outfile;
        outfile.open(path);
        outfile << text;
        outfile.close();

        return true;

    }

    catch (...) {return false;}

}

