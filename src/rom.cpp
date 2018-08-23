
#include <fstream>
using std::ofstream; using std::ifstream; using std::fstream; 
using std::ios;

#include <cstdio>
using std::fopen; using std::fclose; using std::fread;// using std::FILE;

#include <vector>
using std::vector;

//#include <cstring>
using std::strncpy;

#include "rom.h"

using std::cout; using std::endl;

Rom::Rom(string filename) {
    // 
    open_rom(filename);
}

Rom::~Rom() {

    delete[] data_;

}

void Rom::open_rom(string filename) {
    //
}

// delete delete delete this
void Rom::open_rom(string filename, Rom &rom) {
    //
}

byte *Rom::get_data(int offset, int nbytes) {

    char *ret_ary = new char[nbytes];

    // don't reinvent the wheel here
    strncpy(ret_ary, (char *)(data_ + offset), nbytes);

    return (byte *)ret_ary;

}


byte *Rom::get_data(int nbytes) {

    //
    byte *ret_ary = new byte[nbytes];

    FILE *file = fopen(name_.c_str(), "rb");
    fread(ret_ary, sizeof(byte), nbytes, file);
    fclose(file);

    return ret_ary;

}

byte Rom::get_byte(int offset) {

    return get_data(offset, 1)[0];

}

half Rom::get_half(int offset) {
    //
    byte b1 = get_byte(offset);
    byte b2 = get_byte(offset+1);

    return (half)((b2 << 8) | b1);

}

word Rom::get_word(int offset) {
    //
    byte b1 = get_byte(offset);
    byte b2 = get_byte(offset+1);
    byte b3 = get_byte(offset+2);
    byte b4 = get_byte(offset+3);

    return (word)((b4 << 24) | (b3 << 16) | (b2 << 8) | b1);

}

// what is this useful for???
// idea was to read a pointer from the rom
word Rom::read_ptr(int offset) {
    //
    word ptr = get_word(offset);
    return (word)(ptr - 0x08000000);

}

string Rom::get_text(int offset, int length) {

    string r_str;

    for (int i = 0; i < length; i++) {
        r_str += data_[offset+i];
    }

    return r_str;

}

string Rom::get_text(word w) {
    //
    string r_str;

    r_str += (w >> 0)  & 0xFF;
    r_str += (w >> 8)  & 0xFF;
    r_str += (w >> 16) & 0xFF;
    r_str += (w >> 24) & 0xFF;
    
    return r_str;

}

string Rom::get_text(half h) {
    //
    string r_str;

    r_str += (h >> 0) & 0xFF;
    r_str += (h >> 8) & 0xFF;

    return r_str;

}

string Rom::get_text(byte b) {
    //
    string r_str;
    r_str += b;
    return r_str;
}

void Rom::print_bytes(int offset, int numbytes) {

    //
    for (int i = 0; i < numbytes; i++) {
        printf("0x%02X ", get_byte(offset+i));
    }

}

ostream& operator << (ostream &os, Rom &pr_rom){
    os << "Rom ";
    os << pr_rom.name_;
    os << " is ";
    os << pr_rom.size_;
    os << " bytes.";
    //os << " The first letter is: ";
    //os << *(pr_rom.data_ + 0);
    os << endl;
    return os;
}

void open_rom(string filename, Rom &rom) {

    //
    rom.name_ = filename;

    // determine size of the rom
    ifstream file(filename, ios::binary | ios::ate);
    long size = file.tellg();
    file.close();
    rom.size_ = size;

    rom.data_ = rom.get_data(size);
    //return;

    cout << "header: " << rom.get_text(0xAC, 4)
         << ", name: " << rom.get_text(0xA0, 12)
         << ", marker: " << rom.get_text(0xB0, 2)
         << endl;

    rom.type_ = rom.get_text(0xAC, 4);

    cout << "Rom header test: " << rom.get_text(rom.get_word(0xAC));
    //printf("Rom header test: %04X", rom.get_word(0xAC));
    cout << endl;

    cout << "Map Names? " << rom.get_text(0x3F1CAC, 0xA) << endl;
    cout << "um " << rom.read_ptr(0x3F1CAC) << endl;

    //for(int i = 0; i < 20; i++){cout << "Name V2? " << rom.get_text(rom.read_ptr(0x00+4*i)) << endl;}
    //cout << "Name V2? " << rom.get_text(rom.read_ptr(0x3F1CAC)) << endl;
    //rom.print_bytes(0x308588, 0xa0);

    cout << "get byte test: " << rom.get_byte(0xAC) << endl;
    //printf("get byte test 2: %02X", rom.get_byte(0xAC)); // hex formatting 
    //printf("get word test: %04X", rom.get_half(0xAC));   // (flipped tho)
    cout << "get half test: " << rom.get_text(rom.get_half(0xAC)) << endl;
    cout << "get word test: " << rom.get_text(rom.get_word(0xAC)) << endl;

    //cout << "map something? " << rom.get_text(0x486578, 0xA0) << endl; 00DDE438
    //cout << "version something? " << rom.get_text(0x00DDE438, 0xA0) << endl;

}
