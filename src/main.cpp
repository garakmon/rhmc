#include <iostream>
using std::cout; using std::endl;

#include <iomanip>

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "global.h"
#include "io.h" // file writing and such

//#include <fstream>

int main(int argc, char *argv[]) {

    if (argc < 5) {
        cout << "Too few arguments." << endl;
        return 1;
    }

    /* ./rhmc romhack.gba ruby pokeruby 32 */
    string filename = argv[1];       // rom file
    string baserom  = argv[2];       // baserom version
    string folder   = argv[3];       // folder to place maps in
    int    nmaps    = atoi(argv[4]); // number of maps

    write_to_file("test.txt", filename+baserom+folder);

    vector<string> map_names;
    Rom rom;

    open_rom(filename, rom);

    cout << rom;

    return 0;

}