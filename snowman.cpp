#include "snowman.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

namespace ariel{
  const int min = 11111111;
  const int max = 44444444;
  const int Hat = 0;
  const int Nose = 1;
  const int LE = 2;
  const int RE = 3;
  const int LA = 4;
  const int RA = 5;
  const int Torso = 6;
  const int Base = 7;
  const int k = 10;
  const std::vector<string> hats = { "_===_"," ___ \n.....","  _  \n /_\\"," ___ \n(_*_)"};
  const std::vector<string> noses = {",",".","_"," "};
  const std::vector<string> eyes = {".","o","O","-"};
  const std::vector<string> left_arms = {"<"," ","/"," "};
  const std::vector<string> left_arm_up = {" ","\\"," "," "};
  const std::vector<string> right_arms = {">"," ","\\"," "};
  const std::vector<string> right_arm_up = {" ","/"," "," "};
  const std::vector<string> torsos = {" : ","] [","> <","   "};
  const std::vector<string> bases = {" : ","\" \"","___","   "};

  string snowman (int input){
    string num = to_string(input);
    string snowman = " ";

    if(input<min || input>max){  // the input consists of 8 digits
      throw out_of_range{"Invalid input"}; }

    std::vector<int> building = {0,0,0,0,0,0,0,0};
    int number = input;
    for (int i = Base; i >=0; i--){
      if(number%k==0 || number%k > 4){  // the input contains invalid digits
        throw out_of_range("Invalid digits"); }
      building.at(i) = number%k -1;
      number/=k;
    }

    snowman += hats[building[Hat]] + "\n";  // hat
    snowman += left_arm_up[building[LA]] + "(";  // if the left arm is up then print it before the face
    snowman += eyes[building[LE]]; // left_eye
    snowman += noses[building[Nose]];  // nose
    snowman += eyes[building[RE]] + ")";  // right_eye and closing for the face
    snowman += right_arm_up[building[RA]] + "\n";  // if the right arm is up then print it after the face
    snowman += left_arms[building[LA]] + "(";  // left arm and openning the torso
    snowman += torsos[building[Torso]] + ")";  // torso and closing the torso
    snowman += right_arms[building[RA]] + "\n (";  // right arm, linebreak and openning the base
    snowman += bases[building[Base]] + ")";  // base and closing the base


    return snowman;

  }

}
