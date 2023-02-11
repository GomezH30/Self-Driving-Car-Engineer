# Writeup: 3D Object dtection

In this project, a deep-learning approach is used to detect vehicles in LiDAR data based on a birds-eye view perspective of the 3D point-cloud. Also, a series of performance measures is used to evaluate the performance of the detection approach.

## Section 1 : Compute Lidar Point-Cloud from Range Image

### Visualize range image channels

In the Waymo Open dataset, lidar data is stored as a range image. Therefore, this task is about extracting two of the data channels within the range image, which are "range" and "intensity", and convert the floating-point data to an 8-bit integer value range.

Results of range image.

![](img/Img_S1_EX1.PNG)

### Visualize lidar point-cloud

The goal of this task is to use the Open3D library to display the lidar point-cloud in a 3d viewer in order to develop a feel for the nature of lidar point-clouds.

![](img/Img_S1_EX2_1.PNG)
![](img/Img_S1_EX2_2.PNG)
![](img/Img_S1_EX2_3.PNG)
![](img/Img_S1_EX2_4.PNG)
![](img/Img_S1_EX2_5.PNG)
![](img/Img_S1_EX2_6.PNG)
![](img/Img_S1_EX2_7.PNG)
![](img/Img_S1_EX2_8.PNG)
![](img/Img_S1_EX2_9.PNG)
![](img/Img_S1_EX2_10.PNG)

## Section 2 : Create Birds-Eye View from Lidar PCL

### Convert sensor coordinates to BEV-map coordinates

The goal of this task is to perform the first step in creating a birds-eye view (BEV) perspective of the lidar point-cloud

Result Image

![](img/Img_S2_EX1.PNG)


### Compute intensity layer of the BEV map

The goal of this task is to fill the "intensity" channel of the BEV map with data from the point-cloud. In order to do so, you will need to identify all points with the same (x,y)-coordinates within the BEV map and then assign the intensity value of the top-most lidar point to the respective BEV pixel


Result Image

![](img/Img_S2_EX2.PNG)


### Compute height layer of the BEV map

The goal of this task is to fill the "height" channel of the BEV map with data from the point-cloud.

Result Image

![](img/Img_S2_EX3.PNG)

## Section 3 : Model-based Object Detection in BEV Image

### Add a second model from a GitHub repo

The goal of this task is to illustrate how a new model can be integrated into an existing framework. 

### Extract 3D bounding boxes from model response

As the model input is a three-channel BEV map, the detected objects will be returned with coordinates and properties in the BEV coordinate space. Thus, before the detections can move along in the processing pipeline, they need to be converted into metric coordinates in vehicle space. This task is about performing this conversion such that all detections have the format [1, x, y, z, h, w, l, yaw], where 1 denotes the class id for the object type vehicle

Result Image

![](img/Img_S3_EX2.PNG)

## Section 4 : Performance Evaluation for Object Detection

### Compute intersection-over-union between labels and detections

The goal of this task is to find pairings between ground-truth labels and detections, so that we can determine wether an object has been (a) missed (false negative), (b) successfully detected (true positive) or (c) has been falsely reported (false positive).

### Compute false-negatives and false-positives

Based on the pairings between ground-truth labels and detected objects, the goal of this task is to determine the number of false positives and false negatives for the current frame.

### Compute precision and recall

After processing all the frames of a sequence, the performance of the object detection algorithm shall now be evaluated.

Result Image 

![](img/Img_S4_EX3_1.PNG)






