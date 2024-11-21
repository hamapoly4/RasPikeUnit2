/******************************************************************************
 *  ファイル名：common_enum_class.h
 *　　　　内容：共通で利用する列挙体クラスの定義
 *  　　作成日：2024/10/21
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___COMMON_ENUM_CLASS_H
#define ___COMMON_ENUM_CLASS_H  // インクルードカード

/* 色 */
enum class eColor { BLACK, BLUE, ELSE, };

/* 走行速度 */
enum class eSpeed { LOW, MID, HIGH, };

/* 旋回方向 */
enum class eDire { LEFT, RIGHT, };

/* エッジ */
enum class eEdge { LEFT, RIGHT, };

#endif // ___COMMON_ENUM_CLASS_H
