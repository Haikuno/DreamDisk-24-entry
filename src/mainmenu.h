#ifndef BB_MAINMENU_H
#define BB_MAINMENU_H

#include "menuscene.h"

#define BB_MAINMENU_TYPE (GBL_TYPEID(BBMainmenu))
#define BB_MAINMENU(self) (GBL_CAST(BBMainmenu, self))
#define BB_MAINMENU_CLASS(klass) (GBL_CLASS_CAST(BBMainmenu, klass))
#define BB_MAINMENU_GET_CLASS(self) (GBL_CLASSOF(BBMainmenu, self))

#define GBL_SELF_TYPE BBMainmenu

GBL_FORWARD_DECLARE_STRUCT(BBMainmenu);
GBL_DECLS_BEGIN

GBL_CLASS_DERIVE(BBMainmenu, BBMenuScene)
//
GBL_CLASS_END

GBL_INSTANCE_DERIVE(BBMainmenu, BBMenuScene)
//
GBL_INSTANCE_END

GblType BBMainmenu_type(void);

BBMainmenu *BBMainmenu_create();
BBMainmenu *BBMainmenu_ref(GBL_SELF);
GblRefCount BBMainmenu_unref(GBL_SELF);

GBL_DECLS_END

#undef GBL_SELF_TYPE

#endif
