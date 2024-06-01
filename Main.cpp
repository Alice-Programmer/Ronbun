# include <Siv3D.hpp> // Siv3D v0.6.14
#include <iostream>
#include <math.h>

using namespace std;



void hensati(double* pStart_Num,double* pHensati, TextEditState number)//計算元の数値の配列、偏差値を返すときの配列、キー入力から受け取る数値の個数
{
	
	long i;//ループカウンタ
	int j, tmp;//ソート
	double* Hensati;//偏差値配列
	double sum = 0; //和
	double average = 0;//平均
	double pow_average = 0;//平均の二乗
	double average_pow_sum = 0;//平均の二条の合計
	double bunsan = 0;//分散
	double Hensa = 0;
	double tyuOu=0;//中央値を作って個々に数値をいれる
	
	
	

	//和の計算
	for (i = 0; i < number; i++)//こういうとこでエラーが出る
	{
		sum = sum + pStart_Num[i];
	}

	average = sum / number;//平均の算出
	pow_average = pow(average, 2);//平均の二乗

	for (i = 0; i < number; i++)
	{
		average_pow_sum = average_pow_sum + pow(pStart_Num[i] - average, 2);//二乗の和を算出
	}

	bunsan = average_pow_sum - pow_average;//分散の算出

	Hensa = sqrt(bunsan);//偏差の算出

	for (i = 0; i < number; i++)//偏差値の算出と出力
	{
		pHensati[i] = (pStart_Num[i] - average) / Hensa * 10 + 50;
	}


	for (i = 0; i < number; i++)//ソート
	{
		for (j = i + 1; j < number; j++)
		{
			if (pStart_Num[i] > pStart_Num[j])
			{
				tmp = pStart_Num[i];
				pStart_Num[i] = pStart_Num[j];
				pStart_Num[j] = tmp;
			}
		}
	}
}


void Button(const Rect& rect, const Font& font, const String& text)
{
	if (rect.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}
	rect.draw(ColorF{ 0.3, 0.7, 1.0 });

	font(text).drawAt(40, (rect.x + rect.w / 2), (rect.y + rect.h / 2));

	
}

bool Button(const Rect& rect, const Font& font, const String& text, bool enabled)
{
	if (enabled && rect.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	if (enabled)
	{
		rect.draw(ColorF{ 0.3, 0.7, 1.0 });
		font(text).drawAt(40, (rect.x + rect.w / 2), (rect.y + rect.h / 2));
	}
	else
	{
		rect.draw(ColorF{ 0.5 });
		font(text).drawAt(40, (rect.x + rect.w / 2), (rect.y + rect.h / 2), ColorF{ 0.7 });
	}

	return (enabled && rect.leftClicked());
}

void Main()
{


	System::SetTerminationTriggers(UserAction::CloseButtonClicked);
	Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });

	const Font font{ FontMethod::MSDF, 48 };
	double accumulatedTime = 0.0;

	TextEditState te0;
	TextEditState te1{ U"数値の個数" };// デフォルトのテキストを設定する
	



	while (System::Update())
	{
		int number=0;//数値の個数
		double* Start_Num = nullptr;//配列
		Start_Num = new double[number];
		double Hensati[] = {0};
		TextEditState te1;//数値の個数を格納する変数の定義
		
		/*GUI側でStart_Numへの数値入力をする。打ち直しはなくてもいいかも*/
		hensati(Start_Num,Hensati,te1);
		/*hensati関数でソートもやっちゃうので、偶数、奇数の場合の中央値を出すプログラムをコーディング。出力もここで。*/

		


		



		Button(Rect{ 250, 400, 300, 80 }, font, U"始める");

		if (Button(Rect{ 250, 400, 300, 80 }, font, U"最初から", true))
		{
			Scene::SetBackground(ColorF(0.0, 0.5, 1.0));

			// ここに描画する内容を書く
			Circle(Cursor::Pos(), 50).draw(Palette::Orange);

			FontAsset(U"ExampleFont")(U"こんにちは、Siv3D!").draw(Arg::topCenter = Scene::Center(), Palette::Black);

			Scene::SetBackground(ColorF(0.1,0.1,0.1));
		}

		SimpleGUI::TextBox(te1, Vec2{ 100, 140 });

		

		hensati(Start_Num, Hensati, te1);

		
		accumulatedTime += Scene::DeltaTime();
		font(U"Hello!!").draw(50, Vec2{ 300, 100 }, Palette::Black);
		font(U"統計ソフトへようこそ").draw(50, Vec2{ 200, 50 }, Palette::Black);
		font(U"デバック経過時間: {:.2f}"_fmt(accumulatedTime)).draw(40, 20, 20, Palette::Black);
		
		
		Circle{ 100, 300, 10 }.draw(Palette::Black);
		Circle{ 200, 300, 10 }.draw(Palette::Black);
		Circle{ 300, 300, 10 }.draw(Palette::Black);
		Circle{ 400, 300, 10 }.draw();
		Circle{ 500, 300, 10 }.draw();
		Circle{ 600, 300, 10 }.draw();
		Circle{ 700, 300, 10 }.draw();
		}

	
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//
