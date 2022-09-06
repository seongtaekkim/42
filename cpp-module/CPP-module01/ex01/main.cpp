/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:04:13 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/06 14:04:15 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (0);
    
    // need to number exception code
    int n = std::atoi(argv[1]);
    Zombie *z = zombieHorde(n, "zombie");
    int index = 0;
    while (index < n)
    {
        z[index].announce();
        index++;
    }
    delete [] z;
    return (0);
}
