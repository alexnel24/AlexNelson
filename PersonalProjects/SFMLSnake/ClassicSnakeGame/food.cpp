//
//  food.cpp
//  SFMLSnake
//
//  Created by Alex Nelson on 8/20/20.
//  Copyright © 2020 AlexNelson. All rights reserved.
//

#include "food.hpp"

//CIRCLE CLASS

    //constructor
circle::circle(){
    xPos = getRandInt();
    yPos = getRandInt();
    
    apple.setPosition(xPos * 15, yPos * 15);
    apple.setFillColor(sf::Color::Red);
    
    display = true;
}
    
    //methods
sf::CircleShape circle::getApple(){
    return apple;
}

bool circle::getDisplay(){
    return display;
}

void circle::disappear(){
    display = false;
}

int circle::getXpos(){
    return xPos;
}

int circle::getYpos(){
    return yPos;
}

void circle::killColor(){
    apple.setFillColor(sf::Color(139,69,19));
}


//FOOD CLASS

    //constructor
food::food(){
    currentApple = circle();
}

    //methods
void food::draw(sf::RenderWindow &window){
    if(currentApple.getDisplay()){
        window.draw(currentApple.getApple());
    }
}

int food::getX(){
    return currentApple.getXpos();
}

int food::getY(){
    return currentApple.getYpos();
}

void food::disappear(){
    currentApple.disappear();
}

void food::gameOver(){
    currentApple.killColor();
}


//HELPER FUNCTION FOR RANDOMIZATION
int getRandInt(){
    int toRet = (rand() % 52) + 1;
    return toRet;
}


