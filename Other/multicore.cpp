#include "multicore.h"

//multicore
TaskHandle_t Core0;
TaskHandle_t Core1;

void core0setup(){
    xTaskCreatePinnedToCore(
             core0,     /* Task function. */
             "Core0",   /* name of task. */
             10000,     /* Stack size of task */
             NULL,      /* parameter of the task */
             1,         /* priority of the task */
             &Task1,    /* Task handle to keep track of created task */
             0);        /* pin task to core 0 */
}

void core1setup(){
    xTaskCreatePinnedToCore(
             core1,     /* Task function. */
             "Core1",   /* name of task. */
             10000,     /* Stack size of task */
             NULL,      /* parameter of the task */
             1,         /* priority of the task */
             &Core1,    /* Task handle to keep track of created task */
             1);        /* pin task to core 1 */
}

void Task1code( void * pvParameters ){
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
  } 
}

void createCoreTask(int core, void (*func)){
    if (core == 0){
        const void Core0(void * pvParameters){
            func();
        }
    }
    else if (core == 1){
        const void Core1(void * pvParameters){
            func();
        }
    }
}

void clearcore0(){
    vTaskDelete(Core0);
}

void clearcore1(){
    vTaskDelete(Core1);
}