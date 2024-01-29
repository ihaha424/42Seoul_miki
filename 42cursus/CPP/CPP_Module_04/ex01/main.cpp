/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:04:18 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/15 18:51:15 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    {
        /*
            Show Constructors and Destructors
        */
        Animal*	array[10];

        for(int i = 0; i < 10; i++)
        {
            if (i % 2 == 0)
            {
                std::cout << std::endl;
                try {
                    array[i] = new Cat();
                } catch (const std::bad_alloc& err) {
                    std::cerr << "bad_alloc exception: " << err.what() << std::endl;
                    array[i] = NULL;
                }
            }
            else
            {
                std::cout << std::endl;
                try {
                    array[i] = new Dog();
                } catch (const std::bad_alloc& err) {
                    std::cerr << "bad_alloc exception: " << err.what() << std::endl;
                    array[i] = NULL;
                }
            }
        }
        std::cout << std::endl;
        for(int i = 0; i < 10; i++)
            array[i]->makeSound();
        std::cout << std::endl;
        for (int i = 0; i < 10; i++)
            delete array[i];
    }
    std::cout << "\n=====================================\n" << std::endl;
    {
        /*
            Comparison between Deep Copy and  Shallow Copy.
        */
        Cat	A;
        std::cout << std::endl;
        std::cout << std::endl;
        A.setBrainIdeas("11111", 0);
        Cat	B = Cat(A);
        std::cout << std::endl;
        A.setBrainIdeas("22222", 0);
        Cat* C;
        C = new Cat(A);
        A.setBrainIdeas("33333", 0);
        std::cout << std::endl;
        std::cout << "A: " << A.getBrainIdeas(0) << std::endl;
        std::cout << "B: " << B.getBrainIdeas(0) << std::endl;
        std::cout << "C: " << C->getBrainIdeas(0) << std::endl;
        std::cout << std::endl;

        delete C;
    }


	return 0;
}