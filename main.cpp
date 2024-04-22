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

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	int windowX = 1280;
	int windowY = 720;
	Novice::Initialize(kWindowTitle, windowX, windowY);

	Matrix4x4 m1 = {
		3.2f, 0.7f, 9.6f, 4.4f,
		5.5f, 1.3f, 7.8f, 2.1f,
		6.9f, 8.0f, 2.6f, 1.0f,
		0.5f, 7.2f, 5.1f, 3.3f
	};

	Matrix4x4 m2 = {
		4.1f, 6.5f, 3.3f, 2.2f,
		8.8f, 0.6f, 9.9f, 7.7f,
		1.1f, 5.5f, 6.6f, 0.0f,
		3.3f, 9.9f, 8.8f, 2.2f
	};

	Matrix4x4 resultAdd = Add(m1, m2);
	Matrix4x4 resultSub = Subtrsct(m1, m2);
	Matrix4x4 resultMul = Multiply(m1, m2);
	Matrix4x4 inverseM1 = Inverse(m1);
	Matrix4x4 inverseM2 = Inverse(m2);
	Matrix4x4 transposeM1 = Transpose(m1);
	Matrix4x4 transposeM2 = Transpose(m2);
	Matrix4x4 identity = MakeIdentity4X4();



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

		Matrix4x4ScreenPrint(0, 0, resultAdd, "Add");
		Matrix4x4ScreenPrint(0, kRowHeight * 5, resultSub, "Subtract");
		Matrix4x4ScreenPrint(0, kRowHeight * 5 * 2, resultMul, "Multiply");
		Matrix4x4ScreenPrint(0, kRowHeight * 5 * 3, inverseM1, "Inverse M1");
		Matrix4x4ScreenPrint(0, kRowHeight * 5 * 4, inverseM2, "Inverse M2");
		Matrix4x4ScreenPrint(kColumnWidth * 5, 0, transposeM1, "Transpose M1");
		Matrix4x4ScreenPrint(kColumnWidth * 5, kRowHeight * 5, transposeM2, "Transpose M2");
		Matrix4x4ScreenPrint(kColumnWidth * 5, kRowHeight * 5 * 2, identity, "Identity");




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
