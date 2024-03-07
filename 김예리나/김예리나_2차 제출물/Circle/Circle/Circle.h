#pragma once
#include <windowsx.h> 

#include "resource.h"
#include "DrawCircle.h"
#include "LinaList.h"

int x, y;

void Loop();

DrawCircle* draw;
DrawCircle* draw2;
LinaList<DrawCircle*> list;
