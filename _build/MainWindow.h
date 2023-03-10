#include "ObstacleRect.h"
#include "raylib.h"
// Constantes de la fenetre principale
const int width = 350;
const int heigth = 200;
const char winTitle = *"RayFrame_1" ;

// Variables relatives au cercle
int centerX = 175 ;
int centerY = 100 ;
int radius = 25 ;
int circleSpeed = 15;

// Variables relatives au bords du cercle
int leftEdgeX = centerX - radius;
int rightEdgeX = centerX + radius;
int upperEdgeY = centerY - radius;
int bottomEdgeY = centerY + radius;

// Variables relatives au rectangle
int rectHeight = GetScreenHeight();
int rectWidth = 20;
int rectPox = (GetScreenWidth() / 2) - rectWidth ;
int rectPoy = 200;
int direction = 10;

ObstacleRect rectangleGreen(20, 60, 1050, 350, 10,5,5, GREEN);
ObstacleRect rectangleYellow(350, 20, 850, 650, 10,5,5, YELLOW);
ObstacleRect rectangleBlue(60,60,299, 399,10,5,5,BLUE);
ObstacleRect rectangleRed(200,100,175,386,5,5,5,RED);
ObstacleRect rectanglePurple(120,120,1250,269,30,5,5,PURPLE);

int counter = 0;
