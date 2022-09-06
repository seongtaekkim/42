/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:03:28 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/06 14:03:32 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.h"

Zombie::Zombie() {
        std::cout << "constructor : " << std::endl;
}
Zombie::Zombie(const std::string name)
    : name(name) {
    
    }
Zombie::~Zombie()
{
    std::cout << this->name << " is die." << std::endl;
}
void    Zombie::setName(const std::string &name)
{
    this->name = name;
}
void    Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
