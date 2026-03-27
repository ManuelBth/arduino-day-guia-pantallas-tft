#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_arduino;
extern const lv_img_dsc_t img_one;
extern const lv_img_dsc_t img_two;
extern const lv_img_dsc_t img_three;
extern const lv_img_dsc_t img_profile;
extern const lv_img_dsc_t img_jet;
extern const lv_img_dsc_t img_docker;
extern const lv_img_dsc_t img_back;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[8];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/