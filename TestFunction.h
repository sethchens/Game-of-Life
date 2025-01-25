//
//  unitest.h
//  Game of Life
//
//  Created by Seth on 1/15/25.
//

#include "Function.h"
#include <cassert>

#pragma once

void Run();

// test toGLY
void TestToGLY_0();
void TestToGLY_windowHeight();
void TestToGLY_halfWindowHeight();
void TestToGLY_quarterWindowHeight();

// test toGridY
void TestToGridY_0();
void TestToGridY_windowHeight();
void TestToGridY_oneForthWindowHeight();
