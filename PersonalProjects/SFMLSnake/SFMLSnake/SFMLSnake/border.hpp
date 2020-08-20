//
//  border.hpp
//  SFMLSnake
//
//  Created by Alex Nelson on 8/20/20.
//  Copyright © 2020 AlexNelson. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>

class border{
    int x;
  //no member variables, just a constructor and draw
    
    //constructor
public:
    border(); //default is 810 by 810
//    border(int height, int  width);
    
    //methods
public:
    void draw(sf::RenderWindow &window);
    
};
