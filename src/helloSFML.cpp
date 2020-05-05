#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include <vector>
#include "Snake.hpp"
#include "catch.hpp"
using namespace std;


const int pixelSize = 10; // each pixel is 10 * 10
const int numRow = 160;
const int numCol = 100; // number of pixels = numRow * numCol
const int width = pixelSize * numRow; // width of the window
const int height = pixelSize * numCol; // height of the window

int direction; // direction of snake
int length = 5; // length of snake
int game = 0;


// create an array of snake to store location of each part of the snake
// 150 is the max size of the array
Snake s[100];
//vector<Snake> sVec ={};

// create a food struct
Food f;
Food f2;
Food f3;
Food f4;
Food f5;

void move() {
    // move the snake
    for (int i = length; i >0 ; i--) {
        s[i].x = s[i-1].x;
        s[i].y = s[i-1].y;
    }
}

// change snake's direction
void changeDirection() {
    if (direction == 0) {
        s[0].y += 5; // down
    }
    if (direction == 1) {
        s[0].x -= 5; // left
    }
    if (direction == 2) {
        s[0].x += 5; // right
    }
    if (direction == 3) {
        s[0].y -= 5; // up
    }
}

// when snake leaves the window, it comes from the other side
void crossWall () {
    if (s[0].x >= numRow) {
        s[0].x = 0;
    }
    if (s[0].x < 0) {
        s[0].x = numRow;
    }
    
    if (s[0].y >= numCol) {
        s[0].y = 0;
    }
    if (s[0].y < 0) {
        s[0].y = numCol;
    }
}


// when the snake hits itself, game over
void die () {
    for (int i = 1 ; i < length ; i++) {
    if (s[0].x == s[i].x && s[0].y == s[i].y) {
        game = 1;
        }
    }
    if ((s[0].x == f4.x && s[0].y == f4.y)
        || (s[0].x == f5.x && s[0].y == f5.y)) {
        game = 1;
    }
}

void appearPosition(Food& input){
    bool inbody = true;
    while (inbody){
        input.x = rand() % (numRow / 10) * 10;
        input.y = rand() % (numCol / 10) * 10;
        for(int i=0; i<length; i++){
            if(!(input.x==s[i].x && input.y == s[i].y)) inbody = false;
        }
    }
}

// function that makes the snake grow and regenerate new food
void grow() {
    // when snake hits the food, increase its length by 1
    // change the position of the food within the window
    if ((s[0].x == f.x) && (s[0].y == f.y)) {
        length += 1;
        appearPosition(f);
    }
    if ((s[0].x == f2.x) && (s[0].y == f2.y)) {
        length += 1;
        appearPosition(f2);
    }
    if ((s[0].x == f3.x) && (s[0].y == f3.y)) {
        length += 1;
        appearPosition(f3);
    }
}



int main()
{
    srand(time(0));
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(width, height), "Hungry Snake");
    
//    // Play background music
//    sf::Music music;
//    if (!music.openFromFile("./backgroundMusic.wav")){
//        cout << "Error" << endl;
//    }
//    music.play();
//    music.setLoop(true);
    
    // fill the background with texture
    sf::Texture tBackground;
    tBackground.loadFromFile("./background.jpg");
    sf::Sprite sBackground(tBackground);
    sBackground.setPosition(0,0);
    
    // create food1 with texture
    sf::Texture tDrumstick;
    tDrumstick.loadFromFile("./chicken.png");
    sf::Sprite sDrumstick(tDrumstick);
    
    // create food2 with texture
    sf::Texture tPizza;
    tPizza.loadFromFile("./pizza.png");
    sf::Sprite sPizza(tPizza);
    
    // create food3 with texture
    sf::Texture tBurger;
    tBurger.loadFromFile("./bugrer.png");
    sf::Sprite sBurger(tBurger);
    
    // create food4 with texture
    sf::Texture tFork;
    tFork.loadFromFile("./fork.png");
    sf::Sprite sFork(tFork);
    
    // create food5 with texture
    sf::Texture tKnife;
    tKnife.loadFromFile("./knife.png");
    sf::Sprite sKnife(tKnife);

    // create snake head with texture
    sf::Texture tSnakeHead;
    tSnakeHead.loadFromFile("./headDown.png");
    sf::Sprite sSnakeHead(tSnakeHead);
    
    // create snake body with texture
    sf::Texture tSnake;
    tSnake.loadFromFile("./snake.jpg");
    sf::Sprite sSnake(tSnake);
    

    // initialize food1's location
    f.x = 10;
    f.y = 10;
        
    // initialize food2's location
    f2.x = 50;
    f2.y = 30;
        
    // initialize food3's location
    f3.x = 100;
    f3.y = 60;
        
    // initialize fork's location
    f4.x = 130;
    f4.y = 40;
        
    // initialize knife's location
    f5.x = 70;
    f5.y = 80;
    
    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;
    float timer = 0;
    float timer2 = 0;
    float timer3 = 0;
    float delay = 0.1;
    float delay2 = 9;
    float delay3 = 7;
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        
        float time = clock.getElapsedTime().asSeconds();
        float time2 = clock2.getElapsedTime().asSeconds();
        float time3 = clock3.getElapsedTime().asSeconds();
        clock.restart();
        clock2.restart();
        clock3.restart();
        timer += time;
        timer2 += time2;
        timer3 += time3;
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // detect keyboard events
        if (game == 0){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != 3) {
            direction = 0;
             tSnakeHead.loadFromFile("./headDown.png");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != 2) {
            direction = 1;
             tSnakeHead.loadFromFile("./headLeft.png");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != 1) {
            direction = 2;
             tSnakeHead.loadFromFile("./headRight.png");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != 0) {
            direction = 3;
             tSnakeHead.loadFromFile("./headUp.png");
        }
        }
        
        if (timer > delay && game != 1) {
            timer = 0;
            if (delay >= 0.04) {
                delay -= 0.0001;
            }
            move();
            changeDirection();
            crossWall();
            grow();
            die();
        }
        
        if (timer2 > delay2 && game != 1) {
            timer2 = 0;
            appearPosition(f4);
        }
        
        if (timer3 > delay3 && game != 1) {
            timer3 = 0;
            appearPosition(f5);
        }
            
        // clear the window with black color
        window.clear(sf::Color::Black);
        
        //draw the background
        window.draw(sBackground);

        // draw food1
        sDrumstick.setPosition(f.x * pixelSize, f.y * pixelSize);
        sDrumstick.setScale(sf::Vector2f(0.13f, 0.13f));
        window.draw(sDrumstick);
        
        // draw food2
        sPizza.setPosition(f2.x * pixelSize, f2.y * pixelSize);
        sPizza.setScale(sf::Vector2f(0.13f, 0.13f));
        window.draw(sPizza);
        
        // draw food3
        sBurger.setPosition(f3.x * pixelSize, f3.y * pixelSize);
        sBurger.setScale(sf::Vector2f(0.13f, 0.13f));
        window.draw(sBurger);
        
        // draw the fork
        sFork.setPosition(f4.x * pixelSize, f4.y * pixelSize);
        sFork.setScale(sf::Vector2f(0.28f, 0.28f));
        window.draw(sFork);
        
        // draw the knife
        sKnife.setPosition(f5.x * pixelSize, f5.y * pixelSize);
        sKnife.setScale(sf::Vector2f(0.28f, 0.25f));
        window.draw(sKnife);
        
    
        // create the snake body (made of 4 rectangles)
        for (int i = 1; i < length ; i++) {
            sSnake.setPosition(s[i].x * pixelSize, s[i].y * pixelSize);
            sSnake.setScale(sf::Vector2f(0.1f, 0.12f));
            window.draw(sSnake);
        }
        
        // draw snake head
        if (direction == 0) {
             sSnakeHead.setPosition((s[0].x -1.5) * pixelSize, (s[0].y) * pixelSize);
        }
        if (direction == 1) {
            sSnakeHead.setPosition((s[0].x) * pixelSize, (s[0].y - 2) * pixelSize);
        }
        if (direction == 2) {
            sSnakeHead.setPosition((s[0].x) * pixelSize, (s[0].y - 2) * pixelSize);
        }
        if (direction == 3) {
            sSnakeHead.setPosition((s[0].x -1.5) * pixelSize, (s[0].y ) * pixelSize);
        }
        sSnakeHead.setScale(sf::Vector2f(0.22f, 0.22f));
        window.draw(sSnakeHead);
       
        // game == 1 (true) game over
        if (game) {
            
            sf::Texture tGameover;
            tGameover.loadFromFile("./gameover.png");
            sf::Sprite sGameover(tGameover);
            sGameover.setPosition(540,210);
            window.draw(sGameover);
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }
        // end the current frame
        window.display();
    }

    return 0;
}
