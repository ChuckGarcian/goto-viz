/***
 * At every time step each agent 
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include<unistd.h>

#include "raylib.h"
#include "graphics.h"

#define WD_COLS 32
#define WD_ROWS 32
#define WD_K 32

// #define CELL_SCALE 5
#define CELL_SIZE 16

#define SCRNW ((512 * 3) + 100)
#define SRCHT 512
#define FPS 1

/* Agent data used in the agent client */
struct agent
{
  int posX;
  int posY; 
};

// static void initAgents(struct agent *agents, size_t cnt);



#define MR 2
#define NR 2

#define KC 4
#define MC 8
#define NC 8

static void drawBlock(int col, int row, int posX, int posY, int scaleC, int scaleR, struct Color color);
static void drawGrid (size_t posx , size_t posy,  struct Color color);


void gemm () 
{

  for (int jr = 0; jr < NC; jr += NR) 
  {
    for (int ir = 0; ir < MC; ir += MR) 
    
    {
      // for (int pr = 0; pr < KC; pr += 1)          
      
    }
  }

}

int main (void)
{


  InitWindow(SCRNW, SRCHT, "Agent Simulation");
  SetTargetFPS(FPS);
  
  

for (int j = 0; j < WD_COLS; j = j + NC ) {
  

  for (int p = 0; p < WD_K; p += KC) 
  {
    for (int i = 0; i < WD_ROWS; i += MC)  
    {
      BeginDrawing();         
      ClearBackground(RAYWHITE); //GRAY

      
      drawBlock (j, 0, 0, 0, NC, 32, GRAY);
      drawBlock (j, i, 0, 0, NC, MC, BLACK);
      drawGrid (0, 0, BLACK);

      drawBlock (p, 0, 34, 0, KC, 32, SKYBLUE);
      drawBlock (p, i, 34, 0, KC, MC, DARKBLUE);
      drawGrid (34, 0, DARKBLUE); // SKYBLUE
      
      drawBlock (j, 0, 68, 0, NC, 32, GREEN);
      drawBlock (j, p, 68, 0, NC, KC, DARKGREEN);
      drawGrid (68, 0, DARKGREEN); 
      
      EndDrawing();          
    }
  }
  
}

  

  CloseWindow();
  return 0;
}

static void drawBlock(int col, int row, int posX, int posY, int scaleC, int scaleR, struct Color color)
{
    int size = CELL_SIZE; 
  
    DrawRectangle((col + posX) * CELL_SIZE,(row + posY) * CELL_SIZE, scaleC * CELL_SIZE, scaleR * CELL_SIZE, color);
  
}

static void drawGrid (size_t posx , size_t posy,  struct Color color)
{

  for (int col = 0; col < WD_COLS; col++)
  {
    for (int row = 0; row < WD_ROWS; row++)
    {
     DrawRectangleLines ((posx + col) * CELL_SIZE, (posy + row) * CELL_SIZE,  CELL_SIZE, CELL_SIZE, color);
    }
  }
}