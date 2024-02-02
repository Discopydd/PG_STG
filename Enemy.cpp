#include "Enemy.h"

EnemyClass::EnemyClass(float posX, float posY, float radius) {
	enemy.position = {posX, posY};
	enemy.velocity = {5.0f, 0.0f};
	enemy.radius = radius;
	enemy.respawn = 0;
	enemy.isAlive = 0;
}

void EnemyClass::EnemyUpdate() {
	enemy.respawn = enemy.respawn - 1;
	if (enemy.isAlive) {
		enemy.respawn = 120;
		enemy.position.x += enemy.velocity.x;
		if (enemy.position.x > 610 - enemy.radius) {
			enemy.velocity.x = -5.0f;
		}
		if (enemy.position.x < 0 + enemy.radius) {
			enemy.velocity.x = 5.0f;
		}
	}
	if (enemy.respawn <= 0) {
		enemy.isAlive = 1;
	}
}

void EnemyClass::EnemyDraw() {
	if (enemy.isAlive) {
		Novice::DrawEllipse(
		    (int)enemy.position.x, (int)enemy.position.y, (int)enemy.radius, (int)enemy.radius,
		    0.0f, WHITE, kFillModeSolid);
	}
}

void EnemyClass::Reset(float posX, float posY, float radius) {
	enemy.position = {posX, posY};
	enemy.velocity = {5.0f, 0.0f};
	enemy.radius = radius;
	enemy.respawn = 0;
	enemy.isAlive = 0;
}

void EnemyClass::CheckBulletCollision(Bullet bullet[]) {
	for (int i = 0; i < 7; i++) {
		float a = static_cast<float>(bullet[i].position.x - enemy.position.x);
		float b = static_cast<float>(bullet[i].position.y - enemy.position.y);
		float distance = sqrtf(a * a + b * b);

		if (distance <= bullet[i].radius + enemy.radius) {
			enemy.isAlive = 0;
		}
	}
}

Enemy* EnemyClass::GetEnemyPos() { return &enemy; }
