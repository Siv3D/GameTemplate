# pragma once
# include "Common.hpp"

// ゲームシーン
class Game : public App::Scene
{
public:

	Game(const InitData& init);

	void update() override;

	void draw() const override;

private:

	// ブロックのサイズ
	static constexpr Size BrickSize{ 40, 20 };

	// ボールの速さ
	static constexpr double BallSpeed = 480.0;

	// ボールの速度
	Vec2 m_ballVelocity{ 0, -BallSpeed };

	// ボール
	Circle m_ball{ 400, 400, 8 };

	// ブロックの配列
	Array<Rect> m_bricks;

	// 現在のゲームのスコア
	int32 m_score = 0;

	// ブロックを壊したときの効果音
	Audio m_brickSound{ GMInstrument::Woodblock, PianoKey::C5, 0.2s, 0.1s };

	Rect getPaddle() const;
};
