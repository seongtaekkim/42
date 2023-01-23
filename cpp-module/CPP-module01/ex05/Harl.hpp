#ifndef HARL_HPP
 #define HARL_HPP

#include <iostream>

class Harl
{
private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
    void (Harl::*_func[4])();
    std::string _level[4];
public:
    Harl();
    void    complain(std::string level);
};

#endif
