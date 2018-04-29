import tensorflow as tf
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'
hello = tf.constant("Hello, TensorFlow!")
sess = tf.Session()
print(sess.run(hello))
a = tf.constant(10)
b = tf.constant(30)
print(sess.run(a+b))
