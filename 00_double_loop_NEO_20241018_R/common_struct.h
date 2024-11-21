/******************************************************************************
 *  ファイル名：common_struct.h
 *　　　　内容：共通で利用する構造体の定義
 *  　　作成日：2024/10/20
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___COMMON_STRUCT_H
#define ___COMMON_STRUCT_H  // インクルードカード

/* ヘッダインクルード */
#include "ev3api.h"     // ev3api

/* HSV値 */
typedef struct {
    int h;
    int s;
    int v;

} hsv_raw_t;

/* エンコーダ回転角 */
typedef struct {
    int32_t left;
    int32_t right;

} ecdr_cnt_t;

/* 制御用パラメータ */
typedef struct {
    int   threathold;
    float kp;
    float kd;

} con_param_t;

#endif // ___COMMON_STRUCT_H
