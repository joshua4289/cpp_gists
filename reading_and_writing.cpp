#include <ostream>
#include<vector>
#include <fstream>
#include<iostream>

int main(){


    //get demo data
    std::vector<unsigned char> output {0,1,2,3,4,5,6,7,8,9};
    std::ofstream ofile("sample.bin", std::ios::binary);
    //std::ofstream ofile("sample.bin",std::ios::binary);

    if (ofile.is_open()){
        // ostream& write (const char* s, streamsize n);

        ofile.write(reinterpret_cast<char*>(output.data()),output.size());
        std::cout << "Writing to ofile "<< std::endl;
        // read 
        std::ifstream ifile("sample.bin",std::ios::binary);

        // go to find the end of file 
    
        ifile.seekg(0,std::ios_base::end);
        auto length = ifile.tellg();
        ifile.seekg(0,std::ios_base::beg);

        // reserve some memory based on the length
        std::vector<unsigned char> input ;
        input.resize(static_cast<size_t>(length));
        // same signature as write 

        ifile.read(reinterpret_cast<char*>(input.data()),length);

        std::cout << "reading from  ifile "<< std::endl;


        //check if the read is complete 
        // fail bit is False and gcount is number of chars 

        auto success = !ifile.fail() && length == ifile.gcount();
        
        std::cout << "READ_OK " << std::endl;
        
        ofile.close(); //flush op

    
    }

    return 0;
}