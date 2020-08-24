//
//  snake.cpp
//  SFMLSnake
//
//  Created by Alex Nelson on 8/20/20.
//  Copyright © 2020 AlexNelson. All rights reserved.
//

#include "snake.hpp"

//constructor
snake::snake(){
    body = std::vector<square>();
    
    square head = square(24, 25, sf::Color::Green);
    body.push_back(head);
    
    square prev = head;
    for(int i = 0; i < 4; i++){
        square temp = square(prev.getXpos() - 1, prev.getYpos(), sf::Color::Green);
        temp.changeSquareColor();
        body.push_back(temp);
        prev = temp;
    }
    
    dirIsLeft = false;
    dirIsUp = false;
    dirIsDown = false;
    
    dirIsRight = true;
    
    size = 5;
}

//methods
void snake::draw(sf::RenderWindow &window){
    for(square s : body){
        window.draw(s.getRec());
    }
}

void snake::newDir(){
    if(dirIsLeft | dirIsRight){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
            dirIsUp = true;
            dirIsLeft = false;
            dirIsRight = false;
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
            dirIsDown = true;
            dirIsLeft = false;
            dirIsRight = false;
        }
    }
    if(dirIsUp | dirIsDown){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
                dirIsLeft = true;
                dirIsUp = false;
                dirIsDown = false;
        }
            
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
                dirIsRight = true;
                dirIsUp = false;
                dirIsDown = false;
        }
    }
}

void snake::move(){
    
    square newHead(body[0].getXpos(), body[0].getYpos(), sf::Color::Green);

    if(dirIsRight){
        newHead.changeX(body[0].getXpos() + 1);
    } else if(dirIsLeft){
        newHead.changeX(body[0].getXpos() - 1);
    }else if(dirIsUp){
        newHead.changeY(body[0].getYpos() - 1);
    }else{newHead.changeY(body[0].getYpos() + 1);}
    
    std::vector<square> newBody;
    newBody.push_back(newHead);
    
    for(int i = 0; i < size - 1; i++){
        if(i == 0){
            body[i].changeSquareColor();
        }
        newBody.push_back(body[i]);
    }
    
    body = newBody;
}

void snake::grow(){
    size++;
}

square snake::snakeHeadPosition(){
    return body[0];
}

bool snake::aboutToEat(food apple){
    square tempHead = this->snakeHeadPosition();
    
    if(dirIsUp){
        if(apple.getX() == tempHead.getXpos() && apple.getY() == tempHead.getYpos() - 1)
            return true;
    }
    
    if(dirIsDown){
        if(apple.getX() == tempHead.getXpos() && apple.getY() == tempHead.getYpos() + 1)
            return true;
    }
    
    if(dirIsLeft){
        if(apple.getX() + 1 == tempHead.getXpos() && apple.getY() == tempHead.getYpos())
            return true;
    }
    
    if(dirIsRight){
        if(apple.getX() - 1 == tempHead.getXpos() && apple.getY() == tempHead.getYpos())
            return true;
    }
    
    return false;
}

bool snake::notTouchingBorder(){
    square tempHead = this->snakeHeadPosition();
    int x = tempHead.getXpos();
    int y = tempHead.getYpos();
    if(x == 0 || x == 53 || y == 0 || y == 53){
        for(int i = 1; i < size; i++){
            body[i].killColor();
        }
        return false;
    }
    return true;
}

bool snake::notTouchingSelf(){
    square tempHead = this->snakeHeadPosition();
    int x = tempHead.getXpos();
    int y = tempHead.getYpos();
    for(int i = 3; i < size; i++){
        if(x == body[i].getXpos() && y == body[i].getYpos()){
            for(int j = 1; j < size - 1; j++){
                if(body[j].getXpos() == x && body[j].getYpos() == y)
                    continue;
                else
                    body[j].killColor();
            }
            return false;
        }
    }
    return true;
}

//for testing purposes
std::string snake::direction(){
    if(dirIsLeft)
        return "Left";
    if(dirIsUp)
        return "Up";
    if(dirIsDown)
        return "Down";
    else
        return "Right";
}

int snake::getSize(){
    return body.size();
}

//for testing colors
std::string snake::displayBody(){
    std::string toRet = "";
    for(int i = 0; i < body.size(); i++){
        toRet += "square:" + std::to_string(i) + " color: " + body[i].getColor() + '\n';
    }
    toRet += '\n';
    return toRet;
}
