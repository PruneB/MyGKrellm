/*
** Epitech Bordeaux Promo 2022
** Gau Florian
** Datetime.hpp
** hpp contain class datetime for stock information rush3
*/

#ifndef DATETIME_HPP_
# define DATETIME_HPP_

#include "IMonitorModule.hpp"

class Datetime : virtual public IMonitorModule
{
	public:
		Datetime();
		~Datetime();
		void refreshInfos();

		int GetYear();
		int GetMounth();
		int GetDay();
		int GetHours();
		int GetMinutes();
		int GetSeconds();

		std::string getInfos() const;

		void setActive(bool active);
		bool getActive() const;

		std::string getName() const;

	protected:

	private:
		int _year;
		int _mounth;
		int _day;
		int _hours;
		int _minutes;
		int _seconds;
};

#endif /* !DATETIME_HPP_ */
