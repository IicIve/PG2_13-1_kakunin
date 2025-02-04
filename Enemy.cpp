#include "Enemy.h"
#include "Player.h"
#include <Novice.h>
#include <corecrt_math.h>
Enemy::Enemy(float posX, float posY, int speedY) {
	enemyPosX_ = posX;
	enemyPosY_ = posY;
	speed_ = speedY;
	radius_ = 20;
	distanceX = 0;
	distanceY;
	distance;
	bullet_ = new Bullet;
}

void Enemy::Move() {
	if (isAlive) {
		enemyPosX_ += speed_;
		if (enemyPosX_ <= 20 || enemyPosX_ >= 1260) {
			speed_ *= -1;
		}
	}
}

void Enemy::Draw() {
	if (isAlive) {
		Novice::DrawEllipse(static_cast<int>(enemyPosX_), static_cast<int>(enemyPosY_),
			radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
	Novice::ScreenPrintf(20, 20, "is Alive %d", isAlive);

}
