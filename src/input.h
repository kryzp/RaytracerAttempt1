#pragma once

#include <glm/vec2.hpp>

enum MouseButton
{
    INP_MB_UNKNOWN = 0,
    INP_MB_LEFT = 1,
    INP_MB_MIDDLE = 2,
    INP_MB_RIGHT = 3,
    INP_MB_SIDE_BOTTOM = 4,
    INP_MB_SIDE_TOP = 5,
    INP_MB_MAX
};

enum Key
{
    INP_KEY_UNKNOWN = 0,
    INP_KEY_A = 4,
    INP_KEY_B = 5,
    INP_KEY_C = 6,
    INP_KEY_D = 7,
    INP_KEY_E = 8,
    INP_KEY_F = 9,
    INP_KEY_G = 10,
    INP_KEY_H = 11,
    INP_KEY_I = 12,
    INP_KEY_J = 13,
    INP_KEY_K = 14,
    INP_KEY_L = 15,
    INP_KEY_M = 16,
    INP_KEY_N = 17,
    INP_KEY_O = 18,
    INP_KEY_P = 19,
    INP_KEY_Q = 20,
    INP_KEY_R = 21,
    INP_KEY_S = 22,
    INP_KEY_T = 23,
    INP_KEY_U = 24,
    INP_KEY_V = 25,
    INP_KEY_W = 26,
    INP_KEY_X = 27,
    INP_KEY_Y = 28,
    INP_KEY_Z = 29,
    INP_KEY_D1 = 30,
    INP_KEY_D2 = 31,
    INP_KEY_D3 = 32,
    INP_KEY_D4 = 33,
    INP_KEY_D5 = 34,
    INP_KEY_D6 = 35,
    INP_KEY_D7 = 36,
    INP_KEY_D8 = 37,
    INP_KEY_D9 = 38,
    INP_KEY_D0 = 39,
    INP_KEY_ENTER = 40,
    INP_KEY_ESCAPE = 41,
    INP_KEY_BACKSPACE = 42,
    INP_KEY_TAB = 43,
    INP_KEY_SPACE = 44,
    INP_KEY_MINUS = 45,
    INP_KEY_EQUALS = 46,
    INP_KEY_LEFT_BRACKET = 47,
    INP_KEY_RIGHT_BRACKET = 48,
    INP_KEY_BACKSLASH = 49,
    INP_KEY_NON_US_HASH = 50,
    INP_KEY_SEMICOLON = 51,
    INP_KEY_APOSTROPHE = 52,
    INP_KEY_GRAVE = 53,
    INP_KEY_COMMA = 54,
    INP_KEY_PERIOD = 55,
    INP_KEY_SLASH = 56,
    INP_KEY_CAPSLOCK = 57,
    INP_KEY_F1 = 58,
    INP_KEY_F2 = 59,
    INP_KEY_F3 = 60,
    INP_KEY_F4 = 61,
    INP_KEY_F5 = 62,
    INP_KEY_F6 = 63,
    INP_KEY_F7 = 64,
    INP_KEY_F8 = 65,
    INP_KEY_F9 = 66,
    INP_KEY_F10 = 67,
    INP_KEY_F11 = 68,
    INP_KEY_F12 = 69,
    INP_KEY_PRINT_SCREEN = 70,
    INP_KEY_SCROLL_LOCK = 71,
    INP_KEY_PAUSE = 72,
    INP_KEY_INSERT = 73,
    INP_KEY_HOME = 74,
    INP_KEY_PAGE_UP = 75,
    INP_KEY_DELETE = 76,
    INP_KEY_END = 77,
    INP_KEY_PAGE_DOWN = 78,
    INP_KEY_RIGHT = 79,
    INP_KEY_LEFT = 80,
    INP_KEY_DOWN = 81,
    INP_KEY_UP = 82,
    INP_KEY_NUMLOCK_CLEAR = 83,
    INP_KEY_KP_DIVIDE = 84,
    INP_KEY_KP_MULTIPLY = 85,
    INP_KEY_KP_MINUS = 86,
    INP_KEY_KP_PLUS = 87,
    INP_KEY_KP_ENTER = 88,
    INP_KEY_KP_1 = 89,
    INP_KEY_KP_2 = 90,
    INP_KEY_KP_3 = 91,
    INP_KEY_KP_4 = 92,
    INP_KEY_KP_5 = 93,
    INP_KEY_KP_6 = 94,
    INP_KEY_KP_7 = 95,
    INP_KEY_KP_8 = 96,
    INP_KEY_KP_9 = 97,
    INP_KEY_KP_0 = 98,
    INP_KEY_KP_PERIOD = 99,
    INP_KEY_NON_US_BACKSLASH = 100,
    INP_KEY_APPLICATION = 101,
    INP_KEY_POWER = 102,
    INP_KEY_KP_EQUALS = 103,
    INP_KEY_F13 = 104,
    INP_KEY_F14 = 105,
    INP_KEY_F15 = 106,
    INP_KEY_F16 = 107,
    INP_KEY_F17 = 108,
    INP_KEY_F18 = 109,
    INP_KEY_F19 = 110,
    INP_KEY_F20 = 111,
    INP_KEY_F21 = 112,
    INP_KEY_F22 = 113,
    INP_KEY_F23 = 114,
    INP_KEY_F24 = 115,
    INP_KEY_EXECUTE = 116,
    INP_KEY_HELP = 117,
    INP_KEY_MENU = 118,
    INP_KEY_SELECT = 119,
    INP_KEY_STOP = 120,
    INP_KEY_AGAIN = 121,
    INP_KEY_UNDO = 122,
    INP_KEY_CUT = 123,
    INP_KEY_COPY = 124,
    INP_KEY_PASTE = 125,
    INP_KEY_FIND = 126,
    INP_KEY_MUTE = 127,
    INP_KEY_VOLUME_UP = 128,
    INP_KEY_VOLUME_DOWN = 129,
    INP_KEY_KP_COMMA = 133,
    INP_KEY_KP_EQUALS_AS_400 = 134,
    INP_KEY_INTERNATIONAL1 = 135,
    INP_KEY_INTERNATIONAL2 = 136,
    INP_KEY_INTERNATIONAL3 = 137,
    INP_KEY_INTERNATIONAL4 = 138,
    INP_KEY_INTERNATIONAL5 = 139,
    INP_KEY_INTERNATIONAL6 = 140,
    INP_KEY_INTERNATIONAL7 = 141,
    INP_KEY_INTERNATIONAL8 = 142,
    INP_KEY_INTERNATIONAL9 = 143,
    INP_KEY_LANGUAGE1 = 144,
    INP_KEY_LANGUAGE2 = 145,
    INP_KEY_LANGUAGE3 = 146,
    INP_KEY_LANGUAGE4 = 147,
    INP_KEY_LANGUAGE5 = 148,
    INP_KEY_LANGUAGE6 = 149,
    INP_KEY_LANGUAGE7 = 150,
    INP_KEY_LANGUAGE8 = 151,
    INP_KEY_LANGUAGE9 = 152,
    INP_KEY_ALT_ERASE = 153,
    INP_KEY_SYS_REQ = 154,
    INP_KEY_CANCEL = 155,
    INP_KEY_CLEAR = 156,
    INP_KEY_PRIOR = 157,
    INP_KEY_RETURN2 = 158,
    INP_KEY_SEPERATOR = 159,
    INP_KEY_OUT = 160,
    INP_KEY_OPER = 161,
    INP_KEY_CLEAR_AGAIN = 162,
    INP_KEY_CRSEL = 163,
    INP_KEY_EXSEL = 164,
    INP_KEY_KP_00 = 176,
    INP_KEY_KP_000 = 177,
    INP_KEY_THOUSANDS_SEPERATOR = 178,
    INP_KEY_DECIMAL_SEPERATOR = 179,
    INP_KEY_CURRENCY_UNIT = 180,
    INP_KEY_CURRENCY_SUBUNIT = 181,
    INP_KEY_KP_LEFT_PARENT = 182,
    INP_KEY_KP_RIGHT_PARENT = 183,
    INP_KEY_KP_LEFT_BRACE = 184,
    INP_KEY_KP_RIGHT_BRACE = 185,
    INP_KEY_KP_TAB = 186,
    INP_KEY_KP_BACKSPACE = 187,
    INP_KEY_KP_A = 188,
    INP_KEY_KP_B = 189,
    INP_KEY_KP_C = 190,
    INP_KEY_KP_D = 191,
    INP_KEY_KP_E = 192,
    INP_KEY_KP_F = 193,
    INP_KEY_KP_XOR = 194,
    INP_KEY_KP_POWER = 195,
    INP_KEY_KP_PERCENT = 196,
    INP_KEY_KP_LESS = 197,
    INP_KEY_KP_GREATER = 198,
    INP_KEY_KP_AMPERSAND = 199,
    INP_KEY_KP_DOUBLE_AMPERSAND = 200,
    INP_KEY_KP_VERTICAL_BAR = 201,
    INP_KEY_KP_DOUBLE_VERTICAL_BAR = 202,
    INP_KEY_KP_COLON = 203,
    INP_KEY_KP_HASH = 204,
    INP_KEY_KP_SPACE = 205,
    INP_KEY_KP_AT = 206,
    INP_KEY_KP_EXCLAM = 207,
    INP_KEY_KP_MEM_STORE = 208,
    INP_KEY_KP_MEM_RECALL = 209,
    INP_KEY_KP_MEM_CLEAR = 210,
    INP_KEY_KP_MEM_ADD = 211,
    INP_KEY_KP_MEM_SUBTRACT = 212,
    INP_KEY_KP_MEM_MULTIPLY = 213,
    INP_KEY_KP_MEM_DIVIDE = 214,
    INP_KEY_KP_PLUS_MINUS = 215,
    INP_KEY_KP_CLEAR = 216,
    INP_KEY_KP_CLEAR_ENTRY = 217,
    INP_KEY_KP_BINARY = 218,
    INP_KEY_KP_OCTAL = 219,
    INP_KEY_KP_DECIMAL = 220,
    INP_KEY_KP_HEXADECIMAL = 221,
    INP_KEY_LEFT_CONTROL = 224,
    INP_KEY_LEFT_SHIFT = 225,
    INP_KEY_LEFT_ALT = 226,
    INP_KEY_LEFT_SUPER = 227,
    INP_KEY_RIGHT_CONTROL = 228,
    INP_KEY_RIGHT_SHIFT = 229,
    INP_KEY_RIGHT_ALT = 230,
    INP_KEY_RIGHT_SUPER = 231,
    INP_KEY_MAX
};

struct KeyboardState
{
    bool down[INP_KEY_MAX];
    char text[256];
};

struct MouseState
{
    bool down[INP_MB_MAX];
    glm::vec2 screen_position;
    glm::vec2 draw_position;
    glm::vec2 position;
    glm::vec2 wheel;
};

class Input
{
public:
    static Input* inst()
    {
        static Input* instance = nullptr;
        if (!instance) { instance = new Input(); }
        return instance;
    }

    bool init();
    void destroy();

    void update();

    bool down_mb(int mb);
    bool down_key(int key);

    bool released_mb(int mb);
    bool released_key(int key);

    bool pressed_mb(int mb);
    bool pressed_key(int key);

    bool ctrl();
    bool shift();
    bool alt();

    const char* text();

    glm::vec2 mouse_screen_pos();
    glm::vec2 mouse_draw_pos();
    glm::vec2 mouse_position();
    glm::vec2 mouse_wheel();
    glm::vec2 mouse_wheel_change();

    void on_mouse_move(float x, float y);
    void on_mouse_screen_move(float x, float y);

    void on_mouse_down(int button);
    void on_mouse_up(int button);
    void on_mouse_wheel(float x, float y);

    void on_key_down(int key);
    void on_key_up(int key);
    void on_text_utf8(const char* text);

private:
    KeyboardState m_kb;
    KeyboardState m_kb_prev;

    MouseState m_mouse;
    MouseState m_mouse_prev;
};
