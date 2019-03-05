//シーン雛形


# include <Siv3D.hpp> // OpenSiv3D v0.3.1
#include<HamFramework.hpp>

enum class SceneName
{
	Title,
	Game,
	Result
};

//全てのシーンからアクセスできる

struct CommonData
{
	int ini_num;
	Font font{ 50 };
};

using MyApp = SceneManager<SceneName, CommonData>;



class Title : public MyApp::Scene
{
public:

	/*
	void init()override
	{

	}
	*/

	Title(const InitData& init)
		: IScene(init)
	{
		getData().ini_num = 0;
		//getData().ini_num = 0;
	}

	

	void update()override
	{
		
		if (KeyZ.down()/*Input::KeyZ.clicked*/)
		{
			changeScene(SceneName::Game);
			getData().ini_num++;
		}
	}

	void draw()const override
	{
		Window::ClientRect().draw(Palette::Black);
		getData().font(U"TITLE", getData().ini_num).drawAt(Window::Center());
		
	}


};

class Game : public MyApp::Scene
{
public:

	Game(const InitData& init)
		: IScene(init)
	{
		
	}
	

	void update()override
	{
		if (KeyZ.down())
		{
			changeScene(SceneName::Result);
			getData().ini_num++;
		}
	}

	void draw()const override
	{
		Window::ClientRect().draw(Palette::Red);
		getData().font(U"GAME", getData().ini_num).drawAt(Window::Center());
	}


};

class Result : public MyApp::Scene
{
public:

	Result(const InitData& init)
		: IScene(init)
	{

	}
	

	void update()override
	{
		if (KeyZ.down())
		{
			changeScene(SceneName::Title);
			getData().ini_num++;
		}
	}

	void draw()const override
	{
		Window::ClientRect().draw(Palette::Blue);
		getData().font(U"GAME", getData().ini_num).drawAt(Window::Center());
	}


};






void Main()
{
	const Font font(30);

	MyApp scenemanager;

	scenemanager.add<Title>(SceneName::Title);
	scenemanager.add<Game>(SceneName::Game);
	scenemanager.add<Result>(SceneName::Result);



	while (System::Update())
	{
		if (!scenemanager.update())
		{
			break;
		}
	}
}

