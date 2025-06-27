#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
  if(argc != 4)
  {
    std:: cout << "Error: number of arguments not correct" << std::endl;
    return(1);
  }
  std::string fileName;
  std::string s1;
  std::string s2;

  fileName = argv[1];
  s1 = argv[2];
  s2 = argv[3];

  std::ifstream infile(fileName);  // open file with input file stream
  if(!infile)
  {
    std::cerr << "Error: opennig file";
    return(1);
  }

  std::ofstream oufile(fileName + ".replace"); // output file with output file stream
  if(!oufile)
  {
    std::cerr << "Error: cannot creat output file" << std::endl;
    return(1);
  }

  std::string line;
  while(std::getline(infile, line)) // read line
  {
    size_t pos = 0;  // possition is index
    while((pos = line.find(s1, pos)) != std::string::npos)  //special value that means “not found”
    {
      line.erase(pos, s1.length()); // erase s1 from the line
      line.insert(pos, s2);         //insert s2 inside the line
      pos += s2.length();
    }
    oufile << line << '\n';
  }

  infile.close();
  oufile.close();
}
