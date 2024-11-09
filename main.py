import tensorflow as tf
import tensorflow_hub as hub
import numpy as np
from tensorflow.keras.preprocessing.sequence import pad_sequences
from sklearn.preprocessing import LabelEncoder
from tensorflow.keras.models import load_model


print ('AI Simulation + Agent')
print('Predicted Emotion')

# تحميل نموذج معالج النصوص (BERT مثلاً)
module_url = "https://tfhub.dev/google/bert_uncased_L-12_H-768_A-12/1"
bert_layer = hub.KerasLayer(module_url, trainable=False)

# بيانات تدريب وهمية للتوضيح (بيانات مشاعر بسيطة)
texts = ["I am happy", "I feel sad", "This is great", "I am angry"]
labels = ["positive", "negative", "positive", "negative"]

# تحويل النصوص إلى أرقام باستخدام Tokenizer
tokenizer = tf.keras.preprocessing.text.Tokenizer()
tokenizer.fit_on_texts(texts)
sequences = tokenizer.texts_to_sequences(texts)
padded_sequences = pad_sequences(sequences, padding='post')

# ترميز الأهداف (المشاعر)
label_encoder = LabelEncoder()
encoded_labels = label_encoder.fit_transform(labels)

# بناء نموذج بسيط باستخدام BERT كطبقة
model = tf.keras.Sequential([
    bert_layer,
    tf.keras.layers.Dense(128, activation='relu'),
    tf.keras.layers.Dense(1, activation='sigmoid')
])

model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# تدريب النموذج (مع بيانات وهمية هنا)
model.fit(padded_sequences, np.array(encoded_labels), epochs=5)

# اختبار النموذج
test_text = ["I am feeling excited"]
test_sequence = tokenizer.texts_to_sequences(test_text)
test_padded = pad_sequences(test_sequence, padding='post', maxlen=10)

# التنبؤ بالمشاعر
pred = model.predict(test_padded)
pred_label = label_encoder.inverse_transform([int(pred[0][0] > 0.5)])[0]

print(f"Predicted Emotion: {pred_label}")
