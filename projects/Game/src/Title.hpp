# pragma once
# include "Common.hpp"

// タイトルシーン
class Title : public App::Scene
{
public:

	Title(const InitData& init);

	void update() override;

	void draw() const override;

private:

	RoundRect m_startButton{ Arg::center(400, 360), 300, 60, 8 };
	RoundRect m_exitButton{ Arg::center(400, 460), 300, 60, 8 };

	Transition m_startTransition{ 0.4s, 0.2s };
	Transition m_exitTransition{ 0.4s, 0.2s };
};
