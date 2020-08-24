//
//  border.cpp
//  SFMLSnake
//
//  Created by Alex Nelson on 8/20/20.
//  Copyright © 2020 AlexNelson. All rights reserved.
//

#include "border.hpp"

border::border(){
    vec = std::vector<square>();
    for(int i = 0; i < 54; i++){
        square temp = square(0, i, sf::Color(0,0,255,150));
        vec.push_back(temp);
        
        temp = square(53, i, sf::Color(0,0,255,150));
        vec.push_back(temp);
        
        temp = square(i, 0, sf::Color(0,0,255,150));
        vec.push_back(temp);
        
        temp = square(i, 53, sf::Color(0,0,255,150));
        vec.push_back(temp);
    }
}

void border::draw(sf::RenderWindow &window){
    for(square s : vec){
        window.draw(s.getRec());
    }
}
