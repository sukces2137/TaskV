#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>

struct piksel{unsigned char B,G,R;} p;

int Color_range=255;
char Header[54];

std::ifstream in;
std::ofstream out;

int main(){

char infile[]="${workspaceFolder}/test.bmp";
char outfile[]="${workspaceFolder}/negatyw.bmp";

in.open(infile,std::ios::in|std::ios::binary);
in.read((char*)(&Header),sizeof(Header));

out.open(outfile,std::ios::in|std::ios::binary);
out.write((char*)(&Header),sizeof(Header));


for (int i=0; i<=255 ; i++){
    in.read((char*)(&p),sizeof(p));
    p.R=Color_range-p.R;
    p.G=Color_range-p.G;
    p.B=Color_range-p.B;
    out.write((char*)(&p),sizeof(p));
}

in.close();

}