#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet() {
	bulletPosX_ = -100;
	bulletPosY_ = -100;
	bulletSpeed_ = 10;
	bulletRadius_ = 16;
	isShot_ = false;
}

void Bullet::Update() {
	if (isShot_) {
		bulletPosY_ -= bulletSpeed_;

		if (bulletPosY_ <= 0) {
			isShot_ = false;
		}
	}
}

void Bullet::Draw() {
	if (isShot_) {
		Novice::DrawEllipse(bulletPosX_, bulletPosY_,
			bulletRadius_, bulletRadius_, 0.0f, WHITE, kFillModeSolid);
	}
}
