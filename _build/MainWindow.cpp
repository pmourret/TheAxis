#include "MainWindow.h"

#include <raylib.h>

#include "ObstacleRect.h"


int main(int argc, char* argv[])
{
    // Appel de la methode InitWindow permettant la creation de la fenetre principale
    InitWindow(GetScreenWidth(), GetScreenHeight(), "RayLib tutorial");
    ToggleFullscreen();
    
    int score = 0 ;
    bool colidedAxe = false;
    
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        counter += 1;
        BeginDrawing();
            ClearBackground(BLACK);
        if (colidedAxe)
        {
            DrawText("Game Over!",560, 450, 150, RED);
            DrawText(TextFormat("Your score : %d", score),700, 600, 75, RED);
        }
        else
        {
            score += 1;
            DrawText(TextFormat("Score : %d", score), 10,10,20,RED);
            leftEdgeX = centerX - radius;
            rightEdgeX = centerX + radius;
            upperEdgeY = centerY - radius;
            bottomEdgeY = centerY + radius;
            

            rectangleBlue.updateHitbox();
            rectangleGreen.updateHitbox();
            rectangleYellow.updateHitbox();

            colidedAxe = rectangleBlue.detectCollision(leftEdgeX,rightEdgeX,upperEdgeY,bottomEdgeY,colidedAxe) || 
            rectangleYellow.detectCollision(leftEdgeX,rightEdgeX,upperEdgeY,bottomEdgeY,colidedAxe) ||
            rectangleGreen.detectCollision(leftEdgeX,rightEdgeX,upperEdgeY,bottomEdgeY,colidedAxe) ||
            rectangleRed.detectCollision(leftEdgeX,rightEdgeX,upperEdgeY,bottomEdgeY,colidedAxe) ;
            
            
            DrawCircle(centerX, centerY, radius, RED);


            rectangleGreen.createRectangle();
            rectangleYellow.createRectangle();
            rectangleBlue.createRectangle();
            rectangleRed.createRectangle();
            //rectangleGreen.move(false);
            rectangleGreen.randomMove();
            rectangleYellow.move(false);
            rectangleBlue.move(true);
            rectangleRed.move(false);
            
            

            if(counter >= 120)
            {
                counter = rectangleGreen.randomShape(counter, 0,100, 300);
                counter = rectangleBlue.randomShape(counter, 1,60, 300);
                counter = rectangleYellow.randomShape(counter, 0, 100,250);
                counter = rectanglePurple.randomShape(counter,0,300,550);

            }

            if (score >= 500)
            {
                rectanglePurple.createRectangle();
                rectanglePurple.move(true);
                rectanglePurple.updateHitbox();

                colidedAxe = rectangleBlue.detectCollision(leftEdgeX,rightEdgeX,upperEdgeY,bottomEdgeY,colidedAxe) || 
                             rectangleYellow.detectCollision(leftEdgeX,rightEdgeX,upperEdgeY,bottomEdgeY,colidedAxe) ||
                             rectangleGreen.detectCollision(leftEdgeX,rightEdgeX,upperEdgeY,bottomEdgeY,colidedAxe) ||
                             rectanglePurple.detectCollision(leftEdgeX,rightEdgeX,upperEdgeY,bottomEdgeY,colidedAxe) ||
                             rectangleRed.detectCollision(leftEdgeX,rightEdgeX,upperEdgeY,bottomEdgeY,colidedAxe);
            }
 


            
            /*
             * Deplacement vers la droite de 10 pixels
             */
            if(IsKeyDown(KEY_D) && centerX < (GetScreenWidth() - radius)){centerX = centerX + 10;}
            /*
             * Deplacement vers la gauche de 10 pixels
             */
            if (IsKeyDown(KEY_A) && centerX > 0 + radius){centerX = centerX - 10;}
            /*
             * Deplacement vers le haut de 10 pixels
             */
            if (IsKeyDown(KEY_W) && centerY > 0 + radius){centerY = centerY - 10;}
            /*
             * Deplacement vers le bas de 10 pixels 
             */
            if (IsKeyDown(KEY_S) && centerY < (GetScreenHeight() - radius)){centerY = centerY + 10 ;}
            /*
             * Agrandissement du rayon de 2 pixels
             */
            if(IsKeyDown(KEY_KP_ADD)){radius = radius + 2;}
            /*
             * Retrecissement du rayon de 2 pixels
             */
            if(IsKeyDown(KEY_KP_SUBTRACT)){radius = radius - 2;}
            /*
             * Deplacement sur la diagonale haute droite de 5 pixels
             */
            if(IsKeyDown(KEY_E)
                && centerY > 0
                && centerX > 0)
            {
                centerY = centerY - 7;
                centerX = centerX + 7;
            }
            /*
             * Deplacement sur la diagonale gauche de 5 pixels
             */
            if(IsKeyDown(KEY_Q)
                && centerX > 0
                && centerY > 0)
            {
                centerX = centerX - 7;
                centerY = centerY - 7;
            }
        }

        EndDrawing();
    }
    return 0;
}

