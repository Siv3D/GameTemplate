
# pragma once
# include "Common.hpp"

// タイトルシーン
class Title : public MyApp::Scene
{
private:

	Rect m_startButton = Rect(Arg::center = Scene::Center().movedBy(0, 0), 300, 60);
	Transition m_startTransition = Transition(0.4s, 0.2s);

	Rect m_exitButton = Rect(Arg::center = Scene::Center().movedBy(0, 100), 300, 60);
	Transition m_exitTransition = Transition(0.4s, 0.2s);

public:

	Title(const InitData& init);

	void update() override;

	void draw() const override;
};
