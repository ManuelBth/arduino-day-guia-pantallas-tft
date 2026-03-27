/**
 * @file LedController.h
 * @brief Controlador para el LED de la UI
 * @description Maneja el color y brillo del LED basados en ColorWheel y Slider
 */

#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include <lvgl.h>

/**
 * @brief Inicializa el control del LED
 * @details Configura los callbacks para ColorWheel y Slider, y conecta los eventos
 *          al LED para que cambie de color e intensidad dinámicamente
 */
void ledController_init();

/**
 * @brief Actualiza el color del LED
 * @param color Nuevo color en formato lv_color_t
 */
void ledController_setColor(lv_color_t color);

/**
 * @brief Actualiza el brillo del LED
 * @param brightness Valor de 0-255
 */
void ledController_setBrightness(uint8_t brightness);

#endif // LED_CONTROLLER_H
