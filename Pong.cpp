#include "Bat.h"
#include "Ball.h"
#include<SFML/Graphics.hpp>
#include<sstream>

using namespace sf;

int main(){

    //Create VideoMode object
    VideoMode vm(1920.0,1080.0);

    //Create Window
    RenderWindow window(vm,"PONG!!!",Style::Fullscreen);

    //Create Bat and set position
    Bat bat(window.getSize().x/2.0,window.getSize().y-10);

    //Create Ball and set position
    Ball ball(window.getSize().x/2.0,0);    
    
    //Create hud (heads up display) for score and lives
    Text hud;
    Font font;
    font.loadFromFile("font/DS-DIGI.TTF");
    hud.setFont(font);
    hud.setCharacterSize(75.0);
    hud.setFillColor(Color::White);
    hud.setPosition(20.0,20.0);

    int score=0;
    int lives=3;

    //Manage time
    Clock clock;
    //bool acceptInput=false;

    while(window.isOpen()){

        //handle player input to close the window (event type closed)
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed)
               window.close();
            /*if(event.type==Event::KeyReleased)
              acceptInput=true;*/   
        }

        //handle quitting game
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }


        //handle playing inputs (right and left cursor movement)
        //if(acceptInput){
            //right cursor
            if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                //if bat touches right window-side stop moving right.
               if(bat.get_Position().left+bat.get_Position().width>window.getSize().x){
                 bat.stopRight();
                }
                else{   
                     //else move right
                    bat.moveRight();           
                }
                //acceptInput=false;
            }
            else{
              // stop right movement
              bat.stopRight();
              //acceptInput=true;
            }
            
            //Left cursor
            if(Keyboard::isKeyPressed(Keyboard::Left)){
                //if bat touches left window-side stop moving left.
                if(bat.get_Position().left<0){
                    bat.stopLeft();
                }
                else{    
                       //else move left
                        bat.moveLeft();
                }
                //acceptInput=false;    
            }
            else{
                  //stop left movement
                    bat.stopLeft();
                    //acceptInput=true;            
            }
        //}

        //update time
        Time dt=clock.restart();        

        //update bat
        bat.update(dt);        

        //update ball
        ball.update(dt);

        //Handle ball hits bottom side
        if(ball.getPosition().top>=window.getSize().y){
            
            lives--;
            if(lives<1){
                score=0;
                lives=3;
            }
            ball.reboundBottom();
        }

        //Handle ball hits top side
        if(ball.getPosition().top<=0){
            score++;
            ball.reboundBatOrTop();
        }

        //Handle ball hits sound boundaries
        if(ball.getPosition().left<0 || (ball.getPosition().left+ball.getPosition().width)>window.getSize().x){
            ball.reboundSides();
        }

        //Handle ball hits the bat
        if(ball.getPosition().intersects(bat.get_Position())){
            score++;
            ball.reboundBatOrTop();
            ball.update(dt);
            bat.update(dt);
        }

        //update score message
        std::stringstream ss;
        ss << "Score: " << score <<" Lives: " <<lives;
        hud.setString(ss.str());        
        
        //draw
        window.clear();
        
        //draw bat
        window.draw(bat.get_Shape());

        //draw ball
        window.draw(ball.getShape());
        
        //draw hud
        window.draw(hud);        
        
        window.display();
    }

    return 0;
}