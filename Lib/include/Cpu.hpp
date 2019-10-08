/*
** Epitech Bordeaux Promo 2022
** Gau Florian
** Host.hpp
** hpp contain class Host for stock information rush3
*/

#ifndef CPU_HPP_
# define CPU_HPP_

#include <iostream>
#include "IMonitorModule.hpp"

class Cpu : virtual public IMonitorModule
{
	public:
		Cpu();
		~Cpu();

        void refreshInfos();
        std::string getInfos() const;

        void setActive(bool active);
        bool getActive() const;

        std::string getName() const;

	protected:

	private:
};

#endif /* !CPU_HPP_ */
