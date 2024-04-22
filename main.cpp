#include <Novice.h>
#include "Matrix4x4Function.h"
#include <Vector3.h>

const char kWindowTitle[] = "LE2A_10_キョウ_ゲンソ";

const int kRowHeight = 20;
const int kColumnWidth = 60;

void Matrix4x4ScreenPrint(int x, int y, Matrix4x4 m, const char* string) {
	Novice::ScreenPrintf(x, y, "%s", string);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Novice::ScreenPrintf(x + j * kColumnWidth, y + (i + 1) * kRowHeight, "%6.02f", m.m[i][j]);
		}
	}
}

void Vector3ScreenPrint(int x, int y, Vector3 v, const char* string) {
	Novice::ScreenPrintf(x, y, "%s", string);
	Novice::ScreenPrintf(x + 0 * kColumnWidth, y + kRowHeight, "%6.02f", v.x);
	Novice::ScreenPrintf(x + 1 * kColumnWidth, y + kRowHeight, "%6.02f", v.y);
	Novice::ScreenPrintf(x + 2 * kColumnWidth, y + kRowHeight, "%6.02f", v.z);
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	int windowX = 1280;
	int windowY = 720;
	Novice::Initialize(kWindowTitle, windowX, windowY);

	Vector3 translate{ 4.1f, 2.6f, 0.8f };
	Vector3 Scale{ 1.5f, 5.2f, 7.3f };
	Matrix4x4 translateMatrix = MakeTranslateMatrix(translate);
	Matrix4x4 scaleMatrix = MakeScaleMatrix(Scale);
	Vector3 point{ 2.3f, 3.8f, 1.4f };

	Matrix4x4 transFormMatrix = {
		1.0f, 2.0f, 3.0f, 4.0f,
		3.0f, 1.0f, 1.0f, 2.0f,
		1.0f, 4.0f, 2.0f, 3.0f,
		2.0f, 2.0f, 1.0f, 3.0f
	};

	Vector3 transFormed = Transform(point, transFormMatrix);


	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///-------------------///
		/// ↓更新処理ここから///
		///-------------------///

		Vector3ScreenPrint(0, 0, transFormed, "transFormed");
		Matrix4x4ScreenPrint(0, kRowHeight * 5, translateMatrix, "translateMatrix");
		Matrix4x4ScreenPrint(0, kRowHeight * 5 * 2, scaleMatrix, "scaleMatrix");

		///-------------------///
		/// ↑更新処理ここまで///
		///-------------------///

		///-------------------///
		/// ↓描画処理ここから///
		///-------------------///





		///-------------------///
		/// ↑描画処理ここまで///
		///-------------------///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
