#include "ObstacleRect.h"
#include "raylib.h"

/* Constructeur de la classe ObstacleRect
 *  Parametres :
 *      rectHeight -> La hauteur du rectangle sur son axe Y
 *      rectWidth -> La largeur du rectangle sur son axe X
 *      rectPox -> L'origine du rectangle sur l'axe X
 *      rectPoy -> L'origine du rectangle sur l'axe Y
 *      speed -> La vitesse de deplacement du rectangle
 *      color -> La couleur du rectangle
 */
ObstacleRect::ObstacleRect(int rectHeight, int rectWidth, int rectPox, int rectPoy,int speed, int travelX, int travelY, Color color)
{
    this->rectHeight = rectHeight;
    this->rectWidth = rectWidth;
    this->rectPox = rectPox;
    this->rectPoy = rectPoy;
    this->speed = speed;
    this->color = color;
    this->travelX = travelX;
    this->travelY = travelY;

    // Coordonnees des bords d'un rectangle
    this->leftAxeX = this->rectPox;
    this->rightAxeX = this->rectPox + this->rectWidth;
    this->upperAxeY = this->rectPoy;
    this->bottomAxeY = this->rectPoy + this->rectHeight;
}

// Getters
int ObstacleRect::getRectHeight(){return this->rectHeight;}
int ObstacleRect::getRectWidth(){return this->rectWidth;}
int ObstacleRect::getRectSpeed(){return this->speed;}
int ObstacleRect::getBottomAxeY(){return this->bottomAxeY;}
int ObstacleRect::getUpperAxeY(){return this->upperAxeY;}
int ObstacleRect::getLeftAxeX(){return this->leftAxeX;}
int ObstacleRect::getRightAxeX(){return this->rightAxeX;}
int ObstacleRect::getPox(){return this->rectPox;}
int ObstacleRect::getPoy(){return this->rectPoy;}

// Setters
void ObstacleRect::set_rect_heigth(int rectHeight){this->rectHeight = rectHeight;}
void ObstacleRect::set_speed(int speed){this->speed = speed;}
void ObstacleRect::set_rect_width(int rectWidth){this->rectWidth = rectWidth;}
void ObstacleRect::setBottomAxeY(int bottomAxeY){this->bottomAxeY = bottomAxeY;}
void ObstacleRect::setUpperAxeY(int upperAxeY){this->upperAxeY = upperAxeY;}
void ObstacleRect::setLeftAxeX(int lAxeX){this->leftAxeX =lAxeX;}
void ObstacleRect::setRightAxeX(int rAxeX){this->rightAxeX = rAxeX;}


/*
 * Cette methode permet de dessiner le rectangle 
 */
void ObstacleRect::createRectangle()
{
    DrawRectangle(this->rectPox,this->rectPoy,this->rectWidth, this->rectHeight,this->color);
}
/*
 * Cette methode permet le deplacement du rectangle sur l'axe Y 
 */
int ObstacleRect::move(bool reverse)
{
    if (reverse)
    {
        this->rectPoy += -speed;
        if(this->rectPoy > GetScreenHeight() || rectPoy < 0)
        {
            speed = -speed ;
        } 
    }else
    {
        this->rectPoy += speed;
        if(this->rectPoy > GetScreenHeight() || rectPoy < 0)
        {
            speed = -speed ;
        }
    }
    return speed;
}

int ObstacleRect::randomShape(int counter, int side, int limitMin, int limitMax)
{
    switch (side)
    {
    case 0:
        {
            int randomSize = GetRandomValue(limitMin, limitMax);
            this->set_rect_width(randomSize);
            printf("Counter (method case w) %d \n", counter);
            return counter  = 0;
        }
    case 1:
        {
            int randomSize = GetRandomValue(limitMin, limitMax);
            this->set_rect_heigth(randomSize);
            printf("Counter (method case h) %d \n", counter);
            return counter  = 0;
        }
    }
    
}

bool ObstacleRect::detectCollision(int leftCircleEdgeX, int rightCicrleEdgeX, int upperCircleEdgeY, int bottomCircleEdgeY, bool colidedAxe)
{
    if (this->getBottomAxeY() >= upperCircleEdgeY &&
        this->getUpperAxeY() <= bottomCircleEdgeY &&
        this->getRightAxeX() >= leftCircleEdgeX &&
        this->getLeftAxeX() <= rightCicrleEdgeX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ObstacleRect::updateHitbox()
{
    this->setLeftAxeX(this->getPox());
    this->setRightAxeX(this->getPox() + this->getRectWidth());
    this->setUpperAxeY(this->getPoy());
    this->setBottomAxeY(this->getPoy() + this->getRectHeight());
}

void ObstacleRect::randomMove()
{
    this->rectPox += this->travelX ;
    this->rectPoy += this->travelY ;
    if (this->rectPox > GetScreenWidth() || this->rectPox < 0)
    {
        this->travelX = -this->travelX;
    }
    if (this->rectPoy > GetScreenHeight() || this->rectPoy < 0)
    {
        this->travelY = -this->travelY;
    }
}

bool ObstacleRect::detectCollisionRectangle(ObstacleRect obstacleRect)
{
    if (this->getBottomAxeY() >= obstacleRect.getUpperAxeY() &&
    this->getUpperAxeY() <= obstacleRect.getBottomAxeY() &&
    this->getRightAxeX() >= obstacleRect.getLeftAxeX() &&
    this->getLeftAxeX() <= obstacleRect.getRightAxeX())
    {
        return true;
    }
    else
    {
        return false;
    }
}





