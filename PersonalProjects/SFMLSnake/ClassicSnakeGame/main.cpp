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
#include "snake.hpp"
#include "food.hpp"
#define SCREEN_WIDTH 810
#define SCREEN_HEIGHT 810

int main(int argc, const char * argv[]) {
    
    //so food is randomized
    srand(time(NULL));

    sf::RenderWindow window( sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake Game");
    //this is how fast the snake moves
    window.setFramerateLimit(10);
         
    //create variables for the gameS
    border border;
    snake snake;
    food apple;

    
    
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
        
        //food detection
        if(snake.aboutToEat(apple)){
            food temp;
            apple = temp;
            snake.grow();
        }
        
        //allows change of direction based on arrow keys
        snake.newDir();
        
        //end game detection
        if(snake.notTouchingBorder() && snake.notTouchingSelf())
            //moves the snake
            snake.move();
        else{
            apple.gameOver();
        }

        //displaying the game frame by frame
        window.clear();

        border.draw(window);
        snake.draw(window);
        apple.draw(window);

        window.display();
        
        
    }
    return 0;
}
