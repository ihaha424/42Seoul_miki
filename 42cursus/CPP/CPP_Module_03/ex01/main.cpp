/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:04:18 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/10 18:54:58 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
  //Make 3 ClapTrap
  ClapTrap CA("C_A");
  ClapTrap CB("C_B"); 
  ScavTrap SA("S_A");
  ScavTrap SB("S_B");
  
  //Message Off
  CA.changeFlag();
  CB.changeFlag();
  SA.changeFlag();
  SB.changeFlag();

  //Attack Damege Setting
  CA.setAttackDamage(50);
  CB.setAttackDamage(100);
  SB.setAttackDamage(1000);

  //Action1
  CA.attack(SA);
  CA.attack(SB);

  //Action2
  SA.attack("Player");
  SB.attack("Player");
  SA.guardGate();
  SB.guardGate();

  SA.setTarget(CB);
  std::cout << SA.getTarget()->getName() << std::endl;
  
  //Error case
  // SA.attack(CA);
  // SA.attack(SB);
  // SA.attack();
  
  //Plus takeDamage is not change Message.
  // SA.takeDamage(100);
}