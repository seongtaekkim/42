/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:18:08 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/07 14:18:10 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    const std::string str = "HI THIS IS BREAN";
    const std::string *stringPTR = &str;
    const std::string &stringREF = str;

    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
    return (0);
}
