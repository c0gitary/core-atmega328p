#ifndef TOOLS_H
#define TOOLS_H

#define Bit _BV
#define Set(_reg, _bit) ((_reg) = (_bit))
#define SetBit(_reg, _bit) ((_reg) |= (Bit(_bit)))
#define ClearBit(_reg, _bit) ((_reg) &= ~(Bit(_bit)))
#define ToggleBit(_reg, _bit) ((_reg) ^= (Bit(_bit)))

#define map(value, in_min, in_max, out_min, out_max) \
    ((value-in_min) * ((out_max-out_min)/(in_max-in_min)+out_min))

#define min(a, b) ((a) < (b) ? (a) : (b))

#define max(a, b) ((a) > (b) ? (a) : (b))

#define abs(a) ((a) >= (0) ? (a) : (-(a)))

#define constrain(value, min_value, max_value) \
    ((value) <= (min_value) ? (min_value) : ((value) >= (max_value) ? (max_value) : (value)))

#define swap(x, y) do{\
    __typeof__(x) _tmp = (x);\
    (x) = (y);\
    (y) = (_tmp);\
} while(0)

#endif