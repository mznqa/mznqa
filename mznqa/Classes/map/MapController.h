#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_MAP_MAPCONTROLLER_H_
#define MZNQA_CLASSES_MAP_MAPCONTROLLER_H_

class MapController
{
private:
	MapController();
	MapController(const MapController&);
	MapController& operator=(const MapController&);
public:
	static MapController* Instance();
	~MapController();
};

#endif
