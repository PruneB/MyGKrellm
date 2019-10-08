/*
** EPITECH PROJECT, 2019
** pool
** File description:
** Sfml
*/

#include <algorithm>
#include "Sfml.hpp"

Sfml::Sfml() : IMonitorDisplay()
{
	this->_host = new Host;
	this->_time = new Datetime;
	this->_kernel = new Kernel;
	this->_cpu = new Cpu;
	this->_ram = new Ram;
}

Sfml::~Sfml()
{
}

void Sfml::addModule(const std::string &name)
{
	if (this->_host->getName() == name)
		this->_host->setActive(true);
	else if (this->_kernel->getName() == name)
		this->_kernel->setActive(true);
	else if (this->_time->getName() == name)
		this->_time->setActive(true);
}

void Sfml::deleteModule(const std::string &name)
{
	if (this->_host->getName() == name)
		this->_host->setActive(false);
	else if (this->_kernel->getName() == name)
		this->_kernel->setActive(false);
	else if (this->_time->getName() == name)
		this->_time->setActive(false);
}

void Sfml::InitWindow()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Resize | sf::Style::Close, settings);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		this->_time->refreshInfos();
		this->_cpu->refreshInfos();
		this->_ram->refreshInfos();
		window.clear();
		this->displayWallPaper(window);

		if (this->_host->getActive() == true) // bool active
			this->displayModuleHost(window);
		else
			this->_host->setActive(false);
		if (this->_time->getActive() == true) // bool active
			this->displayModuleDate(window);
		else
			this->_time->setActive(false);
		if (this->_kernel->getActive() == true) // bool active
			this->displayModuleKernel(window);
		else
			this->_kernel->setActive(false);
		if (this->_cpu->getActive() == true) // bool active
			this->displayModuleCpu(window);
		else
			this->_cpu->setActive(false);
		if (this->_ram->getActive() == true) // bool active
			this->displayModuleRam(window);
		else
			this->_ram->setActive(false);
		this->displayTitle(window);
		this->displayButton(window);
		window.display();
	}
}

void Sfml::displayModuleHost(sf::RenderWindow &window)
{
	if (!this->_texture.loadFromFile("image/images.png"))
	{
		// erreur...
	}
	sf::Sprite sprite(this->_texture);

	sprite.setPosition(20, 20);

	if (!this->_font.loadFromFile("./image/arial.ttf"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}
	if (!this->_titleFont.loadFromFile("./image/text.ttf"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}

	this->_title.setFont(this->_titleFont);
	this->_title.setString("Host Infos");
	this->_title.setCharacterSize(20);
	this->_title.setFillColor(sf::Color::Green);
	this->_title.setPosition(120, 70);

	this->_text.setFont(this->_font);
	this->_text.setString(this->_host->getInfos());
	this->_text.setCharacterSize(15);
	this->_text.setFillColor(sf::Color::Green);
	this->_text.setPosition(120, 150);

	window.draw(sprite);
	window.draw(this->_title);
	window.draw(this->_text);
}

void Sfml::displayModuleDate(sf::RenderWindow &window)
{
	if (!this->_texture.loadFromFile("image/images.png"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}
	sf::Sprite sprite(this->_texture);
	sprite.setPosition(20, 330);

	if (!this->_font.loadFromFile("./image/arial.ttf"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}
	if (!this->_titleFont.loadFromFile("./image/text.ttf"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}

	this->_title.setFont(this->_titleFont);
	this->_title.setString("Time");
	this->_title.setCharacterSize(20);
	this->_title.setFillColor(sf::Color::Green);
	this->_title.setPosition(120, 380);

	this->_text.setFont(this->_font);
	this->_text.setString(this->_time->getInfos());
	this->_text.setCharacterSize(15);
	this->_text.setFillColor(sf::Color::Green);
	this->_text.setPosition(120, 460);

	window.draw(sprite);
	window.draw(this->_title);
	window.draw(this->_text);
}

void Sfml::displayModuleKernel(sf::RenderWindow &window)
{
	if (!this->_texture.loadFromFile("image/images.png"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}
	sf::Sprite sprite(this->_texture);
	sprite.setPosition(20, 650);

	if (!this->_font.loadFromFile("./image/arial.ttf"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}
	if (!this->_titleFont.loadFromFile("./image/text.ttf"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}

	this->_title.setFont(this->_titleFont);
	this->_title.setString("Kernel");
	this->_title.setCharacterSize(20);
	this->_title.setFillColor(sf::Color::Green);
	this->_title.setStyle(sf::Text::Underlined);
	this->_title.setPosition(120, 700);

	this->_text.setFont(this->_font);
	this->_text.setString(this->_kernel->getInfos());
	this->_text.setCharacterSize(15);
	this->_text.setFillColor(sf::Color::Green);
	this->_text.setPosition(120, 780);

	window.draw(sprite);
	window.draw(this->_title);
	window.draw(this->_text);
}

void Sfml::displayModuleCpu(sf::RenderWindow &window)
{
	if (!this->_texture.loadFromFile("image/images.png"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}
	sf::Sprite sprite(this->_texture);
	sprite.setPosition(1400, 20);

	if (!this->_font.loadFromFile("./image/arial.ttf"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}
	if (!this->_titleFont.loadFromFile("./image/text.ttf"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}

	this->_title.setFont(this->_titleFont);
	this->_title.setString("CPU");
	this->_title.setCharacterSize(20);
	this->_title.setFillColor(sf::Color::Green);
	this->_title.setStyle(sf::Text::Underlined);
	this->_title.setPosition(1500, 70);

	this->_text.setFont(this->_font);
	this->_text.setString(this->_cpu->getInfos());
	this->_text.setCharacterSize(15);
	this->_text.setFillColor(sf::Color::Green);
	this->_text.setPosition(1450, 160);

	window.draw(sprite);
	window.draw(this->_title);
	window.draw(this->_text);
}

void Sfml::displayModuleRam(sf::RenderWindow &window)
{
	if (!this->_texture.loadFromFile("image/images.png"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}
	sf::Sprite sprite(this->_texture);
	sprite.setPosition(1400, 330);

	if (!this->_font.loadFromFile("./image/arial.ttf"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}
	if (!this->_titleFont.loadFromFile("./image/text.ttf"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}

	this->_title.setFont(this->_titleFont);
	this->_title.setString("Ram");
	this->_title.setCharacterSize(20);
	this->_title.setFillColor(sf::Color::Green);
	this->_title.setStyle(sf::Text::Underlined);
	this->_title.setPosition(1500, 380);

	this->_text.setFont(this->_font);
	this->_text.setString(this->_ram->getInfos());
	this->_text.setCharacterSize(20);
	this->_text.setFillColor(sf::Color::Green);
	this->_text.setPosition(1470, 460);

	window.draw(sprite);
	window.draw(this->_title);
	window.draw(this->_text);
}

void Sfml::displayWallPaper(sf::RenderWindow &window)
{
	if (!this->_texture.loadFromFile("./image/rm.jpg"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}
	sf::Sprite sprite(this->_texture);
	window.draw(sprite);
}

void Sfml::displayTitle(sf::RenderWindow &window)
{
	if (!this->_font.loadFromFile("./image/shlop.ttf"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}

	this->_text.setFont(this->_font);
	this->_text.setString("MyGKrellm");
	this->_text.setCharacterSize(100);
	this->_text.setFillColor(sf::Color::Green);
	this->_text.setStyle(sf::Text::Bold);
	this->_text.setPosition(1920 / 2.4, 40);
	window.draw(this->_text);
}

void Sfml::displayButton(sf::RenderWindow &window)
{
	sf::Vector2i click = sf::Mouse::getPosition(window);

	if (!this->_font.loadFromFile("./image/text.ttf"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return;
	}

	this->_text.setFont(this->_font);
	this->_text.setString("User Infos\n\n\n\nDate\n\n\n\nKernel\n\n\n\nCPU\n\n\n\nRam");
	this->_text.setCharacterSize(20);
	this->_text.setFillColor(sf::Color::Green);
	this->_text.setStyle(sf::Text::Bold);
	this->_text.setPosition(1920 / 2.4, 240);
	window.draw(this->_text);

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if ((click.x >= 800) && (click.x <= 1000) && (click.y >= 200) && (click.y <= 300))
			{
				this->_host->setActive(!this->_host->getActive());
			}
			if ((click.x >= 800) && (click.x <= 1000) && (click.y >= 300) && (click.y <= 400))
			{
				this->_time->setActive(!this->_time->getActive());
			}
			if ((click.x >= 800) && (click.x <= 1000) && (click.y >= 400) && (click.y <= 500))
			{
				this->_kernel->setActive(!this->_kernel->getActive());
			}
			if ((click.x >= 800) && (click.x <= 1000) && (click.y >= 500) && (click.y <= 600))
			{
				this->_cpu->setActive(!this->_cpu->getActive());
			}
			if ((click.x >= 800) && (click.x <= 1000) && (click.y >= 600) && (click.y <= 700))
			{
				this->_ram->setActive(!this->_ram->getActive());
			}
		}
	}
}
