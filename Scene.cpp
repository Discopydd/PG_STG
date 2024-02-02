#include "Scene.h"

SceneClass::SceneClass() { Scene.GameStarPos = {0.0f, 0.0f};
	Scene.GamePos = {0.0f, 0.0f};
	Scene.GameOverPos = {0.0f, 0.0f};
	SceneCut = 0;
}
void SceneClass::SceneUpdate(char* keys, char* preKeys) {
	if (SceneCut == 0 && keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
		SceneCut = 1;
	}
	if (SceneCut == 1 && keys[DIK_R] && preKeys[DIK_R] == 0) {
		SceneCut = 0;
	}
}
void SceneClass::SceneDraw() {
	switch (SceneCut) {
	case 0:
		Novice::DrawBox(
		    (int)Scene.GameStarPos.x, (int)Scene.GameStarPos.y, 1280, 720, 0.0f, BLUE,
		    kFillModeSolid);
		break;
	case 1:
		Novice::DrawBox(
		    (int)Scene.GamePos.x, (int)Scene.GamePos.y, 1280, 720, 0.0f, BLACK,
		    kFillModeSolid);
		break;
	case 2:
		Novice::DrawBox(
		    (int)Scene.GameOverPos.x, (int)Scene.GameOverPos.y, 1280, 720, 0.0f, RED,
		    kFillModeSolid);
		break;

	}

}


