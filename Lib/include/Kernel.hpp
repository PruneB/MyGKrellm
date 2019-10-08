/*
** Epitech Bordeaux Promo 2022
** Gau Florian
** Host.hpp
** hpp contain class Host for stock information rush3
*/

#ifndef KERNEL_HPP_
# define KERNEL_HPP_

#include <iostream>
#include "IMonitorModule.hpp"

class Kernel : virtual public IMonitorModule
{
	public:
		Kernel();
		~Kernel();

        void refreshInfos();
        std::string getInfos() const;

        void setActive(bool active);
        bool getActive() const;

        std::string getName() const;

	protected:
        std::string _kernel;
        std::string _version;
	private:
};

#endif /* !KERNEL_HPP_ */
