#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/queue.h"

TaskHandle_t task1_handle;
TaskHandle_t task2_handle;
TaskHandle_t task3_handle;
TaskHandle_t task4_handle;
TaskHandle_t task5_handle;

int count;
QueueHandle_t msg_queue;

static int taskcore=1;

#define MQ_SIZE 4
#define MSG_SIZE 300

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
    while(1)
    {
    printf("Task3:started\n");
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    vTaskDelate(task3_handle);
    }
}

void task_4(void *data)
{
    
    int count task_data=100;
    while(1)
    {
        int +=count;
        if(count>5)
        {
            printf("Task4:started\n");
            msg_queue=xMessageQueueSend(msg_queue,pdMS_TO_TICK(4000));
            vTaskDelay(4000 / portTICK_PERIOD_MS);
            vTaskDelate(NULL);
        }
    }
    
}

void task_5(void *data)
{
    
    int count buffer=200;
    while(1)
    {
        int +=count;
        if(count>5)
        {
            printf("Task5:started\n");
            msg_queue=xMessageQueueReceive(msg_queue,pdMAX_DELAY);
            vTaskDelay(5000 / portTICK_PERIOD_MS);
            vTaskDelate(NULL);
        }
    }

}

void app_main()
{
    printf("Main Tasks\n");

    msg_queue=xMessageQueueCreate(MQ_SIZE,MSG_SIZE);
    
    xTaskPinnedToCore(task_1,"First Task",2048,NULL,5,&task1_handle,taskcore);
    xTaskPinnedToCore(task_2,"second Task",2048,NULL,6,&task2_handle,taskcore);
    xTaskPinnedToCore(task_3,"Third Task",2048,NULL,7,&task3_handle,taskcore);
    xTaskPinnedToCore(task_4,"Fourth Task",2048,NULL,8,&task4_handle,taskcore);
    xTaskPinnedToCore(task_5,"fifth Task",2048,NULL,9,&task5_handle,taskcore);

}