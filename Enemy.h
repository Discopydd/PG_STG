#pragma once
#include "Novice.h"
#include "Struct.h"
#include <math.h>

class EnemyClass {
public:
	EnemyClass(float posX, float posY, float radius);

	void EnemyUpdate();
	void EnemyDraw();
	void Reset(float posX, float posY, float radius);
	void CheckBulletCollision(Bullet bullet[]);
	Enemy* GetEnemyPos();
	

private:
	Enemy enemy;
};