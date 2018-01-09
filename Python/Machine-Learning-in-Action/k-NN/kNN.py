# encoding=utf-8

from numpy import *
import operator
import matplotlib
import matplotlib.pyplot as plt
from os import listdir

def createDataSet():
    group = array([[1.0, 1.1], [1.0, 1.0], [0, 0], [0, 0.1]])
    labels = ['A', 'A', 'B', 'B']
    return group, labels

# inx 要测试的点
def classify0(inX, dataSet, labels, k):
    # 距离计算
    dataSetSize = dataSet.shape[0]
    diffMat = tile(inX, (dataSetSize, 1)) - dataSet
    sqDiffMat = diffMat**2
    # 把二维数组的每列加起来
    sqDistances = sqDiffMat.sum(axis=1)
    distances = sqDistances**0.5
    # 返回distances从小到大的索引值
    sortedDistIndicies = distances.argsort()
    # 选择距离最小的k个点, 距离采用欧式距离
    classCount = {}
    for i in range(k):
        # 按照sortedDistIndicies中顺序取距离最小的点的labels
        voteIlabel = labels[sortedDistIndicies[i]]
        classCount[voteIlabel] = classCount.get(voteIlabel, 0) + 1
    # 排序
    sortedClassCount = sorted(classCount.iteritems(), 
        key=operator.itemgetter(1), reverse=True)
    return sortedClassCount[0][0]

def file2matrix(filename):
    def int(like):
        if like == 'largeDoses':
            like_int = 3
        elif like == 'smallDoses':
            like_int = 2
        else:
            like_int = 1
        return like_int
    fr = open(filename)
    arrayOLines = fr.readlines()
    numberOfLines = len(arrayOLines)
    # 以零填充二维数组
    returnMat = zeros((numberOfLines, 3))
    classLabelVector = []
    index = 0
    for line in arrayOLines:
        line = line.strip()
        listFromLine = line.split('\t')
        returnMat[index, :] = listFromLine[0:3]
        classLabelVector.append( int(listFromLine[-1]) )
        index += 1
    return returnMat, classLabelVector
    

def data_draw():
    datingDataMat, datingLables = file2matrix('datingTestSet.txt') 
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.scatter(datingDataMat[:, 0], datingDataMat[:, 1],
        15.0*array(datingLables), 15.0*array(datingLables))
    # ax.scatter(datingDataMat[:, 1], datingDataMat[:, 2],
    #     15.0*array(datingLables), 15.0*array(datingLables))
    plt.show()

def autoNorm(dataSet):
    minVals = dataSet.min(0)
    maxVals = dataSet.max(0)
    ranges = maxVals - minVals
    normDataSet = zeros(shape(dataSet))
    # 获取共有多少行
    m = dataSet.shape[0]
    # oldValue - min
    normDataSet = dataSet - tile(minVals, (m, 1))
    # (oldValue - min)/(max - min)
    normDataSet = normDataSet/tile(ranges, (m, 1))
    return normDataSet, ranges, minVals

def datingClassTest():
    # 测试数据集所占有的比例
    hoRatio = 0.1
    datingDataMat, datingLabels = file2matrix('datingTestSet.txt')
    normMat, ranges, minVals = autoNorm(datingDataMat)
    m = normMat.shape[0]
    numTestVecs = int(m*hoRatio)
    errorCount = 0.0
    for i in range(numTestVecs):
        classifierResult = classify0(normMat[i, :], normMat[numTestVecs:m, :],\
                        datingLabels[numTestVecs:m], 3)
        print 'the classifier came back with: %d, the real answer is: %d'\
                        % (classifierResult, datingLabels[i])
        if (classifierResult != datingLabels[i]): errorCount += 1.0
    print "the total error rate is: %f" % (errorCount/float(numTestVecs))

def classifyPerson():
    resultList = ['not all all', 'in small doses', 'in large doses']
    percentTats = float(raw_input(\
                    "percentage of time spent playing video game?"))
    ffMiles = float(raw_input("frequest flier miles earned per year?"))
    iceCream = float(raw_input("liters of ice cream consumed per year?"))
    datingDataMat, datingLabels = file2matrix('datingTestSet.txt')
    normMat, ranges, minVals = autoNorm(datingDataMat)
    inArr = array([ffMiles, percentTats, iceCream])
    classifierResult = classify0((inArr-\
                    minVals)/ranges, normMat, datingLabels, 3)
    print "you will probably like this person: ",\
            resultList[classifierResult - 1]

def img2vector(filename):
    returnVect = zeros((1, 1024))
    fr = open(filename)
    for i in range(32):
        lineStr = fr.readline()
        for j in range(32):
            returnVect[0, 32*i + j] = int(lineStr[j])
    return returnVect

def handwritingClassTest():
    hwLabels = []
    trainingFileList = listdir('trainingDigits')
    m = len(trainingFileList)
    trainingMat = zeros((m, 1024))
    for i in range(m):
        fileNameStr = trainingFileList[i]
        fileStr = fileNameStr.split('.')[0]
        classNumStr = int(fileStr.split('_')[0])
        hwLabels.append(classNumStr)
        trainingMat[i, :] = img2vector('trainingDigits/%s' % fileNameStr)
    testFileList = listdir('testDigits')
    errorCount = 0.0
    mTest = len(testFileList)
    for i in range(mTest):
        fileNameStr = testFileList[i]
        fileStr = fileNameStr.split('.')[0]
        classNumStr = int(fileStr.split('_')[0])
        vectorUnderTest = img2vector('testDigits/%s' % fileNameStr)
        classifierResult = classify0(vectorUnderTest, \
                                trainingMat, hwLabels, 3)
        print "the classifier came back with: %d, the real answer is: %d"\
                                % (classifierResult, classNumStr)
        if (classifierResult != classNumStr): errorCount += 1.0
    print "\nthe total number of errors is %d" % errorCount
    print "\nthe total error rate is: %f" % (errorCount/float(mTest))


if __name__ == '__main__':
    # group, labels = createDataSet()
    # print classify0([0, 0], group, labels, 3)
    # datingDataMat, labels = file2matrix('datingTestSet.txt')
    # print autoNorm(datingDataMat)
    # data_draw()
    # datingClassTest()
    # classifyPerson()
    # print img2vector('testDigits/0_32.txt')
    handwritingClassTest()



