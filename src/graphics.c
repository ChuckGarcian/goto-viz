#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <bits/pthreadtypes.h>

#include "raylib.h"
#include "graphics.h"

#define WD_K 32
#define CELL_SIZE 16
#define SCRNW ((512 * 3) + 100)
#define SRCHT 512
#define FPS 1

/* Matric Size */
#define WD_COLS 32
#define WD_ROWS 32

/* Submatrices Block Size */
#define MR 2
#define NR 2
#define KC 4
#define MC 4 
#define NC 8

int pause;

void *handleKeyInput (void *ptr);
void gemm();

static void drawBlock(int col, int row, int posX, int posY, int scaleC, int scaleR, Color color);
static void drawGrid(size_t posx, size_t posy, Color color);

int main(void)
{
  InitWindow(SCRNW, SRCHT, "Agent Simulation");
  SetTargetFPS(FPS);
  pause = 0;

  pthread_t thread_id; 
  pthread_create(&thread_id, NULL, handleKeyInput, NULL);

  for (int j = 0; j < WD_COLS; j += NC) 
  {
    for (int p = 0; p < WD_K; p += KC) 
    {
      for (int i = 0; i < WD_ROWS; i += MC)  
      {
        
        
        while (pause == 1) 
        {
          BeginDrawing();         
          DrawText("PAUSED", 0, 10, 100, RED);
          EndDrawing();          
        }
        
        BeginDrawing();         
        ClearBackground(RAYWHITE);

        drawBlock(j, 0, 0, 0, NC, 32, GRAY);
        drawBlock(j, i, 0, 0, NC, MC, BLACK);
        drawGrid(0, 0, BLACK);

        drawBlock(p, 0, 34, 0, KC, 32, SKYBLUE);
        drawBlock(p, i, 34, 0, KC, MC, DARKBLUE);
        drawGrid(34, 0, DARKBLUE);
        
        drawBlock(j, 0, 68, 0, NC, 32, GREEN);
        drawBlock(j, p, 68, 0, NC, KC, DARKGREEN);
        drawGrid(68, 0, DARKGREEN);
        EndDrawing();         
      }
    }
  }

  CloseWindow();
  return 0;
}

static void drawBlock(int col, int row, int posX, int posY, int scaleC, int scaleR, Color color)
{
    DrawRectangle((col + posX) * CELL_SIZE, (row + posY) * CELL_SIZE, scaleC * CELL_SIZE, scaleR * CELL_SIZE, color);
}

static void drawGrid(size_t posx, size_t posy, Color color)
{
  for (int col = 0; col < WD_COLS; col++)
  {
    for (int row = 0; row < WD_ROWS; row++)
    {
      DrawRectangleLines((posx + col) * CELL_SIZE, (posy + row) * CELL_SIZE, CELL_SIZE, CELL_SIZE, color);
    }
  }
}

void *handleKeyInput (void *ptr)
{
 while (1) 
 {
  if (IsKeyPressed(KEY_SPACE)) 
      pause = (pause == 0) ? 1 : 0;
  else if (IsKeyPressed(KEY_Q))
      exit(0);
 }
}

void gemm() 
{
  for (int jr = 0; jr < NC; jr += NR) 
  {
    for (int ir = 0; ir < MC; ir += MR) 
    {
      // Empty loop body
    }
  }
}

