//
//  snake.hpp
//  SFMLSnake
//
//  Created by Alex Nelson on 8/20/20.
//  Copyright © 2020 AlexNelson. All rights reserved.
//

#pragma once
#include "square.hpp"
#include "food.hpp"
#include <vector>
#include <string>
#include <iostream>


class snake{
    //member variables (private)
    std::vector<square> body;
    bool dirIsLeft;
    bool dirIsUp;
    bool dirIsDown;
    bool dirIsRight;
    int size;
  
public:
    //constructor
    snake(); //set to start in middle of screen
    
    //methods
    void draw(sf::RenderWindow &window);
    void newDir();
    void move();
    void grow();
    
    //for collision detection
    square snakeHeadPosition();
    bool aboutToEat(food apple);
    bool notTouchingBorder();
    bool notTouchingSelf();
    
    //for testing
    std::string direction();
    int getSize();
    std::string displayBody();
};
