#include "be_constobj.h"

static be_define_const_map_slots(be_class_audio_output_i2s_map) {
    { be_const_key(INTERNAL_PDM, -1), be_const_int(AudioOutputI2S::INTERNAL_PDM) },
    { be_const_key(INTERNAL_DAC, 2), be_const_int(AudioOutputI2S::INTERNAL_DAC) },
    { be_const_key(init, -1), be_const_func(i2s_output_i2s_init) },
    { be_const_key(EXTERNAL_I2S, 1), be_const_int(AudioOutputI2S::EXTERNAL_I2S) },
    { be_const_key(deinit, -1), be_const_func(i2s_output_i2s_deinit) },
    { be_const_key(stop, -1), be_const_func(i2s_output_i2s_stop) },
};

static be_define_const_map(
    be_class_audio_output_i2s_map,
    6
);

BE_EXPORT_VARIABLE be_define_const_class(
    be_class_audio_output_i2s,
    0,
    (bclass *)&be_class_audio_output,
    AudioOutputI2S
);
