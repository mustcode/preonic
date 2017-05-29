#include "preonic.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define KC_CN_L (LCTL(KC_LEFT))
#define KC_CN_R (LCTL(KC_RGHT))
#define KC_CN_U (LCTL(KC_UP))
#define KC_CN_D (LCTL(KC_DOWN))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | GUI  | Alt  | Ctrl |  "   |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL },
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_GRV,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL, KC_QUOT}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | GUI  | Alt  | Ctrl |  "   |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL },
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_GRV,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL, KC_QUOT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | GUI  | Alt  | Ctrl |  /   |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL },
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT },
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT},
  {KC_GRV,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL, KC_SLSH}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  | F11  | F12  |      |      |      |      |   (  |   )  |   [  |   ]  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |      |   -  |   =  |   {  |   }  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |   _  |   +  |   |  |   \  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | PScr | Ctrl | Alt  | GUI  |      |    Space    |      | GUI  | Alt  | Ctrl | Caps |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_INS },
  {KC_TAB,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_DEL },
  {KC_LCTL, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL , KC_LCBR, KC_RCBR, KC_ENT },
  {KC_LSFT, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_PIPE, KC_BSLS, KC_RSFT},
  {KC_PSCR, KC_LCTL, KC_LALT, KC_LGUI, _______,  KC_SPC,  KC_SPC, _______, KC_RGUI, KC_RALT, KC_RCTL, KC_CAPS}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   7  |   8  |   9  |   /  |      |      |      | PgUp |      |      | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   4  |   5  |   6  |   *  |      |      | Home |  Up  | End  |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   1  |   2  |   3  |   -  | Mute |      | Left | Down |Right |      |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   0  |   .  |   =  |   +  | Vol- | Vol+ | Cn-L | PgDn | Cn-R |      |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |NumLk | Ctrl | Alt  | GUI  |      |    Space    |      | GUI  | Alt  | Ctrl |Pause |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_ESC,  KC_P7,   KC_P8,   KC_P9,   KC_PSLS, _______, _______, _______, KC_PGUP, _______, _______, KC_INS },
  {KC_TAB,  KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______, _______, KC_HOME, KC_UP,   KC_END , _______, KC_DEL },
  {KC_LCTL, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_MUTE, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_ENT },
  {KC_LSFT, KC_P0,   KC_PDOT, KC_PEQL, KC_PPLS, KC_VOLD, KC_VOLU, KC_CN_L, KC_PGDN, KC_CN_R, _______, KC_RSFT},
  {KC_NLCK, KC_LCTL, KC_LALT, KC_LGUI, _______,  KC_SPC,  KC_SPC, _______, KC_RGUI, KC_RALT, KC_RCTL, KC_PAUS}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);

float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
            #endif
            persistent_default_layer_set(1UL<<_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_colemak, false, 0);
            #endif
            persistent_default_layer_set(1UL<<_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
            #endif
            persistent_default_layer_set(1UL<<_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
          return false;
          break;
      }
    return true;
};

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
