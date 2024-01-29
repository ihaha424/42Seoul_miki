/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:04:18 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/10 18:13:07 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
  //Make 3 ClapTrap
  ClapTrap A("A");
  ClapTrap B("B"); 
  ClapTrap C("C");
  

  //Message Off
  A.changeFlag();
  B.changeFlag();
  C.changeFlag();

  //Attack Damege Setting
  A.setAttackDamage(2);
  C.setAttackDamage(9);

  //Action
  A.attack();
  for(int i = 0; i < 5; i++)
    A.attack(B);
  A.attack();
  B.attack(C);
  C.attack(A);
  A.beRepaired(100);
  C.beRepaired(100);
  C.attack(A);
  C.attack(A);
  C.attack("Player");
}