/**
 * @file LedController.cpp
 * @brief Implementación del control del LED
 * @description Maneja el color y brillo del LED basados en ColorWheel y Slider
 * 
 * Este módulo conecta los widgets de la UI al LED:
 * - ColorWheel → determina el color del LED
 * - Slider → determina el brillo/intensidad del LED
 * 
 * ARQUITECTURA DEL CÓDIGO:
 * ========================
 * 
 * 1. CALLBACKS:
 *    LVGL funciona con un sistema de eventos. Cuando el usuario interactúa
 *    con un widget (toca el colorwheel o slider), LVGL dispara un evento.
 *    Nosotros registramos un callback que se ejecuta cuando eso ocurre.
 * 
 * 2. FLUJO DE DATOS:
 *    [Usuario toca ColorWheel] 
 *           ↓
 *    [Evento: LV_EVENT_VALUE_CHANGED]
 *           ↓
 *    [Callback: colorwheel_changed()]
 *           ↓
 *    [lv_colorwheel_get_color() obtiene el color]
 *           ↓
 *    [lv_led_set_color() aplica al LED]
 * 
 *    [Usuario mueve Slider]
 *           ↓
 *    [Evento: LV_EVENT_VALUE_CHANGED]
 *           ↓
 *    [Callback: slider_changed()]
 *           ↓
 *    [lv_slider_get_value() obtiene el valor]
 *           ↓
 *    [lv_led_set_brightness() aplica al LED]
 * 
 * 3. PUNTEROS A OBJETOS:
 *    Los widgets (colorwheel, led, slider) son creados por EEZ Studio.
 *    Nosotros los accedemos a través del objeto global 'objects' que
 *    contiene punteros a todos los widgets de la UI.
 */

#include <Arduino.h>
#include <lvgl.h>
#include "LedController.h"
#include "ui/screens.h"
#include "ui/ui.h"

/**
 * @brief Callback cuando cambia el ColorWheel
 * 
 * EXPLICACIÓN DETALLADA:
 * ======================
 * Este callback se ejecuta cada vez que el usuario selecciona un color
 * en el widget ColorWheel. El flujo es:
 * 
 * 1. Obtenemos el puntero al objeto ColorWheel desde 'objects.my_colorwheel'
 *    - 'objects' es una variable global definida por EEZ Studio
 *    - Contiene punteros a todos los widgets creados en la UI
 * 
 * 2. Obtenemos el color seleccionado usando lv_colorwheel_get_color()
 *    - Esta función devuelve un lv_color_t (estructura con RGB)
 *    - En LVGL v8 el formato es RGB565 (16 bits)
 * 
 * 3. Obtenemos el puntero al LED desde 'objects.my_led'
 * 
 * 4. Aplicamos el color con lv_led_set_color()
 *    - El LED instantáneamente cambia al nuevo color
 * 
 * @param event Evento de LVGL (contiene info sobre qué widget disparó el evento)
 */
static void colorwheel_changed(lv_event_t *event) {
    // 1. Obtener el widget que disparó el evento
    lv_obj_t *colorwheel = lv_event_get_target(event);
    
    // 2. Obtener el color seleccionado del ColorWheel (usando función get_rgb)
    lv_color_t color = lv_colorwheel_get_rgb(colorwheel);
    
    // 3. Obtener el LED y aplicar el color
    if (objects.my_led != NULL) {
        lv_led_set_color(objects.my_led, color);
    }
    
    // Debug: ver el color en serial (opcional)
    // Serial.printf("Color changed: R=%d, G=%d, B=%d\n", color.red, color.green, color.blue);
}

/**
 * @brief Callback cuando cambia el Slider
 * 
 * EXPLICACIÓN DETALLADA:
 * ======================
 * Este callback se ejecuta cuando el usuario mueve el slider.
 * El brillo del LED en LVGL va de 0 (apagado) a 255 (máximo).
 * 
 * 1. Obtenemos el puntero al Slider desde 'objects.my_slider'
 * 
 * 2. Obtenemos el valor actual con lv_slider_get_value()
 *    - Devuelve un entero entre el rango configurado (0-255)
 * 
 * 3. Aplicamos al LED con lv_led_set_brightness()
 *    - 0 = LED apagado
 *    - 255 = LED a máximo brillo
 * 
 * @param event Evento de LVGL
 */
static void slider_changed(lv_event_t *event) {
    // 1. Obtener el widget que disparó el evento
    lv_obj_t *slider = lv_event_get_target(event);
    
    // 2. Obtener el valor del slider (0-255 según lo configurado en screens.c)
    int16_t value = lv_slider_get_value(slider);
    
    // 3. Aplicar el brillo al LED
    if (objects.my_led != NULL) {
        lv_led_set_brightness(objects.my_led, value);
    }
    
    // Debug: ver el valor en serial (opcional)
    // Serial.printf("Slider value: %d\n", value);
}

/**
 * @brief Inicializa el control del LED
 * 
 * EXPLICACIÓN DETALLADA:
 * ======================
 * Esta función conecta los widgets al LED注册 los callbacks:
 * 
 * 1. Obtenemos el ColorWheel de 'objects.my_colorwheel'
 *    Registramos el callback 'colorwheel_changed' para el evento
 *    LV_EVENT_VALUE_CHANGED (cuando cambia el valor/color)
 * 
 * 2. Obtenemos el Slider de 'objects.my_slider'
 *    Registramos el callback 'slider_changed' para el evento
 *    LV_EVENT_VALUE_CHANGED (cuando cambia la posición)
 * 
 * NOTA IMPORTANTE:
 * ================
 * Los widgets deben existir antes de registrar los callbacks.
 * Por eso llamamos a esta función DESPUÉS de ui_init(), cuando
 * todos los widgets ya están creados por EEZ Studio.
 */
void ledController_init() {
    // Conectar ColorWheel al LED
    if (objects.my_colorwheel != NULL) {
        lv_obj_add_event_cb(
            objects.my_colorwheel,           // Widget objetivo
            colorwheel_changed,               // Callback a ejecutar
            LV_EVENT_VALUE_CHANGED,          // Cuándo ejecutar: cuando cambia el valor
            NULL                              // Datos adicionales (none)
        );
        Serial.println("ColorWheel conectado al LED");
    }
    
    // Conectar Slider al LED
    if (objects.my_slider != NULL) {
        lv_obj_add_event_cb(
            objects.my_slider,               // Widget objetivo
            slider_changed,                  // Callback a ejecutar
            LV_EVENT_VALUE_CHANGED,          // Cuándo ejecutar: cuando cambia el valor
            NULL                              // Datos adicionales (none)
        );
        Serial.println("Slider conectado al LED");
    }
}

/**
 * @brief Actualiza el color del LED manualmente
 * @param color Nuevo color en formato lv_color_t
 */
void ledController_setColor(lv_color_t color) {
    if (objects.my_led != NULL) {
        lv_led_set_color(objects.my_led, color);
    }
}

/**
 * @brief Actualiza el brillo del LED manualmente
 * @param brightness Valor de 0-255
 */
void ledController_setBrightness(uint8_t brightness) {
    if (objects.my_led != NULL) {
        lv_led_set_brightness(objects.my_led, brightness);
    }
}
