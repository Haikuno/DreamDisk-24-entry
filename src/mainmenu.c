#include "mainmenu.h"
#include "raylib.h"

static GBL_RESULT BBMainmenu_activate_(BBScene *pSelf) {
    //
}

static GBL_RESULT BBMainmenu_deactivate_(BBScene *pSelf) {
    //
}

static GBL_RESULT BBMainmenu_update_(BBScene *pSelf, float deltaTime) {
    //
}

static GBL_RESULT BBMainmenu_pollInput_(BBScene *pSelf) {
    //
}

static GBL_RESULT BBMainmenu_draw_(BBScene *pSelf) {
    GBL_CTX_BEGIN(NULL);
    GBL_VCALL_DEFAULT(BBMenuScene, parent.pFnDraw, pSelf);
    DrawRectangle(0, 0, 100, 100, RED);
    GBL_CTX_END();
}

static GBL_RESULT BBMainmenuClass_init_(GblClass *pClass, const void *pUserData) {
    GBL_UNUSED(pUserData);

    // if (!GblType_classRefCount(BB_SCENE_TYPE)) {
    //     GBL_PROPERTIES_REGISTER(GblModule);
    // }

    BB_SCENE_CLASS(pClass)->pFnActivate   = BBMainmenu_activate_;
    BB_SCENE_CLASS(pClass)->pFnDeactivate = BBMainmenu_deactivate_;
    BB_SCENE_CLASS(pClass)->pFnUpdate     = BBMainmenu_update_;
    BB_SCENE_CLASS(pClass)->pFnPollInput  = BBMainmenu_pollInput_;
    BB_SCENE_CLASS(pClass)->pFnDraw       = BBMainmenu_draw_;

    return GBL_RESULT_SUCCESS;
}

static GBL_RESULT BBMainmenuClass_final_(GblClass *pClass, const void *pUserData) {
    //
}

static GBL_RESULT BBMainmenu_init_(GblInstance *pInstance) {
    //
}

GblType BBMainmenu_type(void) {
    static GblType type = GBL_INVALID_TYPE;

    if (type == GBL_INVALID_TYPE) {
        type = GblType_register(GblQuark_internStatic("BBMainmenu"), BB_MENUSCENE_TYPE,
                                &(GblTypeInfo){ // Size of your static members + virtaul methods
                                                .classSize = sizeof(BBMainmenuClass),
                                                // Class "construtor"
                                                .pFnClassInit = BBMainmenuClass_init_,
                                                // Class "destructor"
                                                .pFnClassFinal = BBMainmenuClass_final_,
                                                // Size of every instance of the class
                                                .instanceSize = sizeof(BBMainmenu),
                                                // Constructor for each instance
                                                .pFnInstanceInit = BBMainmenu_init_ },
                                GBL_TYPE_FLAGS_NONE);
    }

    return type;
}

BBMainmenu *BBMainmenu_create(void) {
    return BB_MAINMENU(BBScene_create(BB_MAINMENU_TYPE, "BBMainmenu"));
}

BBMainmenu *BBMainmenu_ref(BBMainmenu *pSelf) {
    return BB_MAINMENU(GBL_REF(pSelf));
}

GblRefCount BBMainmenu_unref(BBMainmenu *pSelf) {
    return GBL_UNREF(pSelf);
}