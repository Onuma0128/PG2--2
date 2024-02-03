#include "Game.h"

void Game::Initalize()
{
	scene = Title;
	SceneGH_[0] = Novice::LoadTexture("./Sprite/GameClear.png");
	SceneGH_[1] = Novice::LoadTexture("./Sprite/GameOver.png");
	SceneGH_[2] = Novice::LoadTexture("./Sprite/Title.png");
	player_ = new Player();
	enemy_ = new Enemy();

	player_->Initalize();
	enemy_->Initalize();
}

void Game::Update(char* keys, char* preKeys)
{
	switch (scene)
	{
	case Game::Title:
		if (keys[DIK_RETURN]) {
			scene = MainGame;
		}
		break;
	case Game::MainGame:
		//プレイヤーの更新処理
		player_->Update(keys, preKeys);
		//敵の更新処理
		enemy_->Update();
		//敵とプレイヤーの当たり判定
		playerEnemyCollision();
		//敵とプレイヤーの弾の当たり判定
		playerBulletEnemyCollision();
		//敵の弾とプレイヤーの当たり判定
		enemyBulletPlayerCollision();
		//プレイヤーの弾と敵の弾の当たり判定
		playerBulletEnemyBulletCollision();

		//プレイヤーが死んだら
		if (player_->GetPlayer().HP == 0) {
			scene = GameOver;
		}
		//敵が死んだら
		if (enemy_->GetEnemy().HP == 0) {
			scene = GameClear;
		}

		break;
	case Game::GameClear:
		//Nキーを押したらタイトルへ行き、初期化
		if (keys[DIK_N]) {
			scene = Title;
			player_->Initalize();
			enemy_->Initalize();
		}
		break;
	case Game::GameOver:
		//Nキーを押したらタイトルへ行き、初期化
		if (keys[DIK_N]) {
			scene = Title;
			player_->Initalize();
			enemy_->Initalize();
		}
		break;
	default:
		break;
	}
}

void Game::Draw()
{
	switch (scene)
	{
	case Game::Title:
		Novice::DrawSprite(0, 0, SceneGH_[2], 1, 1, 0.0f, WHITE);
		break;
	case Game::MainGame:
		//プレイヤーの描画処理
		player_->Draw();
		//敵の描画処理
		enemy_->Draw();
		break;
	case Game::GameClear:
		Novice::DrawSprite(0, 0, SceneGH_[0], 1, 1, 0.0f, WHITE);
		break;
	case Game::GameOver:
		Novice::DrawSprite(0, 0, SceneGH_[1], 1, 1, 0.0f, WHITE);
		break;
	default:
		break;
	}
}

void Game::playerEnemyCollision()
{
	if (player_->GetPlayer().Position.x < enemy_->GetEnemy().Position.x + enemy_->GetEnemy().Width &&
		enemy_->GetEnemy().Position.x < player_->GetPlayer().Position.x + player_->GetPlayer().Width) {
		if (player_->GetPlayer().Position.y < enemy_->GetEnemy().Position.y + enemy_->GetEnemy().Height &&
			enemy_->GetEnemy().Position.y < player_->GetPlayer().Position.y + player_->GetPlayer().Height) {
			if (player_->GetPlayer().isAlive && enemy_->GetEnemy().isAlive) {
				player_->SetPlayerIsAlive(false);
				player_->SetPlayerHP(1, 1);
			}
		}
	}
}

void Game::playerBulletEnemyCollision()
{
	for (int i = 0; i < kBulletNum; i++) {
		if (player_->playerBullet_[i].Position.x < enemy_->GetEnemy().Position.x + enemy_->GetEnemy().Width &&
			enemy_->GetEnemy().Position.x < player_->playerBullet_[i].Position.x + player_->playerBullet_[i].Width) {
			if (player_->playerBullet_[i].Position.y < enemy_->GetEnemy().Position.y + enemy_->GetEnemy().Height &&
				enemy_->GetEnemy().Position.y < player_->playerBullet_[i].Position.y + player_->playerBullet_[i].Height) {
				if (enemy_->GetEnemy().isAlive) {
					player_->playerBullet_[i].isAlive = false;
					player_->playerBullet_[i].Position.x = -10;
					player_->playerBullet_[i].Position.y = -10;
					enemy_->SetEnemyIsAlive(false);
					enemy_->SetEnemyHP(1, 1);
				}
			}
		}
	}
}

void Game::enemyBulletPlayerCollision()
{
	if (player_->GetPlayer().Position.x < enemy_->enemyBullet_.Position.x + enemy_->enemyBullet_.Width &&
		enemy_->enemyBullet_.Position.x < player_->GetPlayer().Position.x + player_->GetPlayer().Width) {
		if (player_->GetPlayer().Position.y < enemy_->enemyBullet_.Position.y + enemy_->enemyBullet_.Height &&
			enemy_->enemyBullet_.Position.y < player_->GetPlayer().Position.y + player_->GetPlayer().Height) {
			if (player_->GetPlayer().isAlive && enemy_->enemyBullet_.isAlive) {
				player_->SetPlayerIsAlive(false);
				player_->SetPlayerHP(1, 1);
				enemy_->enemyBullet_.isAlive = false;
				enemy_->enemyBullet_.Position.x = -100;
				enemy_->enemyBullet_.Position.y = -100;
			}
		}
	}
}

void Game::playerBulletEnemyBulletCollision()
{
	for (int i = 0; i < kBulletNum; i++) {
		if (player_->playerBullet_[i].Position.x < enemy_->enemyBullet_.Position.x + enemy_->enemyBullet_.Width &&
			enemy_->enemyBullet_.Position.x < player_->playerBullet_[i].Position.x + player_->playerBullet_[i].Width) {
			if (player_->playerBullet_[i].Position.y < enemy_->enemyBullet_.Position.y + enemy_->enemyBullet_.Height &&
				enemy_->enemyBullet_.Position.y < player_->playerBullet_[i].Position.y + player_->playerBullet_[i].Height) {
				player_->playerBullet_[i].isAlive = false;
				player_->playerBullet_[i].Position.x = -10;
				player_->playerBullet_[i].Position.y = -10;
				enemy_->enemyBullet_.isAlive = false;
				enemy_->enemyBullet_.Position.x = -100;
				enemy_->enemyBullet_.Position.y = -100;
			}
		}
	}
}
