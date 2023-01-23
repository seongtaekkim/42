#include <iostream>
#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger.\nI really do!\n" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. \n I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

void    Harl::other(void)
{
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

Harl::Harl()
{
    _func[DEBUG] = &Harl::debug;
    _func[INFO] = &Harl::info;
    _func[WARNING] = &Harl::warning;
    _func[ERROR] = &Harl::error;
    _func[OTHER] = &Harl::other;
    _level[DEBUG] = "DEBUG";
    _level[INFO] = "INFO";
    _level[WARNING] = "WARNING";
    _level[ERROR] = "ERROR";
    _level[OTHER] = "OTHER";
}

void    Harl::complain(std::string level)
{
    int index;

    index = 0;
    while (index < this->TOTAL)
    {
        if (level.compare(_level[index]) == 0)
        {
            switch(index)
            {
                case DEBUG :
                    (this->*_func[DEBUG])();
                case INFO :
                    (this->*_func[INFO])();
                case WARNING :
                    (this->*_func[WARNING])();
                case ERROR :
                    (this->*_func[ERROR])();
                    break ;
            }
            break ;
        }
        index++;
    }
    if (index == this->TOTAL)
        (this->*_func[OTHER])();
}
