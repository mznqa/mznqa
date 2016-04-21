#pragma execution_character_set("utf-8")

#include "map/MapView.h"

MapView* MapView::Instance()
{
	static MapView instance;
	return &instance;
}
