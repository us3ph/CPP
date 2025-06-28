#include "Replacer.hpp"

int replacer(std::string &fileName, std::string &s1, std::string &s2)
{
  std::ifstream infile(fileName);  // open file with input file stream
  if(!infile)
  {
    std::cerr << "Error: opennig file" << std::endl;
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
    while((pos = line.find(s1, pos)) != std::string::npos)  // npos return special value that means “not found”
    {
      line.erase(pos, s1.length()); // erase s1 from the line
      line.insert(pos, s2);         //insert s2 inside the line
      pos += s2.length();
    }
    oufile << line << '\n';
  }

  infile.close();
  oufile.close();
  return(0);
}
