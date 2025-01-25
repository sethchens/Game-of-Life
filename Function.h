//
//  function.h
//  Game of Life
//
//  Created by Seth on 1/20/25.
//

#include <GL/freeglut.h> // Include freeglut
#include <OpenGL/gl.h>  // OpenGL header
#include <vector>

#pragma once

using namespace std;

extern vector<bool> board;
extern bool isPaused;

/***********************************
 * GOLBAL VARIABLES GO HERE
 *****************************************************/

const int GRID_SIZE           = 100;   // one side of the grid
const float CELL_SIZE_PIXEL   = 10;
const float LINE_WIDTH_PIXEL  = 1.0;
const int WINDOW_WIDTH_PIXEL  = GRID_SIZE * 10;
const int WINDOW_HEIGHT_PIXEL = WINDOW_WIDTH_PIXEL;


/***********************************
 * FUNCTION DECLARATION
 *****************************************************/
void  reset              (vector<bool> &pboard                                       );
void  interact           (int position, vector<bool>& pboard, vector<bool>& nextBoard);
int   countLiveNeighbors (vector<bool> neighbors                                     );

// pixel, openGL coords, and grid conversion
inline float normalizeCellSize (                           );
inline float toGLX             (float x, float windowWidth );
inline float toGLY             (float y, float windowHeight);
inline int   toGridX           (float glX, int gridSize    );
inline int   toGridY           (float glY, int gridSize    );
inline int   xyToIndex         (int x, int y               );

// the callback to be registered
void keyboardCallback(unsigned char key, int x, int y    );
void mouseCallback   (int button, int state, int x, int y);
void display         (                                   );
void timer           (int value                          );

// the drawing
void drawCell();
void drawGrid();
