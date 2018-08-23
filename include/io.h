#ifndef IO_H
#define IO_H

#include <string>
using std::string;

#include "global.h"
#include "rom.h"

class Rom;

bool write_to_file(string, string);
//void save_headers(vector<string>); // map names?

#endif // IO_H
