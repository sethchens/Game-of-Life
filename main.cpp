//
//  main.cpp
//  Game of Life
//
//  Created by Seth on 1/15/25.
//

#include "Function.h"
#include "TestFunction.h"


/***********************************
 * MAIN
 * all the magic happens here
 *****************************************************/
int main(int argc, const char ** argv)
{
   // run the unit test first
   Run();
   
   glutInit(&argc, const_cast<char**>(argv));
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize((int)WINDOW_WIDTH_PIXEL, (int)WINDOW_HEIGHT_PIXEL);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Game of Life");
   
   glClearColor(0.573f, 0.569f, 0.569f, 1.0f); // gray background, dead cells should be the same in drawCell()

   // Register callbacks
   glutTimerFunc(3000, timer, 0);
   glutKeyboardFunc(keyboardCallback);
   glutDisplayFunc(display);
   glutMouseFunc(mouseCallback);

   // Enter the main loop
   reset(board);
   glutMainLoop();
   
   return 0;
}
