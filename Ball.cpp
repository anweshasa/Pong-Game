#include "Ball.h"

//Definitions of all methods of Ball class are written below

//Constructor
Ball::Ball(float StartX, float StartY){
    m_Position.x=StartX;
    m_Position.y=StartY;
    m_Shape.setRadius(10.0);
    m_Shape.setPosition(m_Position);
}

//getPosition()
FloatRect Ball::getPosition(){
    return m_Shape.getGlobalBounds(); 
}
	
//getShape()
CircleShape Ball::getShape(){
    return m_Shape;
}
	
//getXVelocity()
float Ball::getXVelocity(){
    return m_DirectionX;
}
	
//reboundSides()
void Ball::reboundSides(){
    m_DirectionX=-m_DirectionX;
}
	
//reboundBatOrTop()
void Ball::reboundBatOrTop(){
    m_DirectionY=-m_DirectionY;
}

//reboundBottom()
void Ball::reboundBottom(){
    m_Position.x=500;
    m_Position.y=0;
    m_DirectionY=-m_DirectionY;
}

//update(Time)
void Ball::update(Time dt){
    m_Position.x+=m_DirectionX*m_Speed*dt.asSeconds();
    m_Position.y+=m_DirectionY*m_Speed*dt.asSeconds();
    m_Shape.setPosition(m_Position);
}
