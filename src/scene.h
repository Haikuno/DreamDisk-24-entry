#ifndef BB_SCENE_H
#define BB_SCENE_H

#include <gimbal/gimbal_meta.h>

// Type-cast operators
#define BB_SCENE_TYPE (GBL_TYPEID(BBScene))
#define BB_SCENE(self) (GBL_CAST(BBScene, self))
#define BB_SCENE_CLASS(klass) (GBL_CLASS_CAST(BBScene, klass))
#define BB_SCENE_GET_CLASS(self) (GBL_CLASSOF(BBScene, self))

#define GBL_SELF_TYPE BBScene

GBL_FORWARD_DECLARE_STRUCT(BBScene);
GBL_DECLS_BEGIN

// Virtual function table
GBL_CLASS_DERIVE(BBScene, GblObject)
GBL_RESULT (*pFnActivate)(GBL_SELF);
GBL_RESULT (*pFnDeactivate)(GBL_SELF);
GBL_RESULT (*pFnUpdate)(GBL_SELF, float deltaTime);
GBL_RESULT (*pFnPollInput)(GBL_SELF);
GBL_RESULT (*pFnDraw)(GBL_SELF);
GBL_CLASS_END

GBL_INSTANCE_DERIVE(BBScene, GblObject)
// Any public variables for scenes
// You're already inheriting name,
// reference counting, userdata, parenting,
// event handling, etc from GblObject
GBL_INSTANCE_END

GblType BBScene_type(void);

BBScene* BBScene_create(GblType type, const char* pName);

BBScene *BBScene_current(void);
BBScene *BBScene_swap(GBL_SELF);

GBL_RESULT BBScene_update(GBL_SELF, float deltaTime);
GBL_RESULT BBScene_draw(GBL_SELF);
GBL_RESULT BBScene_processInput(GBL_SELF);

GBL_DECLS_END

#undef GBL_SELF_TYPE

#endif
