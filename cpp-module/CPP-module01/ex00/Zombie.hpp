/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staek <staek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:03:36 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/11 14:17:57 by staek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
 #define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
    std::string name;
public:
    Zombie();
    Zombie(const std::string name);
    ~Zombie();
    void announce(void);
};
Zombie* newZombie(const std::string &name);
void    randomChump(const std::string &name);

#endif