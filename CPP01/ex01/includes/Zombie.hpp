#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
class Zombie
{
	private:
		std::string name;
	public:
		Zombie(const std::string& name);
		~Zombie();

		void announce( void );
		std::string getName() const;
};


Zombie* newZombie( const std::string& name );
Zombie* zombieHorde( int N, std::string name );
#endif
