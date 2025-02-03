#pragma once
#include "Bullet.h"

class Player {
public:

	Bullet* bullet_;
	int playerPosX_;
	int playerPosY_;
	int playerRadius_;
	int playerSpeed_;

	/// <summary>
	/// コンストラクター
	/// </summary>
	Player();

	/// <summary>
	/// ディストラクター
	/// </summary>
	~Player();

	/// <summary>
	/// 移動と発射処理
	/// </summary>
	/// <param name="keys">キー入力受け取り</param>
	/// <param name="preKeys">キー入力受け取り</param>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();
};

