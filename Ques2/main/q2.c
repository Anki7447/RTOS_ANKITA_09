#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/timers.h"

TaskHandle_t task1_handle;
TaskHandle_t task2_handle;
TaskHandle_t task3_handle;

TimerHandle_t serial_timer_handle;

void serial_timer_callback(TimerHandle_t serial_timer_handle)
{
    printf{"timer fired\n"};

}

void task_1(void *data)
{
    while(1)
    {
    printf("Task1:started\n");  
        
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    vTaskDelate(task1_handle);
    }
}
void task_2(void *data)
{
    while(1)
    {
    printf("Task2:started\n");

    vTaskDelay(2000 / portTICK_PERIOD_MS);
    vTaskDelate(task2_handle);
    }
}

void task_3(void *data)
{
    printf("task3 started\n");

    printf("Timer Creating\n");
    serial_timer_handle=xTimerCreate("one_s_timer",pdMS_TO_TICK(10000),pdTRUE,0,serial_timer_callback);
    xTimerStarted(serial_timer_handle);
    
    vTaskDelay(10000 / portTICK_PERIOD_MS);

    vTaskDelate(task3_handle);
}

void app_main()
{
    printf("Main Tasks\n");

    xTaskCreate(task_1,"First Task",2048,NULL,5,&task1_handle);
    xTaskCreate(task_2,"second Task",2048,NULL,6,&task2_handle);
    xTaskCreate(task_3,"Third Task",2048,NULL,7,&task3_handle);

}
