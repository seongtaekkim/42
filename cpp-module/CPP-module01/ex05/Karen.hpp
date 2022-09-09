/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:15:55 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/09 13:15:56 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef KAREN_HPP
 #define KAREN_HPP

class Karen
{
private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
    void (Karen::*_func[4])();
    std::string _level[4];
public:
    Karen();
    void    complain(std::string level);
};

#endif
