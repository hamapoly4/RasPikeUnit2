/******************************************************************************
 *  ファイル名：Scene.h
 *　　　　内容：シーンクラスの定義
 *  　　作成日：2024/10/22
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_SCENE
#define ___CLASS_SCENE  // インクルードカード

/* ヘッダインクルード */
#include "Run.h"        // 走行クラス（抽象クラス）
#include "Judge.h"      // 判定クラス（インターフェースクラス）


/* シーンクラス */
class Scene {
public:
    Scene(Run* runforscene, Judge* judgeforscene);  // コンストラクタ

    void exeScene();    // シーンを実行する関数

    bool checkFlag() const;     // シーン終了フラグを確認する関数

private:
    /* 動的インスタンス */
    Run*    mRunForScene;       // 各シーンに応じた走行
    Judge*  mJudgeForScene;     // 各シーンに応じた判定

    bool fin_flag;  // シーン終了フラグ

};

#endif // ___CLASS_SCENE
