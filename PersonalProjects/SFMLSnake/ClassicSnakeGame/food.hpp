//
//  food.hpp
//  SFMLSnake
//
//  Created by Alex Nelson on 8/20/20.
//  Copyright © 2020 AlexNelson. All rights reserved.
//
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>

//CIRCLE CLASS
class circle{
    //member variables
    int xPos;
    int yPos;
    sf::CircleShape apple = sf::CircleShape(8);
    bool display;
    
public:
    //constructor
    circle();
    
    //method
    sf::CircleShape getApple();
    bool getDisplay();
    void disappear();
    void killColor();
    int getXpos();
    int getYpos();
};


//FOOD CLASS
class food{
    //member variable
    circle currentApple;
    
public:
    //constructor
    food();
    
    //methods
    void draw(sf::RenderWindow &window);
    int getX();
    int getY();
    void disappear();
    void gameOver();
    
};

//HELPER FUNCTION FOR CIRCLE RANDOMIZATION
int getRandInt();
