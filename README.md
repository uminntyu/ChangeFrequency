# ChangeFrequency.h

## 概要
ArduinoMegaADKのpwm周波数を変更するためのライブラリ

#### タイマ/カウンタの種類
* TCCR0 ・・・ 8bitタイマ/カウンタ  
* TCCR1 ・・・ 16bitタイマ/カウンタ  
* TCCR2 ・・・ 8bitタイマ/カウンタ  
* TCCR3 ・・・ 16bitタイマ/カウンタ  
* TCCR4 ・・・ 16bitタイマ/カウンタ  

## Get Started
    #include <Arduino.h>
    #include "ChangeFrequency.h"

    ChangeFrequency changeFre;

    void setup()
    {
      changeFre.setPWMFrequency( TIM_ALL , DIV_8 );
      analogWrite( 13, 255 );
    }

    void loop()
    {
    }
    


