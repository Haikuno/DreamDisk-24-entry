#ifndef BB_MENUSCENE_H
#define BB_MENUSCENE_H

#include "scene.h"

#define BB_MENUSCENE_TYPE (GBL_TYPEID(BBMenuScene))
#define BB_MENUSCENE(self) (GBL_CAST(BBMenuScene, self))
#define BB_MENUSCENE_CLASS(klass) (GBL_CLASS_CAST(BBMenuScene, klass))
#define BB_MENUSCENE_GET_CLASS(self) (GBL_CLASSOF(BBMenuScene, self))

#define GBL_SELF_TYPE BBMenuScene

GBL_FORWARD_DECLARE_STRUCT(BBMenuScene);
GBL_DECLS_BEGIN

GBL_CLASS_DERIVE(BBMenuScene, BBScene)
//
GBL_CLASS_END

GBL_INSTANCE_DERIVE(BBMenuScene, BBScene)
//
GBL_INSTANCE_END

GblType BBMenuScene_type(void);

BBMenuScene *BBMenuScene_create();
BBMenuScene *BBMenuScene_ref(GBL_SELF);
GblRefCount BBMenuScene_unref(GBL_SELF);

GBL_DECLS_END

#undef GBL_SELF_TYPE

#endif
