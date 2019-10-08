/*
** Epitech Bordeaux Promo 2022
** Gau Florian
** Host.hpp
** hpp contain class Host for stock information rush3
*/

#ifndef RAM_HPP_
# define RAM_HPP_

#include <iostream>
#include "IMonitorModule.hpp"

class Ram : virtual public IMonitorModule
{
	public:
		Ram();
		~Ram();

        void refreshInfos();
        std::string getInfos() const;

        void setActive(bool active);
        bool getActive() const;

        std::string getName() const;

	protected:

	private:
};

#endif /* !RAM_HPP_ */
