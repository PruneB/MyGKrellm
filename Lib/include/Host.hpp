/*
** Epitech Bordeaux Promo 2022
** Gau Florian
** Host.hpp
** hpp contain class Host for stock information rush3
*/

#ifndef HOST_HPP_
# define HOST_HPP_

#include <iostream>
#include "IMonitorModule.hpp"

class Host : virtual public IMonitorModule
{
	public:
        Host();
        ~Host();

        std::string GetUser();
        std::string GetHost();

        void refreshInfos();
        std::string getInfos() const;

        void setActive(bool active);
        bool getActive() const;

        std::string getName() const;

	protected:

	private:
		char *_hostname;
		char *_username;

};

#endif /* !HOST_HPP_ */
