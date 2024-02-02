#pragma once
struct Vector2 {
	float x;
	float y;
};
struct Player {
	Vector2 position;
	Vector2 velocity;
	float radius;
	int isAlive;
};
struct Bullet {
	Vector2 position;
	Vector2 velocity;
	float radius = 8.0f;
	int isShot;
};
struct Enemy {
	Vector2 position;
	Vector2 velocity;
	float radius;
	int isAlive;
	int respawn;
};
struct Scene {
	Vector2 GameStarPos;
	Vector2 GamePos;
	Vector2 GameOverPos;
};