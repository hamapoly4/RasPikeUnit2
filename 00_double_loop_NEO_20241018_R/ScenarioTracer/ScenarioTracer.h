/******************************************************************************
 *  ファイル名：ScenarioTracer.h
 *　　　　内容：シナリオトレーサクラスの定義
 *  　　作成日：2024/10/24
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_SCENARIO_TRACER
#define ___CLASS_SCENARIO_TRACER    // インクルードカード

/* ヘッダインクルード */
#include "Scenario.h"   // シナリオクラス


/* シナリオトレーサクラス */
class ScenarioTracer {
public:
    /* 列挙体 */
    typedef enum { START, CONQUEST, FINISH, } eState;   // 状態

    ScenarioTracer(Scenario* conqdoublescenario);   // コンストラクタ

    void conquer();     // 攻略する関数

    eState checkState() const;  // 状態を確認する関数

private:
    void run();     // 走行する関数

    void transState(eState s);  // 状態を遷移する関数

    /* 動的インスタンス */
    Scenario* mConqDoubleScenario;  // ダブルループNEO攻略用シナリオ

    eState state;   // 状態

};

#endif // ___CLASS_SCENARIO_TRACER
