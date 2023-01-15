/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:04:32 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/06 14:04:33 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    randomChump(const std::string &name)
{
    Zombie *z = newZombie(name);
    z->announce();
    try {
        delete (z);
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    
}
