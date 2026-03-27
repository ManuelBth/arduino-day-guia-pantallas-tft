#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_obj4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_main_obj5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_main_obj6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_objetos2_switch1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 8, 3, value, "Failed to assign Checked state");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_objetos2_checkbox1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 9, 3, value, "Failed to assign Checked state");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_btn_atras_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 1, 0, e);
    }
}

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 40);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_header(obj, getFlowState(flowState, 0), 5);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 15, 50);
            lv_obj_set_size(obj, 140, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj4, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_one);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 6, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Imagenes");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 15, 100);
            lv_obj_set_size(obj, 140, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj5, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_two);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 5, 2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Objetos 1");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 15, 150);
            lv_obj_set_size(obj, 140, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj6, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_three);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 4, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Objetos 2");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 170, 50);
            lv_obj_set_size(obj, 140, 40);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, -5, -2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_docker);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Button");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 170, 100);
            lv_obj_set_size(obj, 140, 40);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, -5, -2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_jet);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Button");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 170, 150);
            lv_obj_set_size(obj, 140, 40);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, -5, -2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_profile);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Button");
                }
            }
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    tick_user_widget_header(getFlowState(flowState, 0), 5);
}

void create_screen_imagenes() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.imagenes = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 40, 40);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_btn_atras(obj, getFlowState(flowState, 0), 6);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 40);
            lv_obj_set_size(obj, 320, 200);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 100, 18);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_arduino);
                }
                {
                    // QR code eliminado - ya no se usa
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 88, 120);
                    lv_label_set_text(obj, "QR Code");
                }
            }
        }
    }
    
    tick_screen_imagenes();
}

void tick_screen_imagenes() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    tick_user_widget_btn_atras(getFlowState(flowState, 0), 6);
}

void create_screen_objetos1() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.objetos1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 40, 40);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_btn_atras(obj, getFlowState(flowState, 0), 8);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 49);
            lv_obj_set_size(obj, 320, 209);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_calendar_create(parent_obj);
                    lv_obj_set_pos(obj, 20, 0);
                    lv_obj_set_size(obj, 277, 269);
                    lv_calendar_header_arrow_create(obj);
                    lv_calendar_set_today_date(obj, 2022, 11, 1);
                    lv_calendar_set_showed_date(obj, 2022, 11);
                }
                {
                    lv_obj_t *obj = lv_keyboard_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 282);
                    lv_obj_set_size(obj, 320, 137);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    
    tick_screen_objetos1();
}

void tick_screen_objetos1() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    tick_user_widget_btn_atras(getFlowState(flowState, 0), 8);
}

void create_screen_objetos2() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.objetos2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 40, 40);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_btn_atras(obj, getFlowState(flowState, 0), 10);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 50);
            lv_obj_set_size(obj, 320, 190);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_roller_create(parent_obj);
                    lv_obj_set_pos(obj, 40, 280);
                    lv_obj_set_size(obj, 80, 100);
                    lv_roller_set_options(obj, "Option 1\nOption 2\nOption 3", LV_ROLLER_MODE_NORMAL);
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    lv_obj_set_pos(obj, 145, 312);
                    lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
                    lv_dropdown_set_options(obj, "Option 1\nOption 2\nOption 3");
                    lv_dropdown_set_selected(obj, 0);
                }
                {
                    // myColorwheel
                    lv_obj_t *obj = lv_colorwheel_create(parent_obj, false);
                    objects.my_colorwheel = obj;
                    lv_obj_set_pos(obj, 20, 64);
                    lv_obj_set_size(obj, 150, 150);
                }
                {
                    // myLed
                    lv_obj_t *obj = lv_led_create(parent_obj);
                    objects.my_led = obj;
                    lv_obj_set_pos(obj, 220, 139);
                    lv_obj_set_size(obj, 42, 42);
                    lv_led_set_color(obj, lv_color_hex(0xfff40404));
                    lv_led_set_brightness(obj, 255);
                }
                {
                    // mySlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.my_slider = obj;
                    lv_obj_set_pos(obj, 20, 234);
                    lv_obj_set_size(obj, 150, 10);
                    lv_slider_set_range(obj, 0, 255);
                    lv_slider_set_value(obj, 25, LV_ANIM_OFF);
                }
                {
                    // switch1
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.switch1 = obj;
                    lv_obj_set_pos(obj, 40, 19);
                    lv_obj_set_size(obj, 50, 25);
                    lv_obj_add_event_cb(obj, event_handler_cb_objetos2_switch1, LV_EVENT_ALL, flowState);
                }
                {
                    // checkbox1
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.checkbox1 = obj;
                    lv_obj_set_pos(obj, 188, 19);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Clickeame!");
                    lv_obj_add_event_cb(obj, event_handler_cb_objetos2_checkbox1, LV_EVENT_ALL, flowState);
                }
            }
        }
    }
    
    tick_screen_objetos2();
}

void tick_screen_objetos2() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    tick_user_widget_btn_atras(getFlowState(flowState, 0), 10);
    {
        bool new_val = evalBooleanProperty(flowState, 8, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.switch1, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.switch1;
            if (new_val) lv_obj_add_state(objects.switch1, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.switch1, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 9, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.checkbox1, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.checkbox1;
            if (new_val) lv_obj_add_state(objects.checkbox1, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.checkbox1, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
}

void create_user_widget_header(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 8, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_roboto_normal, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Arduino Day");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 172, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_roboto_italic, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "27 de Marzo");
        }
    }
}

void tick_user_widget_header(void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
}

void create_user_widget_btn_atras(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 40, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_btn_atras_obj0, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, -8, -3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_back);
                }
            }
        }
    }
}

void tick_user_widget_btn_atras(void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
}


static const char *screen_names[] = { "Main", "imagenes", "objetos1", "objetos2" };
static const char *object_names[] = { "main", "imagenes", "objetos1", "objetos2", "obj0", "obj1", "obj1__obj0", "obj2", "obj2__obj0", "obj3", "obj3__obj0", "obj4", "obj5", "obj6", "switch1", "checkbox1", "my_colorwheel", "my_led", "my_slider" };


typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_imagenes,
    tick_screen_objetos1,
    tick_screen_objetos2,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_imagenes();
    create_screen_objetos1();
    create_screen_objetos2();
}
