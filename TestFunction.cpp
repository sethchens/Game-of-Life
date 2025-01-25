//
//  TestFunction.cpp
//  Game of Life
//
//  Created by Seth on 1/20/25.
//

#include "TestFunction.h"


/***********************************
 * TEST TO GL Y: 0
 *****************************************************/
void TestToGLY_0()
{
   // setup
   float y = 0.0;
   float glY = 10.0;
   // exercise
   glY = toGLY(y, WINDOW_HEIGHT_PIXEL);
   
   // verify
   assert(y == 0.0);
   assert(glY == 1.0);
} // teardown

/***********************************
 * TEST TO GL Y: window height
 *****************************************************/
void TestToGLY_windowHeight()
{
   // setup
   float y = WINDOW_HEIGHT_PIXEL;
   float glY = 10.0;
   // exercise
   glY = toGLY(y, WINDOW_HEIGHT_PIXEL);
   
   // verify
   assert(y = WINDOW_HEIGHT_PIXEL);
   assert(glY == -1.0);
} // teardown

/***********************************
 * TEST TO GL Y: half of window height
 *****************************************************/
void TestToGLY_halfWindowHeight()
{
   // setup
   float y = WINDOW_HEIGHT_PIXEL / 2.0;
   float glY = 10.0;
   // exercise
   glY = toGLY(y, WINDOW_HEIGHT_PIXEL);
   
   // verify
   assert(y = WINDOW_HEIGHT_PIXEL / 2.0);
   assert(glY == 0.0);
} // teardown

/***********************************
 * TEST TO GL Y: half of window height
 *****************************************************/
void TestToGLY_quarterWindowHeight()
{
   // setup
   float y = WINDOW_HEIGHT_PIXEL / 4.0;
   float glY = 10.0;
   // exercise
   glY = toGLY(y, WINDOW_HEIGHT_PIXEL);
   
   // verify
   assert(y = WINDOW_HEIGHT_PIXEL / 4.0);
   assert(glY == 0.5);
} // teardown

/***********************************
 * TEST TO GRID Y: 0
 *****************************************************/
void TestToGridY_0()
{
   // setup
   float glY = 0.0;
   int gridY = -1;
   
   // exercise
   gridY = toGridY(glY, GRID_SIZE);
   
   // verify
   assert(gridY == GRID_SIZE / 2);
} // teardown

/***********************************
 * TEST TO GRID Y: widow height
 *****************************************************/
void TestToGridY_windowHeight()
{
   // setup
   float glY = 1.0;
   int gridY = -1;
   
   // exercise
   gridY = toGridY(glY, GRID_SIZE);
   
   // verify
   assert(glY == 1.0);
   assert(gridY == 0);
} // teardown

/***********************************
 * TEST TO GRID Y: half widow height
 *****************************************************/
void TestToGridY_oneForthWindowHeight()
{
   // setup
   float glY = -0.5;
   int gridY = -1;

   // exercise
   gridY = toGridY(glY, GRID_SIZE);
   
   // verify
   assert(glY == -0.5);
   assert(gridY == 75);
} // teardown

/***********************************
 * RUN
 * where it calls all the unit tests
 *****************************************************/
void Run()
{
   // test toGLY
   TestToGLY_0();
   TestToGLY_windowHeight();
   TestToGLY_halfWindowHeight();
   TestToGLY_quarterWindowHeight();
   
   // test toGridY
   TestToGridY_0();
   TestToGridY_windowHeight();
   TestToGridY_oneForthWindowHeight();
}
