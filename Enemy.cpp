#include "Enemy.h"
#include "Player.h"
#include <Novice.h>
#include <corecrt_math.h>
//int Enemy::isAlive = 1;
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
	/*distance = sqrtf(powf(enemyPosX_ - bullet_->bulletPosX_,2) + powf(enemyPosY_ - bullet_->bulletPosY_, 2));
	if (distance <= radius_ + bullet_->bulletRadius_) {
		isAlive = 0;
	}*/

	enemyPosX_ += speed_;
	if (enemyPosX_ <= 20 || enemyPosX_ >= 1260) {
		speed_ *= -1;
	}
}

void Enemy::Draw() {
	if (isAlive) {
		Novice::DrawEllipse(static_cast<int>(enemyPosX_), static_cast<int>(enemyPosY_),
			radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
	Novice::ScreenPrintf(20, 20, "is Alive %d", isAlive);

}

//void Enemy::Draw2() {
//	Novice::DrawEllipse(enemyPosX_, enemyPosY_,
//		radius_, radius_, 0.0f, WHITE, kFillModeSolid);
