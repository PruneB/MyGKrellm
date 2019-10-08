/*
** EPITECH PROJECT, 2019
** pool
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
	#define IMONITORMODULE_HPP_

    #include <string>

class IMonitorModule
{
	public:
		virtual ~IMonitorModule() {};

        virtual void refreshInfos() = 0;
        virtual std::string getInfos() const = 0;

        virtual void setActive(bool active) = 0;
        virtual bool getActive() const = 0;

        virtual std::string getName() const = 0;

	protected:
        std::string _name;
        bool _active;
        std::string _infos;
	private:
};

#endif /* !IMONITORMODULE_HPP_ */
