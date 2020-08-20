//
//  border.cpp
//  SFMLSnake
//
//  Created by Alex Nelson on 8/20/20.
//  Copyright © 2020 AlexNelson. All rights reserved.
//

#include "border.hpp"

border::border(){
    x = 5;
}

//border::border(int height, int width){
//    x = 5;
//}

void border::draw(sf::RenderWindow &window){
    for(int i = 0; i < 54; i++){
        sf::RectangleShape temp;
        temp.setSize(sf::Vector2f(15,15));
        temp.setFillColor(sf::Color(0,0,255,150));
        
        temp.setPosition(0, i * 15);
        window.draw(temp);
        
        temp.setPosition(53 * 15, i * 15);
        window.draw(temp);
        
        temp.setPosition(i * 15, 0);
        window.draw(temp);
        
        temp.setPosition(i * 15, 53 * 15);
        window.draw(temp);
    }
}
