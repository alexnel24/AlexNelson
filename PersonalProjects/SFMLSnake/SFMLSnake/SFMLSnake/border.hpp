//
//  border.hpp
//  SFMLSnake
//
//  Created by Alex Nelson on 8/20/20.
//  Copyright © 2020 AlexNelson. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "square.hpp"
#include <vector>

class border{
    //member variable
    std::vector<square> vec;
    
    //constructor
public:
    border(); //default is 810 by 810
    
    //methods
    void draw(sf::RenderWindow &window);
};
