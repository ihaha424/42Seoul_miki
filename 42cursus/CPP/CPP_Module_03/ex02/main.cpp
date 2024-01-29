/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:04:18 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/10 19:08:24 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
  //Make 3 ClapTrap
  ClapTrap CA("C_A");
  ClapTrap CB("C_B"); 
  FragTrap FA("F_A");
  FragTrap FB("F_B");
  
  //Message Off
  CA.changeFlag();
  CB.changeFlag();
  FA.changeFlag();
  FB.changeFlag();

  //Attack Damege Setting
  CA.setAttackDamage(50);
  CB.setAttackDamage(100);
  FB.setAttackDamage(1000);

  //Action1
  CA.attack(FA);
  CB.attack(FB);

  //Action2
  FA.attack("Player");
  FB.attack("Player");
  FA.highFivesGuys();
  FB.highFivesGuys();

  FA.setTarget(CB);
  std::cout << FA.getTarget()->getName() << std::endl;
}