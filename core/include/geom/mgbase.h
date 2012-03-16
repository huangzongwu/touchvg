//! \file mgbase.h
//! \brief 定义基本计算功能函数
// Copyright (c) 2004-2012, Zhang Yungui
// License: LGPL, https://github.com/rhcad/graph2d

#ifndef __GEOMETRY_BASIC_H_
#define __GEOMETRY_BASIC_H_

#include "mgdef.h"

//! 将数转换到数值范围[tmin, tmax)内
/*! 转换后的数和原来的数相差(tmax - tmin)的整数倍。
    \ingroup _GEOMAPI_BASIC_
    \param[in] value 给定的任意数
    \param[in] tmin 数值范围的下限
    \param[in] tmax 数值范围的上限，必须大于tmin
    \return 转换后的数，大于等于tmin且小于tmax
*/
GEOMAPI double mgToRange(double value, double tmin, double tmax);

//! 使角度在[0, 2PI)之间
/*! 转换后的角度和原来的角度相差2PI的整数倍
    \ingroup _GEOMAPI_BASIC_
    \param[in] angle 角度，单位为弧度
    \return 角度，弧度，范围在[0，2PI)之间
    \see mgToRange, mgToPI, _M_2PI
*/
GEOMAPI double mgTo0_2PI(double angle);

//! 使角度在[-PI, PI)之间
/*! 转换后的角度和原来的角度相差2PI的整数倍
    \ingroup _GEOMAPI_BASIC_
    \param[in] angle 角度，单位为弧度
    \return 角度，弧度，范围在[-PI, PI)之间
    \see mgToRange, mgTo0_2PI, M_PI
*/
GEOMAPI double mgToPI(double angle);

//! 角度从度转换到弧度
/*! 内部是乘以一个常数进行转换
    \ingroup _GEOMAPI_BASIC_
    \param[in] deg 以度为单位的角度
    \return 以弧度为单位的角度
    \see mgRad2Deg, mgDms2Deg, _M_D2R
*/
GEOMAPI double mgDeg2Rad(double deg);

//! 角度从弧度转换到度
/*! 内部是乘以一个常数进行转换
    \ingroup _GEOMAPI_BASIC_
    \param[in] rad 以弧度为单位的角度
    \return 以度为单位的角度
    \see mgDeg2Rad, mgDms2Deg, _M_R2D
*/
GEOMAPI double mgRad2Deg(double rad);

//! 度分秒转换到角度(度)
/*! 度分秒形式的角度的整数部分为度，十分位和百分位为分，
    千分位和万分位及其他小数位为秒。例如32.251242表示32°25'12.42"。
    \ingroup _GEOMAPI_BASIC_
    \param[in] angle 度分秒形式的角度
    \return 以度为单位的角度
    \see mgDeg2Dms, mgDeg2Rad
*/
GEOMAPI double mgDms2Deg(double angle);

//! 角度(度)转换到度分秒
/*! 度分秒形式的角度的整数部分为度，十分位和百分位为分，
    千分位和万分位及其他小数位为秒。例如32.251242表示32°25'12.42"。
    \ingroup _GEOMAPI_BASIC_
    \param[in] angle 以度为单位的角度
    \return 度分秒形式的角度
    \see mgDms2Deg, mgDeg2Rad
*/
GEOMAPI double mgDeg2Dms(double angle);

//! 求两个角度的角平分线角度, [0, 2PI)
/*! 函数计算从起始角度到终止角度按逆时针方向所转过角度的角平分线角度。
    如果终止角度小于起始角度，则终止角度自动加上2PI以便按逆时针方向能转到终止角度
    \ingroup _GEOMAPI_BASIC_
    \param[in] fromAngle 起始角度，弧度
    \param[in] toAngle 终止角度，弧度
    \return 角平分线角度，弧度，范围在[0，2PI)之间
*/
GEOMAPI double mgMidAngle(double fromAngle, double toAngle);

//! 求两个角度的夹角, [-PI, PI)
/*! 函数计算从起始角度到终止角度按逆时针方向所转过角度，并转换到[-PI，PI)范围
    \ingroup _GEOMAPI_BASIC_
    \param[in] fromAngle 起始角度，弧度
    \param[in] toAngle 终止角度，弧度
    \return 夹角，弧度，范围在[-PI，PI)之间
*/
GEOMAPI double mgDiffAngle(double fromAngle, double toAngle);

//! 计算最大公约数
/*! 最大公约数就是能被给定的两个正整数整除、且不大于这两个数的正整数
    \ingroup _GEOMAPI_BASIC_
    \param[in] x 第一个正整数
    \param[in] y 第二个正整数
    \return 最大公约数，正整数
*/
GEOMAPI long mgGcd(long x, long y);

//! 四舍五入为浮点数
/*! 例如 mgRoundReal(1.25, 1)=1.3
    \ingroup _GEOMAPI_BASIC_
    \param[in] value 要四舍五入的数
    \param[in] decimal 要保留的小数位数，范围为-6到7，正数表示有小数位，
        0相当于取整，负数表示取整并使某些低位数字为零
    \return 四舍五入后的浮点数
    \see mgRound
*/
GEOMAPI double mgRoundReal(double value, int decimal);

#endif // __GEOMETRY_BASIC_H_
