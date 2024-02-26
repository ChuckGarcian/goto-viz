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

#define WD_COLS 64
#define WD_ROWS 64
#define WD_K 32

// #define CELL_SCALE 5
#define CELL_SIZE 16

#define SCRNW WD_COLS * CELL_SIZE
#define SRCHT WD_ROWS * CELL_SIZE
#define FPS 50

/* Agent data used in the agent client */
struct agent
{
  int posX;
  int posY; 
};

// static void initAgents(struct agent *agents, size_t cnt);



#define MR 1
#define NR 1

#define KC 16
#define MC 4
#define NC 4

static void drawAgents(int x, int y);
static void drawGrid (void);

int main (void)
{


  InitWindow(SCRNW, SRCHT, "Agent Simulation");
  SetTargetFPS(FPS);
  
  
  
for (int j = 0; j < WD_COLS; j = j + NC ) {
  for (int p = 0; p < WD_K; p += KC) 
  {
    for (int i = 0; i < WD_ROWS; i += MC)  
    {
      printf ("j=%d\n", j);
      for (int jr = 0; jr < NC; jr += NR) 
      {
        for (int ir = 0; ir < MC; ir += MR) 
        
        {
          
          // for (int pr = 0; pr < KC; pr += 1)          
          BeginDrawing();
          ClearBackground(RAYWHITE);
          drawGrid ();
          drawAgents(j + jr, i + ir );
          EndDrawing();
          
        }
      }
    }
  }
}
printf ("Done!\n");
  



  // // while (!WindowShouldClose())
  // {
  
  //   // Draw
  //   BeginDrawing();
  //   ClearBackground(RAYWHITE);
  //   drawGrid ();
  //   // drawAgents(agents, CNT);
  //   EndDrawing();
  // }

  CloseWindow();
  return 0;
}

/*
 * Populates emtpy array 'AGENTS' with randomly initilized agent objects 
 */    
// static void initAgents (struct agent *agents, size_t cnt)
// {
//   while (cnt--)
//   {
//     struct agent *agt = &agents[cnt];  
//     agt->my_base.posX = random_range (WD_COLS);
//     agt->my_base.posY = random_range (WD_ROWS);
    
//     agt->perceptual_radius = 20;
//     agt->action_radius = 2;
//     agt->updateAgent = &agtClientUpdate;
//   }
// }

/* 
 * Update the state of the entire system by a timestep
 */
// static void updateSystemState(struct agent *agents, size_t cnt)
// {
//   while (cnt--)
//   {
//     struct agent *agt = &agents[cnt];
//     agt->updateAgent (agt);
//   }
// }

/*
 * Draw agents array 'AGENTS' of count 'CNT' to winow
//  */
static void drawAgents(int x, int y)
{
    int size = CELL_SIZE; 
    DrawRectangle(x * CELL_SIZE,y * CELL_SIZE, size, size, BLACK);
  
}

/*
 * Draw A grid  
*/
static void drawGrid (void)
{

  for (int col = 0; col < WD_COLS; col++)
  {
    for (int row = 0; row < WD_ROWS; row++)
    {
     DrawRectangleLines (col * CELL_SIZE, row * CELL_SIZE,  CELL_SIZE, CELL_SIZE, BLACK);
    }
  }
}