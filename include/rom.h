#ifndef ROM_H
#define ROM_H

//#include <algorithm>
// using

//#include <string>
//using std::string;

#include <iostream>
using std::ostream;

//#include <vector>
//using std::vector;

#include "global.h"
#include "io.h"

class Rom {

private:
    //
    string  name_;
    string  type_;
    string  base_; // needed?
    byte   *data_;
    long    size_; // porbably overkill (expect 16-32M)
    long    pos_; // current position in data

public:
    //
    Rom()=default;
    Rom(string);
    ~Rom();

    string get_text(int, int); // offset, length
    string get_text(word); 
    string get_text(half);
    string get_text(byte);
    void   open_rom(string);
    void   open_rom(string, Rom&);
    void   read_maps();
    void   read_header();//?
    void   read_events();//?
    void   print_bytes(int, int); // offset, number

    // rename these
    word  read_ptr(int);
    byte *get_data(int); // rom size
    byte *get_data(int, int); // offset, size
    byte  get_byte(int); // offset
    half  get_half(int); // 2 bytes
    word  get_word(int); // 4 bytes

    //vector<string> map_list_;

    friend ostream& operator << (ostream&, Rom&);
    friend void open_rom(string, Rom&);

};

#endif // ROM_H
