/*
** EPITECH PROJECT, 2019
** pool
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include "Datetime.hpp"
#include "Host.hpp"
#include "Kernel.hpp"
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Cpu.hpp"
#include "Ram.hpp"

class Sfml : public IMonitorDisplay
{
  public:
    Sfml();
    ~Sfml();

    void addModule(const std::string &);
    void deleteModule(const std::string &);

    void displayWallPaper(sf::RenderWindow &window);
    void displayTitle(sf::RenderWindow &window);
    void displayButton(sf::RenderWindow &window);
    void displayModuleHost(sf::RenderWindow &window);
    void displayModuleDate(sf::RenderWindow &window);
    void displayModuleKernel(sf::RenderWindow &window);
    void displayModuleCpu(sf::RenderWindow &window);
    void displayModuleRam(sf::RenderWindow &window);

    void InitWindow();

  protected:
  private:
    sf::Texture _texture;
    sf::Font _font;
    sf::Font _titleFont;
    sf::Text _text;
    sf::Text _title;
};

#endif /* !SFML_HPP_ */
