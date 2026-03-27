/**
 * @file main.cpp
 * @brief Arduino Day 2026 - Pantalla TFT con LVGL y EEZ Studio
 * @description Inicializa LVGL, TFT_eSPI, touchscreen y carga la UI
 */

#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>

// UI de EEZ Studio
#include "ui/ui.h"

// Controlador del LED
#include "LedController.h"

// Pines del touchscreen
#define TOUCH_CS 5
#define TOUCH_IRQ 17

// Instancias globales
static TFT_eSPI tft = TFT_eSPI();
static XPT2046_Touchscreen ts(TOUCH_CS, TOUCH_IRQ);

// Buffer para LVGL (1/10 de la resolución para reducir memoria)
static lv_color_t buf1[LV_HOR_RES_MAX * LV_VER_RES_MAX / 10];
static lv_color_t buf2[LV_HOR_RES_MAX * LV_VER_RES_MAX / 10];
static lv_disp_draw_buf_t draw_buf;

/**
 * @brief Callback de flush para enviar pixels al display
 */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    uint32_t w = lv_area_get_width(area);
    uint32_t h = lv_area_get_height(area);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)color_p, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

/**
 * @brief Callback de lectura del touchscreen
 */
void my_touch_read(lv_indev_drv_t *indev, lv_indev_data_t *data) {
    if (ts.touched()) {
        TS_Point p = ts.getPoint();
        
        // Mapeo de coordenadas CORREGIDO (Calibración Real)
        // Datos obtenidos de logs:
        // Izquierda (X=0): RAW X ~3850
        // Derecha (X=320): RAW X ~390
        // Arriba (Y=0): RAW Y ~3665
        // Abajo (Y=240): RAW Y ~390
        
        int16_t touchX = map(p.x, 3850, 390, 0, LV_HOR_RES_MAX); 
        int16_t touchY = map(p.y, 3665, 390, 0, LV_VER_RES_MAX); 

        // Limitar coordenadas para evitar errores de LVGL
        if(touchX < 0) touchX = 0;
        if(touchX >= LV_HOR_RES_MAX) touchX = LV_HOR_RES_MAX - 1;
        if(touchY < 0) touchY = 0;
        if(touchY >= LV_VER_RES_MAX) touchY = LV_VER_RES_MAX - 1;
        
        data->point.x = touchX;
        data->point.y = touchY;
        data->state = LV_INDEV_STATE_PRESSED;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

void setup() {
    Serial.begin(115200);
    delay(10);
    Serial.println("\n=== Arduino Day 2026 - TFT + LVGL ===");

    // ========== Inicializar TFT_eSPI ==========
    Serial.println("Inicializando TFT_eSPI...");
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    Serial.println("TFT inicializado");

    // ========== Inicializar touchscreen ==========
    Serial.println("Inicializando touchscreen...");
    ts.begin();
    ts.setRotation(1);
    Serial.println("Touchscreen inicializado");

    // ========== Inicializar LVGL ==========
    Serial.println("Inicializando LVGL...");
    lv_init();

    // Configurar el buffer de display (1/10 del tamaño total)
    lv_disp_draw_buf_init(&draw_buf, buf1, buf2, LV_HOR_RES_MAX * LV_VER_RES_MAX / 10);

    // Configurar el driver de display
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf = &draw_buf;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.hor_res = LV_HOR_RES_MAX;
    disp_drv.ver_res = LV_VER_RES_MAX;
    lv_disp_drv_register(&disp_drv);
    Serial.println("Display driver registrado");

    // Configurar el driver de input (touchscreen)
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touch_read;
    lv_indev_drv_register(&indev_drv);
    Serial.println("Touch driver registrado");

    // Inicializar el UI de EEZ Studio
    Serial.println("Inicializando UI...");
    ui_init();
    Serial.println("UI cargada");

    // Inicializar el controlador del LED (conecta ColorWheel y Slider al LED)
    Serial.println("Inicializando LED controller...");
    ledController_init();
    Serial.println("LED controller listo");

    Serial.println("\n=== Sistema listo ===");
}

unsigned long lastTick = 0;

void loop() {
    // Procesar tareas de LVGL cada 5ms
    unsigned long now = millis();
    if (now - lastTick >= 5) {
        lv_timer_handler();
        lastTick = now;
    }
    
    // Actualizar UI (EEZ Studio)
    ui_tick();
    
    // Incrementar tick de LVGL (1ms)
    lv_tick_inc(1);
    
    // Pequeño delay para no saturar el CPU
    delay(1);
}
