//! \file _gigraph.h
//! \brief 定义GiGraphics类的内部成员
// Copyright (c) 2004-2012, Zhang Yungui
// License: LGPL, https://github.com/rhcad/touchdraw

#include "gigraph.h"

//! GiGraphics的内部实现类
class GiGraphicsImpl
{
public:
    enum { CLIP_INFLATE = 10 };

    GiGraphics*  pThis;             //!< 图形系统
    GiTransform* xform;             //!< 坐标系管理对象

    UInt8       maxPenWidth;        //!< 最大像素线宽
    bool        antiAlias;          //!< 当前是否是反走样模式

    long        lastZoomTimes;      //!< 记下的放缩结果改变次数
    long        drawRefcnt;         //!< 绘图锁定计数
    bool        isPrint;            //!< 是否打印或打印预览
    int         drawColors;         //!< 绘图DC颜色数
    int         colorMode;          //!< 颜色模式, enum kColorMode
    RECT        clipBox0;           //!< 开始绘图时的剪裁框(LP)

    RECT        clipBox;            //!< 剪裁框(LP)
    Box2d       rectDraw;           //!< 剪裁矩形，比clipBox略大
    Box2d       rectDrawM;          //!< 剪裁矩形，模型坐标
    Box2d       rectDrawW;          //!< 剪裁矩形，世界坐标
    Box2d       rectDrawMaxM;       //!< 最大剪裁矩形，模型坐标
    Box2d       rectDrawMaxW;       //!< 最大剪裁矩形，世界坐标

    static long& screenDPI()
    {
        static long dpi = 0;
        return dpi;
    }

    GiGraphicsImpl(GiGraphics* gs, GiTransform* x) : pThis(gs), xform(x)
    {
        drawRefcnt = 0;
        drawColors = 0;
        colorMode = GiGraphics::kColorReal;
        isPrint = false;
        maxPenWidth = 100;
        antiAlias = true;
    }

    ~GiGraphicsImpl()
    {
    }
    
    void zoomChanged()
    {
        rectDrawM = rectDraw * xform->displayToModel();
        Box2d rect (0, 0, xform->getWidth(), xform->getHeight());
        rectDrawMaxM = rect * xform->displayToModel();
        rectDrawW = rectDrawM * xform->modelToWorld();
        rectDrawMaxW = rectDrawMaxM * xform->modelToWorld();
        pThis->clearCachedBitmap();
    }

private:
    GiGraphicsImpl();
    void operator=(const GiGraphicsImpl&);
};

//! 图形系统的绘图引用锁定辅助类
class GiLock
{
    long*  m_refcount;
public:
    GiLock(long* refcount) : m_refcount(refcount)
    {
        giInterlockedIncrement(m_refcount);
    }
    ~GiLock()
    {
        giInterlockedDecrement(m_refcount);
    }
};
