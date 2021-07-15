#include "../../inc/MarlinConfig.h"


#include "../gcode.h"

#if ENABLED(FAST_PWM_FAN)

void GcodeSuite::M9891() {
  const uint8_t pport = parser.byteval('P');
  const uint16_t dfreq = parser.ushortval('F');
  set_pwm_frequency((pin_t)pport, (int)dfreq);
}

#endif
