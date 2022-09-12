/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:16:03 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/09 13:16:05 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char *argv[])
{
    Harl h;

    if (argc != 2)
        return (0);
    h.complain(argv[1]);

    return (0);
}
