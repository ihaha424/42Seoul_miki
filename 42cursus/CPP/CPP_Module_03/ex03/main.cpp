/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:04:18 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/11 16:13:37 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
  //Make Trap
  DiamondTrap DA("D_A");
  FragTrap    FA("F_A");
  ScavTrap    SA("S_A");

  //Message Off
  DA.changeFlag();
  FA.changeFlag();
  SA.changeFlag();
  std::cout << std::endl;

  //Action1
  std::cout << "DA_HitPoints: " << DA.getHitPoints() << std::endl;
  std::cout << "FA_HitPoints: " << FA.getHitPoints() << std::endl;
  std::cout << std::endl;
  std::cout << "DA_EnergyPoints: " << DA.getEnergyPoints() << std::endl;
  std::cout << "SA_EnergyPoints: " << SA.getEnergyPoints() << std::endl;
  std::cout << std::endl;
  std::cout << "DA_AttackDamage: " << DA.getAttackDamage() << std::endl;
  std::cout << "FA_AttackDamage: " << FA.getAttackDamage() << std::endl;
  std::cout << std::endl;
  DA.attack("Player");
  SA.attack("Player");
  std::cout << std::endl;

  //Action2
  DA.whoAmI();
  std::cout << std::endl;
}