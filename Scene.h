#pragma once
#include "Novice.h"
#include "Struct.h"

class SceneClass {
public:
	SceneClass();
	int SceneCut;
	void SceneDraw();
	void SceneUpdate(char* keys, char* preKeys);

	Scene Scene;
};