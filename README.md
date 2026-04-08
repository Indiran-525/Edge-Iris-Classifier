# Edge Iris Classifier

A minimal **Edge Intelligence** demonstration running a machine learning classifier entirely **on-device** using integer-only computation.
Designed for microcontrollers where **latency, power, and memory are constrained**.

---

## Edge Intelligence

This project performs **ML inference at the edge**, meaning predictions run locally on embedded hardware without cloud access.

**Benefits**

* Real-time inference
* Low power consumption
* No data sent to cloud
* Works offline
* Minimal memory usage
* Autonomous operation

---

## Dataset

This model uses the classic **Iris Flower Dataset**.

* Samples: 150
* Classes: 3
* Features: 4
* Balanced dataset
* No missing values

### Classes

* Iris-setosa
* Iris-versicolor
* Iris-virginica

### Feature Order

```
[ sepal_length, sepal_width, petal_length, petal_width ]
```

---

## Edge Deployment Strategy

To enable efficient embedded inference:

* Floating-point weights converted to integers
* Scaling factor applied (×1000)
* Static memory only
* No dynamic allocation
* Loop-based inference
* Deterministic execution time

---

## Model

* Linear classifier
* 3 output classes
* 4 input features
* Argmax decision rule
* Integer-only math

Prediction:

```
score = bias + Σ(weight × feature)
```

Class with highest score is selected.

---

## Integer Optimization

* Weights scaled by 1000
* Bias scaled by 1000
* Features unscaled
* Integer multiplication only
* Long accumulation for safety

This removes floating-point dependency.

---

## Example Inputs

```
{51, 35, 14, 2}   → Iris-setosa
{60, 29, 45, 15}  → Iris-versicolor
{68, 30, 55, 21}  → Iris-virginica
```

(values represent ×10 of original dataset)

---

## Serial Output

```
Sample 1 predicted class: Iris-setosa
Sample 2 predicted class: Iris-versicolor
Sample 3 predicted class: Iris-virginica
```

---

## Features

* On-device ML inference
* Deterministic latency
* Tiny model size
* Integer-only computation
* Offline operation

---

## Suitable Platforms

* ESP32
* Arduino Uno
* STM32
* RP2040
* Any low-power MCU

---

## Use Cases

* Embedded AI demos
* Smart sensors
* Robotics classification
* TinyML education
* Edge IoT devices

---

