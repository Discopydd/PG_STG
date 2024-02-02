#pragma once
#include "Novice.h"
#include "Struct.h"

class BulletClass {
public:
	BulletClass();
	Bullet* GetBulletPos();
	static int BulletTime;
	void BulletDraw();
	void Reset();
	void BulletUpdate(char* keys,Player player);

private:
	Bullet bullet[7];
	
	
};