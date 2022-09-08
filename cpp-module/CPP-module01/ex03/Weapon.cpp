/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:33:39 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/08 17:33:39 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &name)
    : name(name)
{}
void    Weapon::setType(const std::string &name)
{
    this->name = name;
}
std::string Weapon::getType() const
{
    return (this->name);
}
