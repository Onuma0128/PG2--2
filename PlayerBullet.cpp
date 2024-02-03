#include "PlayerBullet.h"

void PlayerBullet::Initalize()
{
	for (int i = 0; i < kBulletNum; i++) {
		playerBullet_[i].Position.x = -10;
		playerBullet_[i].Position.y = -10;
		playerBullet_[i].Velocity.x = 10;
		playerBullet_[i].Velocity.y = 10;
		playerBullet_[i].Width = 10;
		playerBullet_[i].Height = 10;
		playerBullet_[i].Color = WHITE;
		playerBullet_[i].isAlive = false;
	}
	playerBulletGH_ = Novice::LoadTexture("./Sprite/playerBullet.png");
}

void PlayerBullet::Update()
{
	for (int i = 0; i < kBulletNum; i++) {
		if (playerBullet_[i].isAlive) {
			playerBullet_[i].Position.y -= playerBullet_[i].Velocity.y;
		}

		if (playerBullet_[i].Position.y < -10) {
			playerBullet_[i].isAlive = false;
		}
	}
}

void PlayerBullet::Draw()
{
	for (int i = 0; i < kBulletNum; i++) {
		if (playerBullet_[i].isAlive) {
			Novice::DrawSprite((int)playerBullet_[i].Position.x, (int)playerBullet_[i].Position.y, playerBulletGH_, 1, 1, 0.0f, playerBullet_[i].Color);
		}
	}
}
