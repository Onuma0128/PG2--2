#include "Player.h"

void Player::SetPlayerPosition(float posX, float posY)
{
	player_.Position.x = posX;
	player_.Position.y = posY;
}

void Player::SetPlayerIsAlive(bool isAlive)
{
	player_.isAlive = isAlive;
}

void Player::SetPlayerHP(int playerHP, int playerTime)
{
	player_.HP -= playerHP;
	playerDamageTime_ -= playerTime;
}

void Player::Initalize()
{
	player_.Position.x = 640;
	player_.Position.y = 500;
	player_.Velocity.x = 4;
	player_.Velocity.y = 4;
	player_.Width = 50;
	player_.Height = 50;
	player_.Color = WHITE;
	player_.HP = 3;
	player_.isAlive = true;
	playerDamageTime_ = 120;
	playerGH_ = Novice::LoadTexture("./Sprite/player.png");

	PlayerBullet::Initalize();
}

void Player::Update(char* keys,char* preKeys)
{
	//プレイヤーの移動処理
	if (keys[DIK_W]) {
		player_.Position.y -= player_.Velocity.y;
	}
	if (keys[DIK_A]) {
		player_.Position.x -= player_.Velocity.x;
	}
	if (keys[DIK_S]) {
		player_.Position.y += player_.Velocity.y;
	}
	if (keys[DIK_D]) {
		player_.Position.x += player_.Velocity.x;
	}
	//プレイヤーの弾の処理
	for (int i = 0; i < kBulletNum; i++) {
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !playerBullet_[i].isAlive) {
			playerBullet_[i].Position.x = player_.Position.x + 20.0f;
			playerBullet_[i].Position.y = player_.Position.y;
			playerBullet_[i].isAlive = true;
			break;
		}
	}

	PlayerBullet::Update();

	if (playerDamageTime_ < 120) {
		playerDamageTime_--;
		if (playerDamageTime_ < 0) {
			playerDamageTime_ = 120;
			player_.isAlive = true;
		}
	}
}

void Player::Draw()
{
	//プレイヤーの描画処理
	if (playerDamageTime_ % 2 == 0) {
		Novice::DrawSprite((int)player_.Position.x, (int)player_.Position.y, playerGH_, 1, 1, 0.0f, player_.Color);
		Novice::DrawBox((int)player_.Position.x, (int)player_.Position.y - 20, player_.HP * ((int)player_.Width / 3), 10, 0.0f, RED, kFillModeSolid);
		Novice::DrawBox((int)player_.Position.x, (int)player_.Position.y - 20, (int)player_.Width - 1, 10, 0.0f, BLACK, kFillModeWireFrame);
	}
	//プレイヤーの弾の描画処理
	for (int i = 0; i < kBulletNum; i++) {
		if (playerBullet_[i].isAlive) {
			PlayerBullet::Draw();
		}
	}
}

