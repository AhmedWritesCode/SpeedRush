#include <iostream>
#include "Obstacle.hpp"
#include "Car.hpp"
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <chrono>
#include "image.hpp"

bool collision(Car a,Obstacle b);

int main()
{
    int screenWidth = 400;
    int screenHeight = 650;
    int position[3]={75,200,325};
    char array[10000];
    
    initwindow(screenWidth, screenHeight, "Simple Animation");
    
    string obstaclpath="Obstacle.jpg";
    Image obstacleImage (80,80,obstaclpath);
    string charachterpath="Car.jpg";
    Image CarImage (60,60,charachterpath);

    Car Car(position[1], 500, 30, 125, RED,screenWidth);
    Obstacle obstacles[3] = {Obstacle(position[0], -200, 40, 15, WHITE, screenHeight), Obstacle(position[1], 0, 40, 15, GREEN,screenHeight), Obstacle(position[2], -100, 40, 10, YELLOW,screenHeight)};


    while (true)
    {   
        if(!Car.isAlive())
            break;
        cleardevice();

        int ll[20];

        sprintf((char*)ll, "LIVES = %d", Car.getLives());
        outtextxy(300, 10, (char*)ll);

    //RoadLines

    setcolor(YELLOW);
    line(138, 0, 138, 700);
    line(263, 0, 263, 700);

    setcolor(WHITE);
    line(75, 0, 75, 200);
    line(75, 230, 75, 400);
    line(75, 430, 75, 600);
    line(200, 0, 200, 200);
    line(200, 230, 200, 400);
    line(200, 430, 200, 600);
    line(325, 0, 325, 200);
    line(325, 230, 325, 400);
    line(325, 430, 325, 600);
    

        // Car.draw();
        CarImage.draw(Car.getx()-30,Car.gety()-30);
        for (int i = 0; i < 3; i++)
        {
            obstacles[i].move();
            // obstacles[i].draw();
            obstacleImage.draw(obstacles[i].getx()-40,obstacles[i].gety()-40);
            if(collision(Car,obstacles[i]))
            {
                if(obstacles[i].getcollisionEnabled())
                {
                    Car.wasHit();
                    obstacles[i].setcollisionEnabled(false);
                }
            
            }
            else{obstacles[i].setcollisionEnabled(true);}
        }
        
        
        Car.scoreUpdate();
    
        sprintf(array,"SCORE = %d",Car.getScore());
        outtext(array);
        delay(50);

        if (kbhit())
        {
            char key = getch();
            if (key == 'a' || key == 'A')
            {
                Car.moveLeft(position[0]);
            }
            else if (key == 'd' || key == 'D')
            {
                Car.moveRight(position[2]);
            }
            else if (key == 'q')
            {
                break;
            }
        }
    
    }
    closegraph();

    return 0;
}

bool collision(Car a,Obstacle b)
{
    int dx = b.getx() - a.getx();
    int dy = b.gety() - a.gety();
    int distance = sqrt(dx*dx + dy*dy);
    int radius = a.getr()+b.getr();

    if(distance>=radius)
        return false;
    
    return true;
}