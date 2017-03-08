// Solar PV power diversion
// Modulate charge rate based on solar PV output
// Glyn Hudson | OpenEnergyMonitor.org

#include <Arduino.h>
#include "emonesp.h"

// 1: Eco:
// Charging level moderated to match solar PV production down to a minimum level of 6A (1.4Kw)
// Charging is never paused
//
// 2: Eco+ :
// Charging level is moderated to match available excess solar PV power. e.g. Solar PV gen - onsite consumption
// Charging is pasued if excess power (solar PV - consumption) drop below 6A (1.4kW)
//
// 3: Normal / Fast Charge (default):
// Charging at maximum rate irrespective of solar PV output

// Default to normal charging unless set. Divert mode always defaults back to 3 if unit is reset (not saved in EEPROM)
byte divertmode = 3;

void solarpv_divert_update(){
DEBUG.print("Divert mode: ");
DEBUG.println(divertmode);
}


void change_divertmode(byte newmode){
  divertmode = newmode;
}
