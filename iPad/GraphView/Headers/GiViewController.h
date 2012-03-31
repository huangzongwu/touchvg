//! \file GiViewController.h
//! \brief 定义图形视图控制器类 GiViewController
// Copyright (c) 2012, Zhang Yungui <rhcad@hotmail.com>
// License: LGPL, https://github.com/rhcad/graph2d

#import <UIKit/UIKit.h>

//! 图形视图控制器类
/*! \ingroup _GRAPH_IOS_
*/
@interface GiViewController : UIViewController {
@private
    id      _command;                   //!< 绘图命令,GiCommandController
    void*   _shapesCreated;             //!< 创建的图形列表
    BOOL    _gestureRecognizerUsed;     //!< 是否使用手势识别器处理触摸消息
    int     _touchCount;                //!< 开始触摸时的手指数
    UIView  *_magnifierView;            //!< 放大镜视图
    
    enum { RECOGNIZER_COUNT = 4 };
    UIGestureRecognizer* _recognizers[2][RECOGNIZER_COUNT];
}

@property (nonatomic,readonly)  void*   shapes;     //!< 图形列表, MgShapes*

//! 当前命令名称
@property (nonatomic)         const char*   commandName;

//! 是否使用手势识别器处理触摸消息
@property (nonatomic)         BOOL      gestureRecognizerUsed;

//! 线宽，正数表示单位为0.01mm，零表示1像素宽，负数时表示单位为像素
@property (nonatomic)         int       lineWidth;

//! 线条颜色，忽略透明度分量，clearColor 表示不画线条
@property (nonatomic,assign)  UIColor   *lineColor;

//! 线条透明度, 0-1
@property (nonatomic)         float     lineAlpha;

//! 填充颜色，忽略透明度分量，clearColor 表示不填充
@property (nonatomic,assign)  UIColor   *fillColor;

//! 填充透明度, 0-1
@property (nonatomic)         float     fillAlpha;

//! 线型, 0-Solid, 1-Dash, 2-Dot, 3-DashDot, 4-DashDotdot, 5-Null
@property (nonatomic)         int       lineStyle;


- (void)clearCachedData;                //!< 清除缓冲数据，下次重新构建显示
- (void)undoMotion;                     //!< 触发晃动或撤销操作
- (void)dynDraw:(id)sender;             //!< 供图形视图动态显示时调用

//! 创建图形视图(GiGraphView)和图形列表，不需要图形视图的派生类时使用
/*!
    \param frame 视图位置大小
    \param bkColor 背景色
    \param shapes 已有的共享图形列表，如果为NULL则自动创建图形列表
    \return 创建子图形视图(GiGraphView)
 */
- (UIView*)createGraphView:(CGRect)frame backgroundColor:(UIColor*)bkColor shapes:(void*)shapes;

//! 在已有视图中创建子图形视图(GiGraphView)和图形列表
/*!
    \param parentView 已有视图，将创建其子视图
    \param shapes 已有的共享图形列表，如果为NULL则自动创建图形列表
    \return 创建子图形视图(GiGraphView)
 */
- (UIView*)createSubGraphView:(UIView*)parentView frame:(CGRect)frame shapes:(void*)shapes;

//! 在给定视图内创建放大镜视图
- (void)createMagnifierView:(UIView*)parentView frame:(CGRect)frame scale:(CGFloat)scale;

@end
