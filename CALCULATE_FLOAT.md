# IEEE 754 — Representing 3.234 (Single Precision, 32-bit)

---

## The Structure

A 32-bit float has 3 fields:

| Sign (1 bit) | Exponent (8 bits) | Mantissa (23 bits) |
|:---:|:---:|:---:|
| 0 or 1 | biased exponent | fractional part |

---

## Step 1 — Sign bit

3.234 is **positive**, so:

```
sign = 0
```

---

## Step 2 — Convert to binary

**Integer part: 3**
```
3 ÷ 2 = 1 remainder 1
1 ÷ 2 = 0 remainder 1
→ 3 in binary = 11
```

**Fractional part: 0.234** — multiply by 2, take the integer part each time:
```
0.234 × 2 = 0.468  → 0
0.468 × 2 = 0.936  → 0
0.936 × 2 = 1.872  → 1
0.872 × 2 = 1.744  → 1
0.744 × 2 = 1.488  → 1
0.488 × 2 = 0.976  → 0
0.976 × 2 = 1.952  → 1
0.952 × 2 = 1.904  → 1
0.904 × 2 = 1.808  → 1
0.808 × 2 = 1.616  → 1
...
→ 0.234 ≈ .00111011110...
```

So: **3.234 ≈ `11.00111011110...` in binary**

---

## Step 3 — Normalize

Shift the binary point so there's exactly one `1` before it:

```
11.00111011110... × 2⁰
= 1.100111011110... × 2¹
```

The form is always **1.something × 2^n**. Here, **n = 1**.

---

## Step 4 — Exponent field (biased)

IEEE 754 adds a **bias of 127** to the exponent so it can represent negative exponents without a sign bit:

```
exponent = 1 + 127 = 128
128 in binary = 10000000
```

---

## Step 5 — Mantissa (fraction field)

Take everything **after** the `1.` in the normalized form — the leading `1` is implicit (not stored):

```
1.100111011110...
    ↑ store this part (23 bits)

10011101111000010100011...
```

Truncated/rounded to 23 bits:
```
10011101111000010100011
```

---

## Final Result

```
 Sign  |  Exponent  |         Mantissa
   0   | 1 0000000  | 10011101111000010100011
```

All together (32 bits):
```
0 10000000 10011101111000010100011
```

In hex: **`0x404F0A3D`**

---

## Quick sanity check

You can verify this in C:

```c
#include <stdio.h>

int main(void)
{
    float        f = 3.234f;
    unsigned int *p = (unsigned int *)&f;
    printf("%08X\n", *p); // should print 404F0A3D
}
```

---

## Why it's not exact

Notice the fractional part repeats — 0.234 has no exact binary representation (just like 1/3 has no exact decimal). This is why floating point has rounding errors. `3.234f` in memory is actually `3.2339999...`.
