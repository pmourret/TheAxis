#pragma once

#include "raylib.h"
/*
 * Cette classe definit l'objet rectangle
 */
class ObstacleRect
{
public:
    ObstacleRect(int rectHeight, int rectWidth, int rectPox, int rectPoy,int speed, int travelX, int travelY, Color color) ;
    int move(bool reverse) ;
    void randomMove();
    void createRectangle();
    int randomShape(int counter, int side, int limitMin, int limitMax);
    void updateHitbox();
    bool detectCollision(int leftCircleEdgeX, int rightCicrleEdgeX, int upperCircleEdgeY, int bottomCircleEdgeY);
    void detectCollisionRectangle(ObstacleRect obstacleRect) ;
    // Getters
    int getRectHeight();
    int getRectWidth();
    int getRectSpeed();
    int getLeftAxeX();
    int getRightAxeX();
    int getUpperAxeY();
    int getBottomAxeY();
    int getPox();
    int getPoy();
    //Setters
    void set_rect_heigth(int rectHeight);
    void set_rect_width(int rectWidth);
    void set_speed(int speed);
    void setLeftAxeX(int lAxeX);
    void setRightAxeX(int rAxeX);
    void setUpperAxeY(int upperAxeY);
    void setBottomAxeY(int bottomAxeY);
    
protected:
    int rectHeight;
    int rectWidth;
    int rectPox;
    int rectPoy;
    int speed;
    Color color;
    
    int leftAxeX;
    int rightAxeX;
    int upperAxeY;
    int bottomAxeY;

    int travelX;
    int travelY;
};
