# include "Game.hpp"

Game::Game(const InitData& init)
	: IScene{ init }
{
	for (int32 y = 0; y < 5; ++y)
	{
		for (int32 x = 0; x < (800 / BrickSize.x); ++x)
		{
			m_bricks << Rect{ (x * BrickSize.x), (60 + y * BrickSize.y), BrickSize };
		}
	}
}

void Game::update()
{
	// ボールを移動させる
	m_ball.moveBy(m_ballVelocity * Scene::DeltaTime());

	// ブロックを順にチェックする
	for (auto it = m_bricks.begin(); it != m_bricks.end(); ++it)
	{
		// ブロックとボールが交差していたら
		if (it->intersects(m_ball))
		{
			// ブロックの上辺、または底辺と交差していたら
			if (it->bottom().intersects(m_ball) || it->top().intersects(m_ball))
			{
				m_ballVelocity.y *= -1;
			}
			else // ブロックの左辺または右辺と交差していたら
			{
				m_ballVelocity.x *= -1;
			}

			// ブロックを配列から削除する（イテレータは無効になる）
			m_bricks.erase(it);

			m_brickSound.playOneShot(0.5);

			++m_score;

			break;
		}
	}

	// 天井にぶつかったら
	if ((m_ball.y < 0) && (m_ballVelocity.y < 0))
	{
		m_ballVelocity.y *= -1;
	}

	// 左右の壁にぶつかったら
	if (((m_ball.x < 0) && (m_ballVelocity.x < 0))
		|| ((800 < m_ball.x) && (0 < m_ballVelocity.x)))
	{
		m_ballVelocity.x *= -1;
	}

	// パドルにあたったらはね返る
	if (const Rect paddle = getPaddle();
		(0 < m_ballVelocity.y) && paddle.intersects(m_ball))
	{
		// パドルの中心からの距離に応じてはね返る方向を変える
		m_ballVelocity = Vec2{ (m_ball.x - paddle.center().x) * 10, -m_ballVelocity.y }.setLength(BallSpeed);
	}

	// 画面外に出るか、ブロックが無くなったら
	if ((600 < m_ball.y) || m_bricks.isEmpty())
	{
		// タイトル画面へ
		changeScene(State::Title);

		getData().lastScore = m_score;
	}
}

void Game::draw() const
{
	Scene::SetBackground(ColorF{ 0.2 });

	// すべてのブロックを描画する
	for (const auto& brick : m_bricks)
	{
		brick.stretched(-1).draw(HSV{ brick.y - 40 });
	}

	// ボールを描く
	m_ball.draw();

	// パドルを描く
	getPaddle().rounded(3).draw();

	// マウスカーソルを非表示にする
	Cursor::RequestStyle(CursorStyle::Hidden);

	// スコアを描く
	FontAsset(U"Bold")(m_score).draw(24, Vec2{ 400, 16 });
}

Rect Game::getPaddle() const
{
	return{ Arg::center(Cursor::Pos().x, 500), 60, 10 };
}
