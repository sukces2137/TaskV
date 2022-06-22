#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>

struct piksel{unsigned char B,G,R;} pixel;

int Color_range=255;
char Header[54];

std::ifstream in;
std::ofstream out;

int main(){

char infile[]="test.bmp";
char outfile[]="negatyw.bmp";

in.open(infile,std::ios::in|std::ios::binary);
in.read((char*)(&Header),sizeof(Header));

out.open(outfile,std::ios::in|std::ios::binary);
out.write((char*)(&Header),sizeof(Header));

int count = 0;

while(!in.eof()){
    in.read((char*)(&pixel),sizeof(pixel));
    //poniższa instrukcja wydrukuje w konsoli 476 tysięcy wierszy (920x518 pikseli), to trwa kilka(naście) minut
    //std::cout << "Piksel " << count+1 << ": R " << (int)pixel.R << " | G " << (int)pixel.G << " | B " << (int)pixel.B << std::endl;
    pixel.R=Color_range-pixel.R;
    pixel.G=Color_range-pixel.G;
    pixel.B=Color_range-pixel.B;
    out.write((char*)(&pixel),sizeof(pixel));
    count++;
}

in.close();
out.close();
}