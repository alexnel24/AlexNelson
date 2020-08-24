//
//  square.hpp
//  SFMLSnake
//
//  Created by Alex Nelson on 8/20/20.
//  Copyright © 2020 AlexNelson. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>


class square{
//member variables
private:
    int xPos;
    int yPos;
    sf::RectangleShape rec;
    sf::Color color;
    
public:
//constructor
    square(int x, int y, sf::Color inputColor);
    
//methods
    int getXpos();
    int getYpos();
    sf::RectangleShape getRec();
    //for testing
    std::string getColor();
    
    void changeSquareColor(); //only applys from head to body
    void killColor();
    void changeX(int newX);
    void changeY(int newY);
};
