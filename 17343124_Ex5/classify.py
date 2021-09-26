import csv
import struct
import os
import numpy as np
from PIL import Image
from sklearn.metrics import accuracy_score
from sklearn.neural_network import MLPClassifier
from sklearn.externals import joblib
import pandas as pd

def load_mnist(path, kind='train'):
	# 加载mnist数据集
	labels_path = os.path.join(path, '%s-labels.idx1-ubyte' % kind)
	images_path = os.path.join(path, '%s-images.idx3-ubyte' % kind)
	with open(labels_path, 'rb') as lbpath:
		magic, n = struct.unpack('>II',
                                 lbpath.read(8))
		labels = np.fromfile(lbpath, dtype=np.uint8)

	with open(images_path, 'rb') as imgpath:
		magic, num, rows, cols = struct.unpack('>IIII',
                                               imgpath.read(16))
		images = np.fromfile(imgpath, dtype=np.uint8).reshape(len(labels), 784)

	return images, labels

def train_model(mlp, save_dir):
	# 加载训练数据集
	[train_images, train_labels] = load_mnist('./mlp/data/')
	train_labels = train_labels.astype('int32')
	train_images = train_images.astype('int32')
	# 开始训练
	mlp.fit(train_images, train_labels)
	# 保存模型
	joblib.dump(mlp, save_dir)
	mlp = joblib.load(save_dir)
	# 加载测试数据集
	[test_images, test_labels] = load_mnist('./mlp/data/', kind = 't10k')
	test_labels = test_labels.astype('int32')
	test_images = test_images.astype('int32')
	# 预测测试数据集
	y_pred = list(mlp.predict(test_images))
	print(accuracy_score(test_labels, y_pred)) # 测试集的得分

mlp = MLPClassifier(hidden_layer_sizes=(400, 200), activation='logistic', 
				solver='sgd', learning_rate_init=0.001, max_iter=400, verbose = True)

save_dir = './mlp/model/classify.m'
if(os.path.isfile(save_dir)):
	# 加载模型
	mlp = joblib.load(save_dir)
else:
	train_model(mlp, save_dir)

print('Reading images directory from txt file...')
imageDir = []
f = open('./imageDir.txt')
imagedir = f.readline()
while imagedir:
	imagedir = imagedir.strip('\n')
	imageDir.append(imagedir)
	imagedir = f.readline()
f.close()

init_op = tf.initialize_all_variables()

saver = tf.train.Saver()
with tf.Session() as sess:
sess.run(init_op)
saver.restore(sess, "./model/model.ckpt")#这里使用了之前保存的模型参数
prediction=tf.argmax(y_conv,1)
predint=prediction.eval(feed_dict={x: [result],keep_prob: 1.0}, session=sess)
print('the digit is 9: ')
print('recognize result:')
print(predint[0])