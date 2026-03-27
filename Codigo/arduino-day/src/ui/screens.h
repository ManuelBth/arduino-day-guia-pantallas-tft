#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *imagenes;
    lv_obj_t *objetos1;
    lv_obj_t *objetos2;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj1__obj0;
    lv_obj_t *obj2;
    lv_obj_t *obj2__obj0;
    lv_obj_t *obj3;
    lv_obj_t *obj3__obj0;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *switch1;
    lv_obj_t *checkbox1;
    lv_obj_t *my_colorwheel;
    lv_obj_t *my_led;
    lv_obj_t *my_slider;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_IMAGENES = 2,
    SCREEN_ID_OBJETOS1 = 3,
    SCREEN_ID_OBJETOS2 = 4,
};

void create_screen_main();
void tick_screen_main();

void create_screen_imagenes();
void tick_screen_imagenes();

void create_screen_objetos1();
void tick_screen_objetos1();

void create_screen_objetos2();
void tick_screen_objetos2();

void create_user_widget_header(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_header(void *flowState, int startWidgetIndex);

void create_user_widget_btn_atras(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_btn_atras(void *flowState, int startWidgetIndex);

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/