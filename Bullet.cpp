#include"Bullet.h"
#include <iostream>
using namespace std;
int BulletClass::BulletTime;
BulletClass::BulletClass() {
	for (int i = 0; i < 7; i++) {
		bullet[i].position = {0.0f, 0.0f};
		bullet[i].velocity = {0.0f, 10.0f};
		bullet[i].isShot = 0;
	}
}
Bullet* BulletClass::GetBulletPos() { return bullet; }
void BulletClass::BulletUpdate(char* keys, Player player) {
	for (int i = 0; i < 7; i++) {
		if (BulletTime == 0) {
			if (keys[DIK_SPACE]) {
				if (bullet[i].isShot == 0) {
					bullet[i].isShot = 1;
					bullet[i].position.x = player.position.x;
					bullet[i].position.y = player.position.y;
					BulletTime = 10;
				}
			}
		}
		if (bullet[i].isShot == 1) {
			bullet[i].position.y -= bullet[i].velocity.y;
			if (bullet[i].position.y <= 0.0f) {
				bullet[i].isShot = 0;
			}
		}
	}
	if (BulletTime > 0) {
		BulletTime--;
	}
}
void BulletClass::BulletDraw() {
	for (int i = 0; i < 7; i++) {
		if (bullet[i].isShot) {
			Novice::DrawEllipse(
			    (int)bullet[i].position.x, (int)bullet[i].position.y, (int)bullet[i].radius,
			    (int)bullet[i].radius, 0.0f, WHITE, kFillModeSolid);
		}
	}
}

void BulletClass::Reset() {
	for (int i = 0; i < 7; i++) {
		bullet[i].position = {0.0f, 0.0f};
		bullet[i].velocity = {0.0f, 10.0f};
		bullet[i].isShot = 0;
	}
}
