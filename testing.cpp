#include <stdbool.h>
#include "ff.h"
#include <stdio.h>
#include <complex.h>
#include "arm_math.h"
#include "audioMoth.h"

#define NUMBER_OF_SAMPLES_IN_BUFFERS_DATA       4


static float32_t* buffersDATA[12];


int main(void) {

      //Create buffers
      buffersDATA[0] = (float32_t*)AM_EXTERNAL_SRAM_START_ADDRESS;
      for (int i = 1; i < 12; i += 1) {
          buffersDATA[i] = buffersDATA[i - 1] + NUMBER_OF_SAMPLES_IN_BUFFERS_DATA;
      }

      //Example of collected data
      float32_t var0[] = {-29.499557,-67.498978,-54.499176,-53.499191};


      //Pass collected data to one of created buffers
      for (int j = 0; j <NUMBER_OF_SAMPLES_IN_BUFFERS_DATA; j+= 1){
          *(buffersDATA[0]+j) = var0[j];
      }


      //Initialize file system
      AudioMoth_enableFileSystem();

      // Write text file
      FIL fpt;
      f_open(&fpt,"dataVAR.txt", FA_CREATE_ALWAYS | FA_WRITE);
      for (int i = 0; i <NUMBER_OF_SAMPLES_IN_BUFFERS_DATA; i+= 1){
          char str[8];
          sprintf(str, "%f, ", (int)var0[i]);
          f_puts(str,&fpt);
      }
      f_close(&fpt);

      // Write another text file
      FIL fptr;
      f_open(&fptr,"data.txt", FA_CREATE_ALWAYS | FA_WRITE);
      for (int i = 0; i <NUMBER_OF_SAMPLES_IN_BUFFERS_DATA; i+= 1){
          char str[8];
          sprintf(str, "%f, ", (int)*(buffersDATA[0]+i));
          f_puts(str,&fptr);
      }
      f_close(&fptr);

}
