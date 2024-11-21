/******************************************************************************
 *  ファイル名：Scenario.cpp
 *　　　　内容：シナリオクラスの定義
 *  　　作成日：2024/10/23
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "Scenario.h"   // シナリオクラス
#include <stdio.h>


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：初期化装置、パラメータ取得、各区間に応じたシーン
 *　　　　　シーンの先頭番号、シーンの末尾番号
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
Scenario::Scenario(IniDevice* initializer, ParameterManage* getparam, Scene* eachareascene, int8_t t, int8_t l)
    : mInitializer(initializer), mGetParam(getparam), mEachAreaScene(eachareascene), current_scene(t), last(l), state(START)
{
    ;
}

/******************************************************
 *  関数名：conquer
 *    概要：攻略する
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void Scenario::conquer()
{
    if (state == START)
    {
        transState(EXE_SCENARIO);
    }

    if (state == EXE_SCENARIO)
    {
        exeScenario();
    }

    if (state == INI_DEVICE)
    {
        iniDevice();
    }
}

/******************************************************
 *  関数名：exeScenario
 *    概要：シナリオを実行する
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void Scenario::exeScenario()
{
    /* 現在のシーン番号が末尾番号を超えたら判定 */
    if (current_scene > last)
    {
        transState(FINISH);     // 終了状態に遷移する
        return;                 // 以下のコードは実行しない！！
    }

    mGetParam->getParameter();  // センシングする

    mEachAreaScene[current_scene].exeScene();  // シーンを実行する

    if (mEachAreaScene[current_scene].checkFlag())
    {
        switchScene();
    }
}

/******************************************************
 *  関数名：switchScene
 *    概要：シーンを切り替える
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void Scenario::switchScene()
{
    printf("scene%d finish!!\n", current_scene + 1);
    current_scene++;
    transState(INI_DEVICE);
}

/******************************************************
 *  関数名：iniDevice
 *    概要：デバイスを初期化する
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void Scenario::iniDevice()
{
    mInitializer->init();

    if (mInitializer->checkState() == IniDevice::FINISH)
    {
        transState(EXE_SCENARIO);
    }
}

/******************************************************
 *  関数名：transState
 *    概要：状態を遷移する
 *  　引数：状態
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void Scenario::transState(eState s)
{
    state = s;
}

/******************************************************
 *  関数名：checkState
 *    概要：状態を確認する
 *  　引数：なし
 *  返却値：状態
 *  　備考：constメンバ関数
 ******************************************************/
Scenario::eState Scenario::checkState() const
{
    return state;
}
