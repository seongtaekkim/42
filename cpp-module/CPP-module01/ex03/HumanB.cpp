/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:33:24 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/08 17:33:25 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name)
    : name(name)
{}
void    HumanB::attack()
{
    std::cout << this->name << " attack with his " << this->weapon->getType() << std::endl;
}
void    HumanB::setWeapon(Weapon &club)
{
    this->weapon = &club;

    std::cout << "humunb " <<  &club << std::endl;
    std::cout << "humunb " <<  weapon << std::endl;
}
