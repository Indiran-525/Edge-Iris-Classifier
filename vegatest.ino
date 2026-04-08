// Scale factor (to avoid floats)
#define SCALE 1000

// Weights (scaled by 1000)
int weights[3][4] = {
  {-425,  963, -2520, -1081},   // Iris-setosa
  { 534, -317,  -205,  -942},   // Iris-versicolor
  {-110, -646,  2725,  2022}    // Iris-virginica
};

// Biases (scaled by 1000)
int bias[3] = {
  9881,   // 9.88102748 * 1000
  2217,   // 2.21697376 * 1000
 -12098   // -12.09800124 * 1000
};

// Class labels
const char* classes[3] = {
  "Iris-setosa",
  "Iris-versicolor",
  "Iris-virginica"
};

// Prediction function
int predict(int features[4]) {
  long scores[3];

  for (int i = 0; i < 3; i++) {
    scores[i] = bias[i];
    for (int j = 0; j < 4; j++) {
      scores[i] += weights[i][j] * features[j];
    }
  }

  // Find max
  int max_idx = 0;
  for (int i = 1; i < 3; i++) {
    if (scores[i] > scores[max_idx]) {
      max_idx = i;
    }
  }
  return max_idx;
}

void setup() {
  Serial.begin(115200);
  while (!Serial);
  delay(3000);
  Serial.println("Starting Iris Prediction...");

  // Example inputs (scaled by 1000 is NOT needed since features are raw)
  int sample1[4] = {51, 35, 14, 2};   // {5.1, 3.5, 1.4, 0.2}
  int sample2[4] = {60, 29, 45, 15};  // {6.0, 2.9, 4.5, 1.5}
  int sample3[4] = {68, 30, 55, 21};  // {6.8, 3.0, 5.5, 2.1}

  int pred1 = predict(sample1);
  Serial.print("Sample 1 predicted class: ");
  Serial.println(classes[pred1]);

  int pred2 = predict(sample2);
  Serial.print("Sample 2 predicted class: ");
  Serial.println(classes[pred2]);

  int pred3 = predict(sample3);
  Serial.print("Sample 3 predicted class: ");
  Serial.println(classes[pred3]);
}

void loop() {
  // Nothing
}