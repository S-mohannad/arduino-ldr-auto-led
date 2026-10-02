# 🌑 LDR Light Sensor — Auto LED Control

> **Arduino Project #10** — LED يضيء تلقائياً في الظلام ويطفي عند الضوء باستخدام مستشعر LDR

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Level](https://img.shields.io/badge/Level-Beginner-green?style=for-the-badge)](https://github.com/S-mohannad)

---

## 📋 Description

يقرأ Arduino قيمة مستشعر الضوء **LDR** عبر المدخل التماثلي A0 — إذا كانت القيمة أقل من 450 (ظلام) يضيء LED، وإذا كانت أعلى (ضوء) يطفيه. مبدأ عمل أنظمة الإضاءة التلقائية في الشوارع والمنازل.

---

## 🔌 Circuit

```
Arduino UNO
┌─────────────────┐
│            A0 ●─┼──────────┬── LDR ── 5V
│                 │          │
│                 │        [10kΩ]
│                 │          │
│           GND ●─┼──────────┘
│                 │
│            13 ●─┼──[220Ω]──💡 LED ── GND
└─────────────────┘
```

- 🔆 LDR على Pin A0 مع مقاومة سحب 10kΩ إلى GND (Voltage Divider)
- 💡 LED على Pin 13 مع مقاومة 220Ω

---

## 💡 Concepts Used

- `analogRead()` — قراءة قيمة تماثلية (0-1023) من مستشعر LDR
- **Voltage Divider** — دائرة منقسم الجهد لتحويل مقاومة LDR لجهد قابل للقراءة
- `if / else` — مقارنة القيمة مع العتبة (threshold = 450)
- **LDR (Light Dependent Resistor)** — مقاومته تقل عند الضوء وترتفع في الظلام

---

## 📊 Behavior

| حالة الضوء | قيمة A0 | حالة LED |
|-----------|---------|---------|
| ظلام 🌑 | < 450 | HIGH (يضيء) 💡 |
| ضوء ☀️ | > 450 | LOW (يطفي) ⚫ |

> يمكن تعديل قيمة العتبة `450` حسب بيئة الإضاءة المحيطة

---

## 🔗 Code

```cpp
int v = 0;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  v = analogRead(A0);

  if (v > 450) {
    digitalWrite(13, LOW);   // ضوء — LED مطفي
  } else {
    digitalWrite(13, HIGH);  // ظلام — LED يضيء
  }
}
```

---

## 🔧 How to Run

1. افتح **Arduino IDE**
2. وصّل الدائرة كما في الرسم
3. انسخ الكود والصقه
4. اختر **Board:** Arduino UNO
5. اختر **Port** الصحيح
6. اضغط ⬆️ **Upload**
7. غطِّ المستشعر بيدك وشاهد LED يضيء تلقائياً

---

## 👨‍💻 Author

**S-mohannad** — [@S-mohannad](https://github.com/S-mohannad)
