
// ** Dipole-Generator Implementation in C++
// *  Author: Jose Lopez
// *  Date: 15-July-2017
// *
// *

// TODO: Just flesh it out first, shooting from the hop, then profile and refactor
// TODO: Shrink structures to fit on cache/page 

#include "Main.hpp"
#include "Template-Input_Validation.hpp"
#include "Template-Constants.hpp"



int main()
{
    system(CLEARSCREEN);
    
    const auto start = std::chrono::system_clock::now();

    std::cout << "Please enter supercell dimension: ";
    const auto n = IO::get<int>();
    
    std::cout << "Dimensions: " << n << "x" << n << "x" << n << '\n';
    std::cout << "Size: " << POW3(n) << " \n\n";
    
    std::ofstream dipoleoutputfile;
    dipoleoutputfile.open("DIP3D", std::ofstream::out);
    
    STATUS (*GenerateSupercell)(int);
    
    std::cout << "Please select the supercell type: \n";
    std::cout << "\t1. Dot \n";
    std::cout << "\t2. Wire \n";
    std::cout << "\t3. Film \n";
    std::cout << "\t4. Bulk \n";
    auto response = IO::get<int>();
    
    switch (response) {
    	case (DOT) 	: GenerateSupercell = Dot;  break;
    	case (WIRE)	: GenerateSupercell = Wire; break;
    	case (FILM)	: GenerateSupercell = Film; break;
    	case (BULK)	: GenerateSupercell = Bulk; break;
    	
    	default: std::cout << "[ERROR] Could not understand input... \n"; exit(ERROR);
    }
    
    
    GenerateSupercell(n);
    
    
    
    std::cout << "[BACK IN MAIN...]\n";
    
    
    // Program wind-down -> close buffers and stop timer
    dipoleoutputfile.close();
    const auto end = std::chrono::system_clock::now();
    
    std::cout << "\nProgram running time: ";
    const auto diff = end - start;
    std::cout.precision(6);
    std::cout << std::chrono::duration<double, std::ratio<1,1000>>(diff).count() << "ms \n";
}
