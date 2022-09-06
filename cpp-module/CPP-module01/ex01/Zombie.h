/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:03:36 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/06 14:04:06 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
 #define ZOMBIE_H

#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    Zombie();
    Zombie(const std::string name);
    ~Zombie();
    void    announce(void);
    void    setName(const std::string &name);
};
Zombie* zombieHorde(int N, std::string name);
Zombie* newZombie(const std::string &name);
void    randomChump(const std::string &name);
#endif
