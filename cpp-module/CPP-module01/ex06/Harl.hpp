/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:15:55 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/09 13:15:56 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
 #define HARL_HPP

class Harl
{
private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
    void    other(void);
    void (Harl::*_func[5])();
    std::string _level[5];
    enum LOG_TYPE
    {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        OTHER,
        TOTAL
    };
public:
    Harl();
    void    complain(std::string level);
};

#endif
