#pragma once
#include "Bullet.h"
class Enemy {
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	Enemy(float posX, float posY, int speedY);

	/// <summary>
	/// 敵を動かす
	/// </summary>
	void Move();

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();

	/// <summary>
	/// 描画関数
	/// </summary>
	//void Draw2();

public:
	float enemyPosX_;
	float enemyPosY_;
	int speed_;
	int radius_;
	float distanceX;
	float distanceY;
	float distance;
	static int isAlive;
	Enemy* enemy1;
	Enemy* enemy2;
	Bullet* bullet_;
};

