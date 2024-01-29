/*
   Just a quick script to calculate the 
   decayWidth parameter needed for pythia
   given an LLP lifetime in mm.
   g++ calcLifetime.cpp; ./a.out
*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

const double c = 2.998e8; // m/s
const double hbar =  6.582119569e-25; // GeV*s
const double Gamma = 1.9732698e-15; //GeV
int main(){

std::vector<double>  ct; // in mm
ct.push_back(1.00);
ct.push_back(5.00);
ct.push_back(10.00);
ct.push_back(50.00);
ct.push_back(100.00);
ct.push_back(500.00);
ct.push_back(1000.00);
 

std::cout<< hbar*c/Gamma<<std::endl;
for (int i = 0; i<ct.size(); i++){
  double gamma = hbar*c/(ct[i]/1000.);
  std::cout << std::setprecision(9) <<ct[i]<<"    "<<gamma<<std::endl;
}

return 0;
}
