#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(const std::string& name);
		~Zombie();

		void announce( void ){
			std::cout << getName() << " : BraiiiiiiinnnzzzZ..." << std::endl;
		}

		void setName(const std::string& zombieName){
			name = zombieName;
		};

		std::string getName(){
			return name;
		};
};


Zombie* newZombie( std::string name );

#endif
