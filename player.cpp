#include "Player.h"

PlayerClass::PlayerClass() {
	player.position = {600.0f, 600.0f};
	player.velocity = {5.0f, 5.0f};
	player.radius = 30.0f;
	player.isAlive = 1;

}
PlayerClass::~PlayerClass() {}
void PlayerClass::PlayerUpdate(char* keys) {
	if (player.isAlive) {
		if (keys[DIK_A]) {
			player.position.x -= player.velocity.x;
		}

		if (keys[DIK_D]) {
			player.position.x += player.velocity.x;
		}

		if (keys[DIK_W]) {
			player.position.y -= player.velocity.y;
		}

		if (keys[DIK_S]) {
			player.position.y += player.velocity.y;
		}
		if (player.position.x >= 610) {
			player.position.x = 610;
		}
		if (player.position.x <= 0) {
			player.position.x = 0;
		}
		if (player.position.y <= 0) {
			player.position.y = 0;
		}
		if (player.position.y >= 690) {
			player.position.y = 690;
		}
	}
}

Player* PlayerClass::GetPlayertPos() { return &player; }

void PlayerClass::PlayerDraw() {
	if (player.isAlive) {
		Novice::DrawEllipse(
		    (int)player.position.x, (int)player.position.y, (int)player.radius, (int)player.radius,
		    0.0f, WHITE, kFillModeSolid);
	}
	
}

void PlayerClass::Reset() {
	player.position = {600.0f, 600.0f};
	player.velocity = {5.0f, 5.0f};
	player.radius = 30.0f;
}

void PlayerClass::CheckEnemyCollision(Enemy enemy) {
	float a = static_cast<float>(player.position.x - enemy.position.x);
	float b = static_cast<float>(player.position.y - enemy.position.y);
	float distance = sqrtf(a * a + b * b);

	if (distance <= player.radius + enemy.radius) {
		player.isAlive = 0;
	}
}

