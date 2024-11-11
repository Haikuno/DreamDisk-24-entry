#include "menuscene.h"
#include "raylib.h"

static GBL_RESULT BBMenuScene_activate_(BBScene *pSelf) {
    //
}

static GBL_RESULT BBMenuScene_deactivate_(BBScene *pSelf) {
    //
}

static GBL_RESULT BBMenuScene_update_(BBScene *pSelf, float deltaTime) {
    //
}

static GBL_RESULT BBMenuScene_pollInput_(BBScene *pSelf) {
    //
}

static GBL_RESULT BBMenuScene_draw_(BBScene *pSelf) {
    ClearBackground(BLUE);
}

static GBL_RESULT BBMenuSceneClass_init_(GblClass *pClass, const void *pUserData) {
    GBL_UNUSED(pUserData);

    // if (!GblType_classRefCount(BB_SCENE_TYPE)) {
    //     GBL_PROPERTIES_REGISTER(GblModule);
    // }

    BB_SCENE_CLASS(pClass)->pFnActivate   = BBMenuScene_activate_;
    BB_SCENE_CLASS(pClass)->pFnDeactivate = BBMenuScene_deactivate_;
    BB_SCENE_CLASS(pClass)->pFnUpdate     = BBMenuScene_update_;
    BB_SCENE_CLASS(pClass)->pFnPollInput  = BBMenuScene_pollInput_;
    BB_SCENE_CLASS(pClass)->pFnDraw       = BBMenuScene_draw_;

    return GBL_RESULT_SUCCESS;
}

static GBL_RESULT BBMenuSceneClass_final_(GblClass *pClass, const void *pUserData) {
    //
}

static GBL_RESULT BBMenuScene_init_(GblInstance *pInstance) {
    //
}

GblType BBMenuScene_type(void) {
    static GblType type = GBL_INVALID_TYPE;

    if (type == GBL_INVALID_TYPE) {
        type = GblType_register(GblQuark_internStatic("BBMenuScene"), BB_SCENE_TYPE,
                                &(GblTypeInfo){ // Size of your static members + virtaul methods
                                                .classSize = sizeof(BBMenuSceneClass),
                                                // Class "construtor"
                                                .pFnClassInit = BBMenuSceneClass_init_,
                                                // Class "destructor"
                                                .pFnClassFinal = BBMenuSceneClass_final_,
                                                // Size of every instance of the class
                                                .instanceSize = sizeof(BBMenuScene),
                                                // Constructor for each instance
                                                .pFnInstanceInit = BBMenuScene_init_ },
                                GBL_TYPE_FLAGS_NONE);
    }

    return type;
}

BBMenuScene *BBMenuScene_create(void) {
    return BB_MENUSCENE(BBScene_create(BB_MENUSCENE_TYPE, "BBMenuScene"));
}

BBMenuScene *BBMenuScene_ref(BBMenuScene *pSelf) {
    return BB_MENUSCENE(GBL_REF(pSelf));
}

GblRefCount BBMenuScene_unref(BBMenuScene *pSelf) {
    return GBL_UNREF(pSelf);
}