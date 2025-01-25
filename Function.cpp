//
//  function.cpp
//  Game of Life
//
//  Created by Seth on 1/20/25.
//

#include "Function.h"


vector<bool> board(10000, false);
bool isPaused  = true;

/***********************************
 * RESET
 * param:
 * set live cells to beehive pattern as default
 *****************************************************/
void reset(vector<bool> &pboard)
{
   pboard.assign(10000, false);
   pboard[4950] = true;
   pboard[4951] = true;
   pboard[5049] = true;
   pboard[5052] = true;
   pboard[5150] = true;
   pboard[5151] = true;
}

/***********************************
 * INTERACT
 * param:
 * the main game logic
 *****************************************************/
void interact(int position, vector<bool>& pboard, vector<bool>& nextBoard)
{
    vector<bool> neighbors;

    // initiate neighbors for game logic
    for (int pos : {position - 101, position - 100, position - 99, position - 1, position + 1, position + 99, position + 100, position + 101})
    {
        if (0 <= pos && pos < 10000)
            neighbors.push_back(pboard[pos]);
    }

    // perform the game logic
    int live = countLiveNeighbors(neighbors);

    // Apply the game of life rules and set the nextBoard state
    if (pboard[position] == true)
    {
        nextBoard[position] = (live == 2 || live == 3);
    }
    else
    {
        nextBoard[position] = (live == 3);
    }
}

/***********************************
 * COUNT LIVE NEIGHBORS
 * param:
 * return: the number of live cells around the current cell
 *****************************************************/
int countLiveNeighbors(vector<bool> neighbors)
{
   int count = 0;
   for (bool neighbor: neighbors)
   {
      if (neighbor == true)
         count ++;
   }
   return count;
}

/***********************************
 * NORMALIZE CELL  SIZE
 * param: y: scren coord; windowHeight: height of the window
 * return: coord y of the type float where 0 is the center
 *****************************************************/
inline float normalizeCellSize()
{
   return 2.0 * CELL_SIZE_PIXEL / WINDOW_WIDTH_PIXEL;
}

/***********************************
 * XY TO INDEX
 * Helper function to convert 2D coordinates to 1D index
 *****************************************************/
inline int xyToIndex(int x, int y) {
    return y * GRID_SIZE + x;
}

/***********************************
 * PATTERN 1194P4H1V0
 *****************************************************/
void pattern119P4H1V0(std::vector<bool>& pboard) {
    pboard.assign(GRID_SIZE * GRID_SIZE, false);

    int startX = GRID_SIZE / 2 - 10; // Adjust starting position as needed
    int startY = GRID_SIZE / 2 - 5;  // Adjust starting position as needed

    // Define the pattern relative to the starting position
    int pattern[][2] = {
        {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8,0},
        {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1},
        {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2},
        {0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3},
        {0, 4}, {1, 4}, {2, 4}, {3, 4},
        {8,4}, {9,4}, {10,4}, {11,4},
        {9,5}, {10,5}, {11,5}, {12,5},
        {10,6}, {11,6}, {12,6}, {13,6},
        {11,7}, {12,7}, {13,7}, {14,7},
        {12,8}, {13,8}, {14,8},
        {13,9}, {14,9},
        {14,10},
        {16,0},{17,0}, {18,0}, {19,0},
        {16,1},{17,1}, {18,1}, {19,1},
        {19,2},
        {19,3},
        {19,4},
        {16,5}, {17,5}, {18,5},
        {15,6}, {16,6}, {17,6},
        {14,7}, {15,7},
        {13,8},
        {12,9}

    };
    int patternSize = sizeof(pattern) / sizeof(pattern[0]);

    for (int i = 0; i < patternSize; ++i) {
        int x = startX + pattern[i][0];
        int y = startY + pattern[i][1];

        if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
            pboard[xyToIndex(x, y)] = true;
        }
    }
}

/***********************************
 * PATTERN PULSAR
 *****************************************************/
void patternPulsar(std::vector<bool>& pboard) {
    pboard.assign(GRID_SIZE * GRID_SIZE, false);

    int centerX = GRID_SIZE / 2;
    int centerY = GRID_SIZE / 2;
    int startX = centerX - 6;
    int startY = centerY - 6;

    // Outer ring
    for (int i = 0; i < 3; ++i) {
        pboard[xyToIndex(startX + i, startY)] = true;
        pboard[xyToIndex(startX + i, startY + 5)] = true;
        pboard[xyToIndex(startX + i, startY+10)] = true;
        pboard[xyToIndex(startX + i+10, startY)] = true;
        pboard[xyToIndex(startX + i+10, startY + 5)] = true;
        pboard[xyToIndex(startX + i+10, startY+10)] = true;
    }
    for (int i = 0; i < 3; ++i) {
        pboard[xyToIndex(startX, startY+i)] = true;
        pboard[xyToIndex(startX + 5, startY+i)] = true;
        pboard[xyToIndex(startX +10, startY+i)] = true;
        pboard[xyToIndex(startX, startY+i+10)] = true;
        pboard[xyToIndex(startX + 5, startY+i+10)] = true;
        pboard[xyToIndex(startX +10, startY+i+10)] = true;
    }
    // Inner ring
        for (int i = 0; i < 3; ++i) {
        pboard[xyToIndex(startX+2 + i, startY+2)] = true;
        pboard[xyToIndex(startX+2 + i, startY+2 +5)] = true;
        pboard[xyToIndex(startX+2+i, startY+2+10)] = true;
        pboard[xyToIndex(startX+2 + i+10-4, startY+2)] = true;
        pboard[xyToIndex(startX+2 + i+10-4, startY+2 +5)] = true;
        pboard[xyToIndex(startX+2 + i+10-4, startY+2+10)] = true;
    }
    for (int i = 0; i < 3; ++i) {
        pboard[xyToIndex(startX+2, startY+2+i)] = true;
        pboard[xyToIndex(startX+2 + 5, startY+2+i)] = true;
        pboard[xyToIndex(startX+2+10-4, startY+2+i)] = true;
        pboard[xyToIndex(startX+2, startY+2+i+10-4)] = true;
        pboard[xyToIndex(startX+2 + 5, startY+2+i+10-4)] = true;
        pboard[xyToIndex(startX+2+10-4, startY+2+i+10-4)] = true;
    }

}

/***********************************
 * PATTERN TOAD
 *****************************************************/
void patternToad(std::vector<bool>& pboard) {
    pboard.assign(GRID_SIZE * GRID_SIZE, false);

    int centerX = GRID_SIZE / 2;
    int centerY = GRID_SIZE / 2;

    pboard[xyToIndex(centerX - 1, centerY)] = true;
    pboard[xyToIndex(centerX, centerY)] = true;
    pboard[xyToIndex(centerX + 1, centerY)] = true;
    pboard[xyToIndex(centerX - 2, centerY + 1)] = true;
    pboard[xyToIndex(centerX - 1, centerY + 1)] = true;
    pboard[xyToIndex(centerX, centerY + 1)] = true;
}

/***********************************
 * TO GLX
 * param: x: scren coord; windowWidth: widht of the window
 * return: coord x of the type float where 0 is the center
 *****************************************************/
inline float toGLX(float x, float windowWidth)
{
   return (2.0f * x) / windowWidth - 1.0f;
}

/***********************************
 * TO GLY
 * param: y: scren coord; windowHeight: height of the window
 * return: coord y of the type float where 0 is the center
 *****************************************************/
inline float toGLY(float y, float windowHeight)
{
   return 1.0f - (2.0f * y) / windowHeight;
}

/***********************************
 * TO GRID X
 * param: glx: openGL x coord; gridSize: size of the grid
 * return: the nth cell on a row
 *****************************************************/
inline int toGridX(float glX, int gridSize)
{
   return (int)((glX + 1.0f) * 0.5f * gridSize);
}

/***********************************
 * TO GRID Y
 * param: gly: openGL y coord; gridSize: size of the grid
 * return: the nth cell on a column
 *****************************************************/
inline int toGridY(float glY, int gridSize)
{
   return (int)((1.0f - glY) * 0.5f * gridSize);
}

/***********************************
 * KEYBOARD CALLBACK
 * this handle keyboard event
 *****************************************************/
void keyboardCallback(unsigned char key, int x, int y)
{
   if (key == ' ')
      isPaused = !isPaused;
   if (key == 49)
   {
      isPaused = true;
      patternPulsar(board);
   }
   if (key == 50)
   {
      isPaused = true;
      pattern119P4H1V0(board);
   }
   if (key == 51)
   {
      isPaused = true;
      patternToad(board);
   }
   
}

/***********************************
 * MOUSE CALLBACK
 * this handle mouse event
 *****************************************************/
void mouseCallback(int button, int state, int x, int y)
{
   if (state == GLUT_DOWN)
   {
      // convert from screen coords to openGL coords
      float glX = toGLX(x, WINDOW_WIDTH_PIXEL);
      float glY = toGLY(y, WINDOW_HEIGHT_PIXEL);
      
      if (glX >= -1.0f && glX <= 1.0f &&
          glY >= -1.0f && glY <= 1.0f)
      {
         // map glXY to grid position
         int pos = toGridX(glX, GRID_SIZE) + toGridY(glY, GRID_SIZE) * GRID_SIZE;
         if (button == GLUT_LEFT_BUTTON)
            board[pos] = !board[pos];
      }
      
   }
}

/***********************************
 * DRAW CELL
 * This function handles drawing each cell with color
 *****************************************************/
void drawCell()
{
   for (int i = 0; i < board.size(); ++i)
   {
      // Set color based on cell state
      if (board[i]) {
         glColor3f(1.0f, 1.0f, 0.0f); // Green for live cells
      } else {
         glColor3f(0.573f, 0.569f, 0.569f); // gray for dead cells
      }

      // Calculate normalized coordinates for cell position
      float left = -1.0f + (i % 100) * normalizeCellSize();
      float right = left + normalizeCellSize();
      float bottom = 1.0f - (i / 100) * normalizeCellSize(); // Flip Y-axis for OpenGL
      float top = bottom + normalizeCellSize();

      // Draw the cell as a filled square (quad)
      glBegin(GL_QUADS);
         glVertex2f(left, bottom);
         glVertex2f(right, bottom);
         glVertex2f(right, top);
         glVertex2f(left, top);
      glEnd();
   }
}

/***********************************
 * DRAW GRID
 * whatever should happen in a frame
 *****************************************************/
void drawGrid()
{
    glColor3f(0.756f, 0.756f, 0.756f); // Gray color
   glLineWidth(LINE_WIDTH_PIXEL);

    glBegin(GL_LINES);

    // Draw vertical lines
    for (int i = 0; i < GRID_SIZE; ++i) {
       float x = -1.0f + i * normalizeCellSize();
        glVertex2f(x, -1.0f); // Bottom point
        glVertex2f(x, 1.0f);  // Top point
    }

    // Draw horizontal lines
    for (int i = 0; i < GRID_SIZE; ++i) {
       float y = -1.0f + i * normalizeCellSize();
        glVertex2f(-1.0f, y); // Left point
        glVertex2f(1.0f, y);  // Right point
    }

    glEnd();
}

/***********************************
 * DISPLAY CALLBACK
 * whenever openGL render the screen, this gets called
 *****************************************************/
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   
   drawCell();
   drawGrid();
   
   glFlush();
}

/***********************************
 * TIMER
 *
 *****************************************************/
void timer(int value)
{
   if (!isPaused)
   {
      // initiate the next generation
      vector<bool> nextBoard(10000, false);
      
      for (int i = 0; i < board.size(); ++i)
         interact(i, board, nextBoard);
      
      // copy it to the main board
      board = nextBoard;
   }
      
      // Redisplay after updating (call display() again)
      glutPostRedisplay();
      
      // Call timer again to keep updating
      glutTimerFunc(100, timer, 0);
}
