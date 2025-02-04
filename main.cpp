#include <Novice.h>
#include "Enemy.h"
#include "Player.h"
#include <corecrt_math.h>

const char kWindowTitle[] = "LC1B_25_ミヤシタツナグ_静的メンバ変数";

int Enemy::isAlive = 1;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player;
	Enemy* enemy1 = new Enemy(200.0f,200.0f,4);
	Enemy* enemy2 = new Enemy(1000.0f,500.0f, -4);

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

		if (keys[DIK_R]) {
			enemy1 = new Enemy(200.0f, 200.0f, 4);
			enemy2 = new Enemy(1000.0f, 500.0f, -4);
			Enemy::isAlive = 1;
		}

		player->Update(keys, preKeys);

		enemy1->Move();
		enemy2->Move();

		if (Enemy::isAlive) {
			enemy1->distance = sqrtf(powf(enemy1->enemyPosX_ - player->bullet_->bulletPosX_, 2) + powf(enemy1->enemyPosY_ - player->bullet_->bulletPosY_, 2));

			if (enemy1->distance <= enemy1->radius_ + player->bullet_->bulletRadius_) {
				enemy1->isAlive = 0;
			}
		}
		
		if (!Enemy::isAlive) {
			delete enemy1;
			delete enemy2;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		enemy1->Draw();
		enemy2->Draw();

		player->Draw();

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

	// ライブラリの終了
	Novice::Finalize();
	delete player;
	return 0;
}
