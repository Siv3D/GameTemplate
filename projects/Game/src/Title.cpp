# include "Title.hpp"

Title::Title(const InitData& init)
	: IScene{ init }
{

}

void Title::update()
{
	// ボタンの更新
	{
		m_startTransition.update(m_startButton.mouseOver());
		m_exitTransition.update(m_exitButton.mouseOver());

		if (m_startButton.mouseOver() || m_exitButton.mouseOver())
		{
			Cursor::RequestStyle(CursorStyle::Hand);
		}
	}

	// ボタンのクリック処理
	if (m_startButton.leftClicked()) // ゲームへ
	{
		changeScene(State::Game);
	}
	else if (m_exitButton.leftClicked()) // 終了
	{
		System::Exit();
	}
}

void Title::draw() const
{
	Scene::SetBackground(ColorF{ 0.2, 0.8, 0.4 });

	// タイトル描画
	FontAsset(U"TitleFont")(U"BREAKOUT")
		.drawAt(TextStyle::OutlineShadow(0.2, ColorF{ 0.2, 0.6, 0.2 }, Vec2{ 3, 3 }, ColorF{ 0.0, 0.5 }), 100, Vec2{ 400, 100 });

	// ボタン描画
	{
		m_startButton.draw(ColorF{ 1.0, m_startTransition.value() }).drawFrame(2);
		m_exitButton.draw(ColorF{ 1.0, m_exitTransition.value() }).drawFrame(2);

		const Font& boldFont = FontAsset(U"Bold");
		boldFont(U"PLAY").drawAt(36, m_startButton.center(), ColorF{ 0.1 });
		boldFont(U"EXIT").drawAt(36, m_exitButton.center(), ColorF{ 0.1 });
	}
}
