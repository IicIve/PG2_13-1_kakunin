#include "Player.h"
#include <Novice.h>

Player::Player() {
	bullet_ = new Bullet;
	playerPosX_ = 300;
	playerPosY_ = 600;
	playerRadius_ = 32;
	playerSpeed_ = 8;
}

Player::~Player() {

}

void Player::Update(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		playerPosY_ -= playerSpeed_;
	}

	if (keys[DIK_A]) {
		playerPosX_ -= playerSpeed_;
	}

	if (keys[DIK_S]) {
		playerPosY_ += playerSpeed_;
	}

	if (keys[DIK_D]) {
		playerPosX_ += playerSpeed_;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		bullet_->bulletPosX_ = playerPosX_;
		bullet_->bulletPosY_ = playerPosY_;
		bullet_->isShot_ = true;
	}
	bullet_->Update();
}

void Player::Draw() {
	Novice::DrawEllipse(playerPosX_, playerPosY_,
		playerRadius_, playerRadius_, 0.0f, WHITE, kFillModeSolid);

	bullet_->Draw();

}
