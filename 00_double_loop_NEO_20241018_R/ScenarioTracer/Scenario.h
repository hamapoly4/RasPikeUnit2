/******************************************************************************
 *  ファイル名：Scenario.h
 *　　　　内容：シナリオクラスの定義
 *  　　作成日：2024/10/23
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_SCENARIO
#define ___CLASS_SCENARIO   // インクルードカード

/* ヘッダインクルード */
#include "ev3api.h"             // ev3api
#include "IniDevice.h"          // デバイス初期化クラス
#include "ParameterManage.h"    // パラメータ管理クラス
#include "Scene.h"              // シーンクラス


/* シナリオクラス */
class Scenario {
public:
    /* 列挙体 */
    typedef enum { START, EXE_SCENARIO, INI_DEVICE, FINISH, } eState;   // 状態

    Scenario(IniDevice* initializer, ParameterManage* getparam, Scene* eachareascene, int8_t t, int8_t l);  // コンストラクタ

    void conquer(); // 攻略する関数

    eState checkState() const;  // 状態を確認する関数

private:
    void exeScenario();     // シナリオを実行する関数
    void switchScene();     // シーンを切り替える関数
    void iniDevice();       // デバイスを初期化する関数

    void transState(eState s);  // 状態を遷移する関数

    /* 動的インスタンス */
    IniDevice* mInitializer;        // 初期化装置
    ParameterManage* mGetParam;     // パラメータ取得
    Scene* mEachAreaScene;          // 各区間に応じたシーン

    eState state;   // 状態

    int8_t current_scene;   // 現在のシーン番号
    int8_t last;            // シーンの末尾番号

};

#endif // ___CLASS_SCENARIO
