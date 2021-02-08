#include <iostream>
#include <iomanip>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
int main()

/**this is a program to make an empty file of s fiven size */ 

{
    fs::path p = fs::current_path() / "example.bin";
    std::ofstream(p).put('a');
    std::cout << "File size: " << std::setw(5) << fs::file_size(p)
              << " Free space: " << fs::space(p).free << '\n';
    std::filesystem::resize_file(p, 64*1024*1024); // resize to 64 KB
    std::cout << "File size: " << fs::file_size(p)
              << " Free space: " << fs::space(p).free << '\n';

}