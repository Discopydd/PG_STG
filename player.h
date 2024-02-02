#pragma once
#include "Novice.h"
#include "Struct.h"
#include <math.h>
class PlayerClass {
public:
	PlayerClass();
	~PlayerClass();

	Player* GetPlayertPos();
	void PlayerDraw();
	void Reset();
	void CheckEnemyCollision(Enemy enemy);
	void PlayerUpdate(char* keys);
	

private:
	Player player;
	
};