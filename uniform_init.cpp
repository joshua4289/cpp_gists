
#include <iostream>
#include<vector>
#include<map>

/**  Basics of uniform initialization with basic types n classes 
It is a post c++11 feature  
*/

int main(){

    std::string s1 ("test"); //direct initalization 
    std::string s2 = "test"; // copy initialization 

    //T object{other}
    
    std::vector<int>v ={1,2,3};
    std::map<int,std::string> mapper {{1,"one"},{2,"two"}};
    int arr1[3] = {1,2,3};
    int i = {42};
    double d = {2.0};


    // define a struct to hold data 
    struct MyStruct {
        int a_ ;
        double b_;      
    
    };
    // namofstruct instance_name{data,data}
    MyStruct my{1,4.3};
    std::cout << "a:_" << my.a_ << std::endl;
    std::cout << "b_:"<< my.b_ << std::endl;
    

    return 0;
}