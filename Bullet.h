#pragma once

class Bullet {
public:
	int bulletPosX_;
	int bulletPosY_;
	int bulletSpeed_;
	int bulletRadius_;
	int isShot_;

	/// <summary>
	/// コンストラクター
	/// </summary>
	Bullet();

	/// <summary>
	/// 弾が発射されたら上に動かす
	/// </summary>
	void Update();

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();
};

