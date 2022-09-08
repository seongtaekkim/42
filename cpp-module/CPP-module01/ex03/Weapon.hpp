/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:33:43 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/08 17:33:44 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
 #define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
    std::string name;
public:
    Weapon(const std::string &name);
    void    setType(const std::string &name);
    std::string getType() const;
};

#endif
