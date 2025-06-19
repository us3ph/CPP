#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    int i = 1;
    if(ac == 1)
        return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 1);
    while(av[i])
    {
        int j = -1;
        while(av[i][++j])
            std::cout << (char)toupper(av[i][j]); 
        i++;
    }
    std::cout << std::endl;
    return(0);
    
}