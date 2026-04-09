# 🌿 THE PHYTO-SENTRY: A Fused 1D/2D-CNN Framework for Multi-Modal Plant Stress Detection

![Plant Health](https://img.shields.io/badge/Plant_Health-Predictive_Diagnostics-brightgreen)
![Hardware](https://img.shields.io/badge/Hardware-Arduino_%7C_ESP32-blue)
![Machine Learning](https://img.shields.io/badge/ML-1D_CNN_%7C_2D_CNN-orange)

## 📌 Project Overview
Current agricultural diagnostics are reactive, relying on visual inspection that identifies threats only after significant crop damage has occurred. **THE PHYTO-SENTRY** is a non-invasive, multi-modal deep learning platform designed for the predictive diagnosis of plant health. 

The system utilizes an "asymmetrical framework" that simultaneously analyzes two distinct biological signals:
1. **The "Slow" Bio-chemical Scent:** Volatile Organic Compounds (VOCs) indicating diseases like fungal infections.
2. **The "Instant" Bio-electrical Scream:** Variation Potential (VP) spikes triggered by physical attacks like herbivory.

By fusing these signals, the model generates a unified **"Plant Health Index,"** providing a robust, low-cost tool for real-world precision agriculture.

---

## ⚙️ System Architecture

### 1. Bio-Electrical Threat Detection (1D-CNN)
Designed for the instant detection of physical threats (e.g., pests). 
* **Mechanism:** Detects the massive influx of calcium (Ca2+) ions that occurs when an insect tears the cell membrane. This creates a sharp electrical surge known as a Variation Potential (VP).
* **Hardware:** An AD8232 bio-amplifier attached via surface electrodes isolates the 0.5-40 Hz bio-potential frequency band.
* **Data Processing:** Sampled at 1000 Hz to create a high-resolution 1-second "slice" (1x1000 vector).
* **Machine Learning:** A 1D-CNN analyzes the shape of the waveform to distinguish between a true attack and environmental noise.

### 2. Electronic Nose VOC Detection (2D-CNN)
Targets slow-building stress like fungal infections by monitoring the Jasmonic Acid (JA) defense pathway.
* **Mechanism:** When infested, plants release a complex cocktail of VOCs (like ethylene and terpenes) as a distress signal.
* **Hardware:** An E-Nose array comprising MQ-135, MQ-3, MQ-2, and a BME280 sensor.
* **Data Processing:** Time-series data is converted into a 2D data-image or heatmap. Each row represents a sensor's readings over time.
* **Machine Learning:** A 2D-CNN extracts features from the heatmap to identify the specific signature of the disease.

### 3. The "Master Brain" Fusion Model
The probability outputs from both the 1D-CNN and 2D-CNN are fed into a final fused neural network. This evaluates the correlation between signals to differentiate between:
* True Pest Attack
* Fungal Infection
* Mechanical Wound
* False Alarm

---

## 🛠️ Hardware Requirements
* **Microcontrollers:** Arduino Uno and ESP32.
* **Bio-Amplifier:** AD8232 with surface electrodes (Ag/AgCl).
* **Gas & Environmental Sensors:** MQ-135, MQ-3, MQ-2, and BME280.
* **Enclosure:** Sealed, foil-covered acrylic enclosure acting as a Faraday Cage.

---

## 📊 Results & Accuracy
The trained machine learning models demonstrated high efficacy:
* **VOC Model (2D-CNN):** Accuracy ranging between 88% to 91%.
* **Bio-Electrical Model (1D-CNN):** Reached an accuracy of up to 97.36%.

---

## 🚀 Future Recommendations
To integrate this system into a whole field or greenhouse, the project will be mounted on a railway system. A mechanical arm fitted with electrodes will attach to leaves, guided by a webcam and an infrared camera for targeted analysis.
