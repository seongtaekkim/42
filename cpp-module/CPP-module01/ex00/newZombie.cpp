/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:04:19 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/06 14:04:21 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(const std::string &name)
{
    Zombie *z;
    
    try
    {
        z = new Zombie(name);
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << e.what() << std::endl;
        return (NULL);
    }
    return (z);
}
