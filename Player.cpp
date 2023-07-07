#include "Player.h"
#include<assert.h>
#include<MathUtilityForText.h>

void Player::Initialize(Model* model, uint32_t textureHandle) { 
	assert(model);
	model_ = model;
	model_ = Model::Create();
	worldTransform_.scale_ = {0.5f, 0.5f, 0.5f};

	textureHandle_ = textureHandle;
	worldTransform_.Initialize();
}


void Player::Draw(ViewProjection& viewProjection) { 
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}



void Player::Update() { 
	worldTransform_.matWorld_ = MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();
}