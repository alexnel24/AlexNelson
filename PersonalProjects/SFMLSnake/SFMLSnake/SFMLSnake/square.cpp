//
//  square.cpp
//  SFMLSnake
//
//  Created by Alex Nelson on 8/20/20.
//  Copyright © 2020 AlexNelson. All rights reserved.
//

#include "square.hpp"
    
//constructors
square::square(int x, int y, sf::Color inputColor){
    xPos = x;
    yPos = y;
    color = inputColor;
    
    sf::RectangleShape temp;
    temp.setSize(sf::Vector2f(15,15));
    temp.setFillColor(color);
    temp.setPosition(x * 15, y * 15);
    rec = temp;
}


//methods
sf::RectangleShape square::getRec(){
    return rec;
}

//only applys from head to body
void square::changeSquareColor(){
    color = sf::Color(0,255,0, 130);
    rec.setFillColor(sf::Color(0,255,0,130));
}

void square::killColor(){
    color = sf::Color::Red;
    rec.setFillColor(sf::Color::Red);
}

int square::getXpos(){
    return xPos;
}

int square::getYpos(){
    return yPos;
}

void square::changeX(int newX){
    xPos = newX;
    rec.setPosition(newX * 15, yPos * 15);
}

void square::changeY(int newY){
    yPos = newY;
    rec.setPosition(xPos * 15, newY * 15);
}

//for testing
std::string square::getColor(){
    if(color == sf::Color::Green)
        return "headColor";
    else
        return "tailColor";
}

