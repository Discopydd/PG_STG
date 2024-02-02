#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"
#include "Scene.h"
#include <Novice.h>

const char kWindowTitle[] = "LC1C_28_リ_ヨン";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 640, 720);
	SceneClass* scene = new SceneClass();
	PlayerClass* player = new PlayerClass();
	BulletClass* bullet = new BulletClass();
	EnemyClass* enemyA = new EnemyClass(200.0f, 200.0f, 15.0f);
	EnemyClass* enemyB = new EnemyClass(300.0f, 300.0f, 20.0f);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		scene->SceneUpdate(keys,preKeys);
		if (scene->SceneCut == 1) {
			player->PlayerUpdate(keys);
			player->CheckEnemyCollision(*enemyA->GetEnemyPos());
			player->CheckEnemyCollision(*enemyB->GetEnemyPos());
			bullet->BulletUpdate(keys, *player->GetPlayertPos());
			enemyA->EnemyUpdate();
			enemyB->EnemyUpdate();
			enemyA->CheckBulletCollision(bullet->GetBulletPos());
			enemyB->CheckBulletCollision(bullet->GetBulletPos());
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		scene->SceneDraw();
		if (scene->SceneCut == 1) {
			player->PlayerDraw();
			bullet->BulletDraw();
			enemyA->EnemyDraw();
			enemyB->EnemyDraw();
		}
		if (scene->SceneCut == 0) {
			player->Reset(); 
			bullet->Reset(); 
			enemyA->Reset(200.0f, 200.0f, 15.0f); 
			enemyB->Reset(300.0f, 300.0f, 20.0f); 
		}
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete player;
	delete enemyA;
	delete enemyB;
	delete bullet;
	delete scene;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
