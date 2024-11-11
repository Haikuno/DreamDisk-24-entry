#include "scene.h"
// #include <gimbal_module.h>

static BBScene* pCurrentScene_ = GBL_NULL;

static GBL_RESULT BBScene_activate_(BBScene *pSelf) {
    //
}

static GBL_RESULT BBScene_deactivate_(BBScene *pSelf) {
    //
}

static GBL_RESULT BBScene_update_(BBScene *pSelf, float deltaTime) {
    //
}

static GBL_RESULT BBScene_pollInput_(BBScene *pSelf) {
    //
}

static GBL_RESULT BBScene_draw_(BBScene *pSelf) {
    //
}

static GBL_RESULT BBSceneClass_init_(GblClass *pClass, const void *pUserData) {
    GBL_UNUSED(pUserData);

    // if (!GblType_classRefCount(BB_SCENE_TYPE)) {
    //     GBL_PROPERTIES_REGISTER(GblModule);
    // }

    BB_SCENE_CLASS(pClass)->pFnActivate   = BBScene_activate_;
    BB_SCENE_CLASS(pClass)->pFnDeactivate = BBScene_deactivate_;
    BB_SCENE_CLASS(pClass)->pFnUpdate     = BBScene_update_;
    BB_SCENE_CLASS(pClass)->pFnPollInput  = BBScene_pollInput_;
    BB_SCENE_CLASS(pClass)->pFnDraw       = BBScene_draw_;

    return GBL_RESULT_SUCCESS;
}

static GBL_RESULT BBSceneClass_final_(GblClass *pClass, const void *pUserData) {
    //
}

static GBL_RESULT BBScene_init_(GblInstance *pInstance) {
    //
}

GblType BBScene_type(void) {
    // Initialize our type as not registered
    static GblType type = GBL_INVALID_TYPE;

    // If it's our fist time calling, we have no UUID
    if (type == GBL_INVALID_TYPE) {
        // Register the type with libGimbal and store its UUID for later
        type = // Get fast-ass interned string for name of type
            GblType_register(GblQuark_internStatic("BBScene"),
                             // Parent type you're inheriting from
                             GBL_OBJECT_TYPE,
                             // Type information structure
                             &(const GblTypeInfo){ // Size of your static members + virtaul methods
                                                   .classSize = sizeof(BBSceneClass),
                                                   // Class "construtor"
                                                   .pFnClassInit = BBSceneClass_init_,
                                                   // Class "destructor"
                                                   .pFnClassFinal = BBSceneClass_final_,
                                                   // Size of every instance of the class
                                                   .instanceSize = sizeof(BBScene),
                                                   // Constructor for each instance
                                                   .pFnInstanceInit = BBScene_init_ },
                             // Any additional flags
                             GBL_TYPE_FLAG_ABSTRACT);
    }

    // Return its UUID
    return type;
}


BBScene *BBScene_create(GblType type, const char *pName) {
    return BB_SCENE(GblObject_create(type, "name", pName, NULL));
}

GBL_RESULT BBScene_update(BBScene *pScene, float deltaTime) {
    return BB_SCENE_GET_CLASS(pScene)->pFnUpdate(pScene, deltaTime);
}

GBL_RESULT BBScene_pollInput(BBScene *pScene) {
    return BB_SCENE_GET_CLASS(pScene)->pFnPollInput(pScene);
}

GBL_RESULT BBScene_draw(BBScene *pScene) {
    return BB_SCENE_GET_CLASS(pScene)->pFnDraw(pScene);
}

GBL_RESULT BBScene_activate(BBScene *pScene) {
    return BB_SCENE_GET_CLASS(pScene)->pFnActivate(pScene);
}

GBL_RESULT BBScene_deactivate(BBScene *pScene) {
    return BB_SCENE_GET_CLASS(pScene)->pFnDeactivate(pScene);
}

BBScene* BBScene_current(void) {
    return pCurrentScene_;
}

BBScene* BBScene_swap(BBScene *pScene) {
    if (pCurrentScene_ != GBL_NULL) {
        BB_SCENE_GET_CLASS(pCurrentScene_)->pFnDeactivate(pCurrentScene_);
    }
    BBScene *pPrevious = pCurrentScene_;
    pCurrentScene_ = pScene;
    BB_SCENE_GET_CLASS(pScene)->pFnActivate(pScene);
    return pPrevious;
}