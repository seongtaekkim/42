#include <iostream>
#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}
void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void    Harl::error(void)
{
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}
Harl::Harl()
{
    _func[0] = &Harl::debug;
    _func[1] = &Harl::info;
    _func[2] = &Harl::warning;
    _func[3] = &Harl::error;
    _level[0] = "DEBUG";
    _level[1] = "INFO";
    _level[2] = "WARNING";
    _level[3] = "ERROR";
}
void    Harl::complain(std::string level)
{
    int index;

    index = 0;
    while (index < 4)
    {
        if (level.compare(_level[index]) == 0)
        {
            (this->*_func[index])();
            break ;
        }
        index++;
    }
}
