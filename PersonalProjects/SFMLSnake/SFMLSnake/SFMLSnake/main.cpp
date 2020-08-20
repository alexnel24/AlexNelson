//
//  main.cpp
//  SFMLSnake
//
//  Created by Alex Nelson on 8/20/20.
//  Copyright © 2020 AlexNelson. All rights reserved.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "square.hpp"
#include "border.hpp"
#define SCREEN_WIDTH 810
#define SCREEN_HEIGHT 810

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    sf::RenderWindow window( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), "ALEX'S SNAKE" );
    
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
        //create variables snake below
        border border;

        

        window.clear();
        //game comes next
        
        border.draw(window);
        
        window.display();
        
        
    }
    return 0;
}
